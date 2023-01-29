#include "getAssets.h"
#include <iostream>

#include "nlohmann/json.hpp"

#include "HTTPRequest.hpp"

using json = nlohmann::json;

std::string httpGet(std::string url) {
    try {
    // Replace https with http
    if (url.substr(0,5) == "https") {
        url = "http"+url.substr(5,end(url)-begin(url));
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

int main()
{
    std::cout << getVersionMeta("1.19.3").value("assetIndex", json::parse("{}")) << std::endl;
    return 0;
}