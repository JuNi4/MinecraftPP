## Minecraft++ Options file library
By: @JuNi4

A library for everyting related to the options.txt

-- Requirements --
  - nlohmann/json (https://github.com/nlohmann/json)

 (Included in Mc++)
  - utils.hpp
  - os.hpp

Demo script:
```cpp
#include <nlohmann/json.hpp>
#include <iostream>

#include <options/options.hpp>

int main() {
    // -- Demo Options file implementaion --
    // delete the option files (only if they exist)
    options::deleteOptionsFile();
    options::deleteOptionsFile(options::defaultKeyBindsPath());

    // Check if optionsfile exists
    if ( ! std::filesystem::is_regular_file( options::defaultOptionsPath() )) {
        // If the mc options file exists: import it
        if (std::filesystem::is_regular_file(options::getMcPath()+"options.txt")) {
            options::importConfig();
        } else { // otherwise, create new files
            // Crate Options file
            options::createOptionsFile();
            // Create key binds file
            options::createOptionsFile(false, options::defaultKeyBindsPath(), options::defaultKeyBindStruct);
        }
    } else if ( ! std::filesystem::is_regular_file( options::defaultKeyBindsPath() ) ) {
        // Create key binds file
        options::createOptionsFile(false, options::defaultKeyBindsPath(), options::defaultKeyBindStruct);
    }
    // load the two files
    json opt = options::getOptions();
    json keys = options::getOptions(options::defaultKeyBindsPath());

    // get the title of the window
    std::cout << opt["title"] << std::endl;

    // set the title directly
    options::setOption("title", "Minecraft--");

    // set the title inside of the json object
    opt["title"] = "Minecraft**";

    // save the opt json object
    options::saveOptions(opt);

    // -- End of demo --
    return 0;
}
```
