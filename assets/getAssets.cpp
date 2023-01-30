#include "getAssets.h"
#include <iostream>
#include <fstream>

#include "utils.hpp"

#include "nlohmann/json.hpp"
#include "elnormous/HTTPRequest.hpp"
#include <curl/curl.h>
#include <zip.h> // Install using 'sudo apt install libzip-dev'

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

json getVersionMeta(std::string version) {
    // load the request body in a json object
    json version_master_list = json::parse(httpGet("https://piston-meta.mojang.com/mc/game/version_manifest_v2.json"));
    // Print the version id
    json version_list = version_master_list.value("versions", json::parse("{}"));

    int version_id = -1;

    // Loop through all minecraft versions
    if (version != "latest") {
        for (int i = 0; i <= end(version_list) - begin(version_list) - 1; i++ ) {
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
    // get the version data
    json versionData = getVersionMeta(version);
    if (versionData.value("error", "none") != "none") { return; }
    // Get the url of the client.jar
    json downloads = versionData.value("downloads",json::parse("{\"error\": \"No Key called downloads\"}"));
    json clientData = downloads.value("client", json::parse("{\"error\": \"No Key called client\"}"));
    std::string clientURLString = clientData.value("url","none").c_str();
    const char* clientURL = clientURLString.c_str();
    
    // Download the client.jar
    print(clientURL);
    downloadFile(clientURL, "client.jar");

    struct zip_stat sb;

    // unzip the minecraft folder in /client.jar/assets/
    zip *z = zip_open("client.jar", 0, 0);
    std::cout << zip_get_num_entries(z, 0) << "\n";
    for (int i = 0; i < zip_get_num_entries(z, 0); i++) {
        if (zip_stat_index(z, i, 0, &sb) == 0) {
            //print(sb.name);
        }
    }
}

int main()
{
    getAssets("1.19.3");
    return 0;
}