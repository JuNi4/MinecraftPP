/**
 * @file options.hpp
 * @brief Everything for the optionsfile
 * @author @JuNi4
 * @date 2023-02-08
 * @copyright Copyright (c) 2023
*/

#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <limits>
#include <utils.hpp>
#include <os.hpp>
#include <string>

#include "keyCodes.hpp"

using json = nlohmann::json;

#ifndef _OPTIONS_H_
#define _OPTIONS_H_
#pragma once

namespace options {

// Place holder vars
/**
 * @brief the FPS cap of the game
*/
int FPS;
/**
 * @brief the Render Distance of the game. Not yet in chunks
*/
int renderDistance = 10;
/**
 * @brief The FOV of the camera
*/
int FOV = 45;
/**
 * @brief wether or not the fps should be printed to the console
*/
bool displayFPS = false;
/**
 * @brief the title of the window
*/
const char* windowTitle = "NAN";

/**
 * @brief A json object for creating a config file
 */
nlohmann::json defaultOptionsStruct = json::parse(R"(
    {
        "advancedItemTooltips": {"val": "false", "comments": "## Typical minecraft options"},
        "allowServerListing":{"val": "true"},
        "ao":{"val": "2"},
        "attackIndicator":{"val": "1"},
        "autoJump":{"val": "false"},
        "autoSuggestions":{"val": "true"},
        "backgroundForChatOnly":{"val": "true"},
        "biomeBlendRadius":{"val": "2"},
        "bobView":{"val": "true"},
        "chatColors":{"val": "true"},
        "chatDelay":{"val": "0.0"},
        "chatHeightFocused":{"val": "1.0"},
        "chatHeightUnfocused":{"val": "0.5"},
        "chatLineSpacing":{"val": "0.0"},
        "chatLinks":{"val": "true"},
        "chatLinksPrompt":{"val": "true"},
        "chatOpacity":{"val": "1.0"},
        "chatScale":{"val": "1.0"},
        "chatVisibility":{"val": "0"},
        "chatWidth":{"val": "1.0"},
        "darkMojangStudiosBackground":{"val": "true"},
        "darknessEffectScale":{"val": "1.0"},
        "directionalAudio":{"val": "false"},
        "discrete_mouse_scroll":{"val": "false"},
        "enableVsync":{"val": "false"},
        "entityDistanceScaling":{"val": "1.0"},
        "entityShadows":{"val": "true"},
        "forceUnicodeFont":{"val": "false"},
        "fov":{"val": "0.0", "comments": "# The field of view\n# Default: 0.0"},
        "fovEffectScale":{"val": "1.0"},
        "maxFps":{"val": "60", "comments": "# The FPS cap\n# Default: 60"},
        "fullscreen":{"val": "false"},
        "gamma":{"val": "1.0"},
        "glDebugVerbosity":{"val": "1"},
        "graphicsMode":{"val": "1"},
        "guiScale":{"val": "3"},
        "heldItemTooltips":{"val": "true"},
        "hideBundleTutorial":{"val": "true"},
        "hideLightningFlashes":{"val": "false"},
        "hideMatchedNames":{"val": "true"},
        "hideServerAddress":{"val": "false"},
        "incompatibleResourcePacks":{"val": "[]"},
        "invertYMouse":{"val": "false"},
        "renderDistance":{"val": "16", "comments": "# The render distance in chunks\n# Default: 16"},
        "icon":{"val": "assets/resources/icons/minecraft.icns", "comments": "# The icon path for the application logo\n# Default: assets/resources/icons/minecraft.icns"},
        "title":{"val": "Minecraft++", "comments": "# The title of the game\n# Default: Minecraft++"},
        "brand":{"val": "Minecraft++", "comments": "# Brand of the minecraft client (only used in F3 menu)\n# Default: Minecraft++"},
        "sendBrand":{"val": "true", "comments": "# Wether or not the Minecraft++ brand should be send to the server\n# If not, the client will tell a server, that it is a vanilla client\n# It will disable client specific features, that are requested by a server like custom ui's\n# Default: true"}
    }
)");

nlohmann::json defaultKeyBindStruct = json::parse(R"(
    {
        "key_key.advancements":{"val": "l"},
        "key_key.attack":{"val": "lmb"},
        "key_key.back":{"val": "s"},
        "key_key.chat":{"val": "t"},
        "key_key.command":{"val": "slash"},
        "key_key.drop":{"val": "q"},
        "key_key.forward":{"val": "w"},
        "key_key.fullscree:":{"val": "f11"},
        "key_key.hotbar.1":{"val": "1"},
        "key_key.hotbar.2":{"val": "2"},
        "key_key.hotbar.3":{"val": "3"},
        "key_key.hotbar.4":{"val": "4"},
        "key_key.hotbar.5":{"val": "5"},
        "key_key.hotbar.6":{"val": "6"},
        "key_key.hotbar.7":{"val": "7"},
        "key_key.hotbar.8":{"val": "8"},
        "key_key.hotbar.9":{"val": "9"},
        "key_key.inventory":{"val": "e"},
        "key_key.jump":{"val": "space"},
        "key_key.left":{"val": "a"},
        "key_key.loadToolbarActivator":{"val": "x"},
        "key_key.pickItem":{"val": "mmb"},
        "key_key.playerlist":{"val": "tab"},
        "key_key.right":{"val": "d"},
        "key_key.saveToolbarActivator":{"val": "c"},
        "key_key.screenshot":{"val": "f2"},
        "key_key.smoothCamera":{"val": "none"},
        "key_key.sneak":{"val": "lshift"},
        "key_key.socialInteractions":{"val": "p"},
        "key_key.spectatorOutlines":{"val": "none"},
        "key_key.sprint":{"val": "lctrl"},
        "key_key.swapOffhand":{"val": "f"},
        "key_key.togglePerspective":{"val": "f5"},
        "key_key.use":{"val": "rmb"},
        "key_key.zoom":{"val": "v"}
    }
)");

/**
 * @brief  The name of the options file
 */
std::string optionsFileName = "options.txt";
/**
 * @brief The name of the key binds file
 */
std::string keyBindsFileName = "keyBinds.txt";

/**
 * @brief Get the path to the options file
 * 
 * @return std::string Path to options file
 */
std::string defaultOptionsPath() {
    std::string delimeter = os::getOsDelimiter();
    return "data"+delimeter+optionsFileName;
}

/**
 * @brief Get the Minecraft Path
 * 
 * @return std::string The path of minecraft
 */
std::string getMcPath() {
    // set minecraft path based on operating system
    std::string os = os::getOsName();
    // linux path
    if (os == "Linux") { return "/home/"+os::getUserName()+"/.minecraft/"; }
    // Windows path
    else if (os.substr(0,7) == "Windows") { return "C:\\Users\\"+os::getUserName()+"\\AppData\\Roaming\\.minecraft\\"; }
    else { return ""; }
}

/**
 * @brief Get the path to the key binds file
 * 
 * @return std::string Path to key binds file
 */
std::string defaultKeyBindsPath() {
    std::string delimeter = os::getOsDelimiter();
    return "data"+delimeter+keyBindsFileName;
}

/**
 * @brief Set the value type of the values in a json object
 * 
 * @param jobj The Json object to set the value types
 * @return nlohmann::json The json object with correct* value types. *Arrays and objects are currently not supported
 */
nlohmann::json setOptionValuetypes(nlohmann::json jobj) {
    // loop through all
    for (nlohmann::json::iterator opt = jobj.begin(); opt != jobj.end(); ++opt) {
        // set the value type accordingly
        // - numbers
        std::string number_string = opt.value();
        std::string::size_type sz;
        double parsed_number = 0.0;
        int parsed_int = 0;

        try {
            if (number_string.find(".") < sizeof(number_string)) { // check if the number is float
                parsed_number = std::stod(number_string, &sz);
                jobj[opt.key()] = parsed_number;
            } else { // else try to convert to int
                parsed_int = std::stoi(number_string, &sz);
                jobj[opt.key()] = parsed_int;
            }
        }
        catch(std::exception& ia) {
            parsed_number = 0.0;
        }

        // - bools
        if (opt.value() == "true") { // check if bool = true
            jobj[opt.key()] = true;
        } else if (opt.value() == "false") { // check if bool = false
            jobj[opt.key()] = false;
        }
    }
    // Return options object
    return jobj;
}

/**
 * @brief Get the Options json object
 * 
 * @param path The path to the options.txt
 * @return nlohmann::json The json object containing all the options (with mostly correct types). In case of am error, the object will contain a key called "error" containing some detail of the error
 */
nlohmann::json getOptions(std::string path = defaultOptionsPath()) {
    // check if options file exists
    if (!std::filesystem::is_regular_file(path)) { return json::parse(R"({"error": "404: options file not found!"})"); }
    nlohmann::json j;
    // Config Tests
    std::ifstream cFile (path);
    if (cFile.is_open())
    {
        std::string line;
        while(getline(cFile, line)){
            line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
            if(line[0] == '#' || line.empty())
            continue;
            auto delimiterPos = line.find(":");
            auto name = line.substr(0, delimiterPos);
            auto value = line.substr(delimiterPos + 1);
            //std::cout << " " << name << ": " << value << '\n';
            // Set Options
            j[name] = value;
        }
        return setOptionValuetypes(j);
    }
    else {
        std::cerr << "Couldn't open config file for reading.\n";
        return nlohmann::json::parse("{\"error:\": \"Could not open file\"}");
    }
}
/**
 * @brief Get the Options json object
 * The same as getOptions(); but the data types are all strings
 * 
 * @param path The path to the options.txt
 * @return nlohmann::json The json object containing all the options. In case of am error, the object will contain a key called "error" containing some detail of the error
 */
nlohmann::json getRawOptions(std::string path = defaultOptionsPath()) {
    // check if options file exists
    if (!std::filesystem::is_regular_file(path)) { return json::parse(R"({"error": "options file not found!"})"); }
    nlohmann::json j;
    // Config Tests
    std::ifstream cFile (path);
    if (cFile.is_open())
    {
        std::string line;
        while(getline(cFile, line)){
            line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
            if(line[0] == '#' || line.empty())
            continue;
            auto delimiterPos = line.find(":");
            auto name = line.substr(0, delimiterPos);
            auto value = line.substr(delimiterPos + 1);
            //std::cout << " " << name << ": " << value << '\n';
            // Set Options
            j[name] = value;
        }
        return j;
    }
    else {
        std::cerr << "Couldn't open config file for reading.\n";
        return nlohmann::json::parse("{\"error:\": \"Could not open file\"}");
    }
}

/**
 * @brief Set an option by a key in the options file
 * 
 * @param key The key to be modified
 * @param value The value to set the key to
 * @param path The path to the options file
 * @return true The operation was succsessfull,
 * @return false The operation failed succsessfully
 */
bool setOption(std::string key, auto value, std::string path = defaultOptionsPath()) {
    //std::cout << key << " " << value << " " << path << "\n";
    // check if options file exists
    if (!std::filesystem::is_regular_file(path)) { return false; }
    // Load config file
    std::fstream fp (path);

    // if the key was found in the options file
    bool found = false;

    // Tempoary string
    std::string tmp = "";
    // Key position info
    int keyPos;
    int lineCount = 0;

    std::string settingLine = "";

    if (fp.is_open()) {
        // line string
        std::string line;
        
        // Search for the key
        while ( getline(fp, line) ) {
            if(line[0] == '#' || line.empty()) { tmp += line + "\n"; continue; } // skip if line is empty or comment 

            // Get key and value
            auto delimiterPos = line.find(":");
            auto name = line.substr(0, delimiterPos);
            //auto val = line.substr(delimiterPos + 1);

            if ( key != name) { 
                tmp += line + "\n";
                continue;
            }
            // Count the lines before the key
            if (!found) {
                lineCount++;
            }

            found = true;
            settingLine = line;

            // Get positional information of key line
            keyPos = length(tmp);
            //keyLineLenght = length(line);
            tmp = "";

            // The string to be written to the file
            std::string setting = key + ":" + value + "\n";

            // Delete acces chars at the end of the key line
            if (length(line) > length(setting)) {
                for (int i = 0; i <= length(line)-length(setting); i++) {
                    tmp += " ";
                }
                tmp += "\n";
            }
        }

        fp.close();
    }
    
    // if the last char is not a \n, add \n
    std::fstream f(path);

    std::string data;
    std::string data2;

    f.seekp(0,std::ios::end);

    f.seekp(f.tellp()-1);
    f >> data;

    f.seekp(f.tellp()-1);
    f >> data2;

    /*
    if (data == "" && data2 != " ") {
        
    }*/

    f.close();

    // The string to be written to the file
    std::string setting = key + ":" + value + "\n";

    // Write to the file

    std::fstream file(path);

    // In case the key wasn't found, write to end of file
    if (!found) { keyPos = length(tmp);}

    // Write setting line
    file.seekp(keyPos);
    file << setting;

    if ( found ) {
        // Write remaining file
        file.seekp(keyPos+length(setting));
        file << tmp;
    }

    /*
        For MALHINDS: remove spaces in last line here!
    */

    file.close();

    return true;
}

/**
 * @brief Write any string at the last line of a file
 * 
 * @param value What to write
 * @param path Which file and where
 * @return true The writing was sucsessfull; 
 * @return false The writing failed
 */
bool writeToLastLine(std::string value, std::string path = defaultOptionsPath()) {
    // check if the file exists
    if (! std::filesystem::is_regular_file(path)) { return false; }

    // open file
    std::fstream file(path);

    // make sure the file is open
    if (!file.is_open()) { return false; }

    // line string
    std::string line;
    std::string tmp;

    while ( getline(file, line) ) {
        // skip the line if there is no 
        long unsigned int ll = length(line);
        if (line.find("\n") > ll) { tmp += line + "\n"; continue; }
    }

    file.close();

    std::fstream fp (path);

    if (!fp.is_open()) { return false; }

    fp.seekp(length(tmp));

    fp << value << std::endl;

    fp.close();

    return true;
}


/**
 * @brief Saves all options
 * 
 * @param obj The json object containing all the options to be saved
 * @param ignoreLevel The level of ignorance. 0 = Nothing; 1 = key binds; 2 = regular options.
 * @param path The path to the options file
 */
bool saveOptions(json obj, int ignoreLevel = 0, std::string path = defaultOptionsPath()) {
    bool sucsessfull = true; // Whether or not the saving was sucsessfull

    // loop through all keys in options object
    for (json::iterator it = obj.begin(); it != obj.end(); it++) {

        if (ignoreLevel == 1 && it.key().substr(0,4) == "key_") { continue; }
        if (ignoreLevel == 2 && it.key().substr(0,4) != "key_") { continue; }

        // convert value to string
        std::string tmp;
        if (it.value() == true) { tmp = "true"; }
        else if (it.value() == false) { tmp = "false"; }
        else if (it.value().is_number_integer()) {
            int tmp2 = it.value();
            tmp = std::to_string(tmp2);
        }
        else if (it.value().is_number_float()) {
            float tmp2 = it.value();
            tmp = std::to_string(tmp2);
            tmp = tmp.substr(0, it.value().size());
        }
        else if (it.value().is_number_unsigned()) {
            unsigned tmp2 = it.value();
            tmp = std::to_string(tmp2);
        }
        else { tmp = it.value(); }
        

        if ( ! setOption(it.key(), tmp, path) ) {
            sucsessfull = false;
        }
    }

    return sucsessfull;
}

/**
 * @brief Creates an Options File
 * 
 * @param force If true, it will replace any options file. If false, it will not do anything if the optionsfile is already present
 * @param optionsStruct The structural data for the config file
 * @param path the path to the options file
 * @return true The creation was sucsessfull; 
 * @return false The creation failed
 */
bool createOptionsFile(bool force = false, std::string path = defaultOptionsPath(), json optionsStruct = defaultOptionsStruct) {
    // check if the file exists
    if (std::filesystem::is_regular_file(path) && ! force) { return false; }

    // if file exists and force is true, delete file
    if (!std::filesystem::is_regular_file(path) && force) {
        std::filesystem::remove(path);
    }

    // Create a file

    std::ofstream file (path);
    file << "";
    file.close();

    bool sucsessfull = true;

    // loop through all keys in options structure
    for (json::iterator it = optionsStruct.begin(); it != optionsStruct.end(); it++) {
        bool tmp = true;
        // if the key has a comment
        if (it.value()["comments"] != nullptr) {
            tmp = writeToLastLine(std::string(it.value()["comments"]), path);
            // check for "errors"
            if (tmp) {sucsessfull = false;}
        }
        // if the key has a value
        if (it.value() != nullptr) {
            tmp = setOption(it.key(), std::string(it.value()["val"]), path);
            // check for "errors"
            if (tmp) {sucsessfull = false;}
        }
    }
    return sucsessfull;
}

/**
 * @brief Deletes the options file
 * 
 * @param path The path to the options file
 * @return bool Whether or not the operation was sucsessfull
 */
bool deleteOptionsFile(std::string path = defaultOptionsPath()) {
    // check if the options file exists
    if (! std::filesystem::is_regular_file(path) ) { return true; }

    // delete file
    return std::filesystem::remove(path);
}

/**
 * @brief Tryes to import the options.txt from mojang
 * 
 * Note: this is currently not implemented or not completly functional
 * 
 * @param local_path The path to the M++ options file
 * @return bool Whether or not the operation was sucsessfull
 */
bool importConfig(std::string localOptPath = defaultOptionsPath(), bool doKeyBinds = true, std::string localKeyPath = defaultKeyBindsPath()) {
    std::string minecraftPath = getMcPath();
    // check if file exists
    if (! std::filesystem::is_regular_file(minecraftPath+"options.txt") ) { return false; }
    // read minecraft options file
    json mcOptions = getRawOptions(minecraftPath+"options.txt");
    // check if local options file exists
    if (! std::filesystem::is_regular_file(localOptPath) ) {
       // create options file
       createOptionsFile(false, localOptPath);
    }
    if (! std::filesystem::is_regular_file(localKeyPath) && doKeyBinds ) {
       // create options file
       createOptionsFile(false, localKeyPath, json::parse("{}"));
    }
    // save to local file
    saveOptions(mcOptions, 1, localOptPath); // set normal options
    // replace key bind LWJGE key codes to names

    if (doKeyBinds) {
        for (json::iterator it = mcOptions.begin(); it != mcOptions.end(); it++) {
            if (it.key().substr(0,4) == "key_") {
                mcOptions[it.key()] = LWJGEKeys::convertKey( std::stoi(std::string( it.value() )) );
            }
        }
    }

   if (doKeyBinds) { saveOptions(mcOptions, 2, localKeyPath); } // set key binds
   return true;
}

};

#endif