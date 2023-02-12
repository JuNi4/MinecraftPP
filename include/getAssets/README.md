## Minecraft++ assets library
By: @JuNi4

A simple library for downloading assets from Mojang

-- Requirements --
  - libzip   (`sudo apt install libzip-dev` or https://libzip.org/download/)
  - curl     (`sudo apt install libcurl-dev` or https://curl.se/download.html)
  - nlohmann/json (https://github.com/nlohmann/json)
  - elnormous/HTTPRequest (https://github.com/elnormous/HTTPRequest)

-- Quick help --\
(Because there are only three simple functions)

`getAssets( std::string version, std::string base_path = "" )`\
Downloads the assets, contained in the version jar file, from Mojang\
`version` Being the Minecraft version to get the assets from\
`base_path` Is the place, where the assets will be downloaded to.

`getResources( std::string version, std::string base_path = "" )`\
Downloads the Resources, the Minecraft launcher downloads. This may take up to 10 minutes or more, depending on your connection speed.\
`version` Being the Minecraft version to get the assets from\
`base_path` Is the place, where the assets will be downloaded to.

`json getVersionMeta( std::string version )`\
Gets the information for a version. The Json object contains things like where to get the client.jar from.\
`version` Being the Minecraft version to get the assets from

Quick Demo:
```cpp
#include <getAssets/getAssets.hpp>

int main() {
    // Download the assets contained in the version jar file
    getAssets("1.19.3", "assets/");
    // Get the resources, downloaded by the launcher. This may take up to 10 minutes or more
    getResources("1.19.3", "assets/");

    return 0;
}
```