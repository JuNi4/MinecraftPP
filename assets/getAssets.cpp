#include "getAssets.h"
#include <iostream>
#include <fstream>

#include "utils.hpp"

#include "nlohmann/json.hpp"
#include "elnormous/HTTPRequest.hpp"
#include <curl/curl.h>
#include <zip.h> // Install using 'sudo apt install libzip-dev'
#include <filesystem>

using json = nlohmann::json;

std::string httpGet(std::string url) {
    try {
    // Replace https with http
    if (url.substr(0,5) == "https") {
        url = "http"+url.substr(5,len(url));
    }
    // the request url
    http::Request request{url};
    // send a get request
    const auto response = request.send("GET");
    // Return response as string
    return std::string{response.body.begin(), response.body.end()};

    } catch (const std::exception& e ) {
        std::cerr << "Request failed, error: " << e.what() << '\n';
        return "Someting wen wrong";
    }
}

int downloadFile(const char* url, const char* filename) {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(filename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    return 0;
}

// for string delimiter
std::vector<std::string> split (std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}


json getVersionMeta(std::string version) {
    // load the request body in a json object
    json version_master_list = json::parse(httpGet("https://piston-meta.mojang.com/mc/game/version_manifest_v2.json"));
    // Print the version id
    json version_list = version_master_list.value("versions", json::parse("{}"));

    int version_id = -1;

    // Loop through all minecraft versions
    if (version != "latest") {
        for (int i = 0; i < end(version_list) - begin(version_list); i++ ) {
            // Get the id of the id of the index
            std::string id = version_list[i].value("id", "none");
            // if the id is not the specified version, continue
            if (id != version) { continue; }
            // set the version id
            version_id = i;
            // break out of the loop
            break;
        }
    } else {
        version_id = 0;
    }

    if (version_id == -1) {
        // if the version wasn't found, return error message
        return json::parse("{'error': '404: version not found'}");
    }

    // get the json file url of the version
    std::string url = version_list[version_id].value("url", "none");
    // get the json file
    json version_data = json::parse(httpGet(url));
    // return the version data
    return version_data;
}

void getAssets(std::string version) {
    print("Getting Assets...");
    // if minecraft folder exists
    if ( std::filesystem::is_directory("minecraft") ) {
        // remove minecraft folder
        std::filesystem::remove_all("minecraft");
    }

    // get the version data
    json versionData = getVersionMeta(version);
    if (versionData.value("error", "none") != "none") { return; }
    // Get the url of the client.jar
    json downloads = versionData.value("downloads",json::parse("{\"error\": \"No Key called downloads\"}"));
    json clientData = downloads.value("client", json::parse("{\"error\": \"No Key called client\"}"));
    std::string clientURLString = clientData.value("url","none").c_str();
    const char* clientURL = clientURLString.c_str();
    
    // Download the client.jar
    print("Downloading client.jar...");
    downloadFile(clientURL, "client.jar");

    // unzip the minecraft folder in /client.jar/assets/
    zip *z = zip_open("client.jar", 0, 0);
    //std::cout << zip_get_num_entries(z, 0) << "\n";

    const char* pathInZip = "assets/minecraft";
    struct zip_stat sb;
    
    std::string folder = "";

    print("Extracting assets...");
    for (int i = 0; i < zip_get_num_entries(z, 0); i++) {
        if (zip_stat_index(z, i, 0, &sb) == 0) {
            // Do something with the zipfile
            if ( std::string{sb.name}.substr(0,strlen(pathInZip)) != pathInZip ) { continue; } // if the file does not start with assets/minecraft, continue

            // create folder for file
            folder = std::string{sb.name}.substr(7,strlen(sb.name));

            std::vector<std::string> v = split (folder, "/");

            folder = folder.substr(0,len(folder)-len(v[len(v)-1]));

            if ( !std::filesystem::is_directory(folder) ) {
                std::filesystem::create_directories(folder);
            }

            //Alloc memory for its uncompressed contents
            char *contents = new char[sb.size];

            //Read the compressed file
            zip_file *f = zip_fopen(z, sb.name, 0);
            zip_fread(f, contents, sb.size);
            zip_fclose(f);

            if(!std::ofstream((folder + v[len(v)-1]).c_str()).write(contents, sb.size))
            {
                std::cerr << "Error writing file " << EXIT_FAILURE << '\n';
            }
        }
    }

    // Delete client.jar
    std::filesystem::remove("client.jar");
    print("Done getting assets!");
}

void getResources(std::string version) {
    print("Getting resources...");
    std::string BASE_URL = "https://resources.download.minecraft.net/";
    // if minecraft folder exists
    if ( std::filesystem::is_directory("resources") ) {
        // remove minecraft folder
        std::filesystem::remove_all("resources");
    }

    // get the version data
    json versionData = getVersionMeta(version);
    if (versionData.value("error", "none") != "none") { return; }

    json assetIndexData = versionData.value("assetIndex", json::parse("{\"error\": \"no assetIndex\"}"));
    std::string assetIndexUrl = assetIndexData.value("url", "none");

    // don't conitnue if url didn't work
    if (assetIndexUrl == "none") { return; }

    // get the asset index
    json assetIndex = json::parse(httpGet(assetIndexUrl));

    json objects = assetIndex["objects"];

    if ( objects == nullptr ) { return; }
    
    // go through all assets and download them
    for (json::iterator it = objects.begin(); it != objects.end(); ++it) {
        print("Downloading "+it.key());
        //std::cout << it.key() << " : " << it.value() << "\n";

        // create folder for file
        std::string folder = "resources/"+it.key();
        std::string path = "resources/"+it.key();

        std::vector<std::string> v = split (folder, "/");

        folder = folder.substr(0,len(folder)-len(v[len(v)-1]));

        if ( !std::filesystem::is_directory(folder) ) {
            std::filesystem::create_directories(folder);
        }

        // assamble url
        std::string hash = objects[it.key()]["hash"];
        std::string block = hash.substr(0,2);

        std::string url = BASE_URL + block +"/"+ hash;

        // Download file
        downloadFile(url.c_str(),path.c_str());
    }
    print("Done getting assets!");
}

int main()
{
    getAssets("1.19.3");
    getResources("1.19.3");
    return 0;
}