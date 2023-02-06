#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <limits>

using json = nlohmann::json;

#ifndef _OPTIONS_H_
#define _OPTIONS_H_
#pragma once

namespace options {

// Place holder vars
/**
 * @brief the FPS cap of the game
*/
int FPS = 60;
/**
 * @brief the Render Distance of the game. Not yet in chunks
*/
double renderDistance = 10;
/**
 * @brief The FOV of the camera
*/
float FOV = 45;
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

/**
 * @brief Set the value type of the values in a json object
 * 
 * @param jobj The Json object to set the value types
 * @return nlohmann::json The json object with correct* value types. *Arrays and objects are currently not supported
 */
nlohmann::json setOptionValuetypes(nlohmann::json jobj);

/**
 * @brief Get the Options json object
 * 
 * @param path The path to the options.txt
 * @return nlohmann::json The json object containing all the options (with mostly correct types). In case of am error, the object will contain a key called "error" containing some detail of the error
 */
nlohmann::json getOptions(std::string path = "data/options.txt");
/**
 * @brief Get the Options json object
 * The same as getOptions(); but the data types are all strings
 * 
 * @param path The path to the options.txt
 * @return nlohmann::json The json object containing all the options. In case of am error, the object will contain a key called "error" containing some detail of the error
 */
nlohmann::json getRawOptions(std::string path = "data/options.txt");

/**
 * @brief Set an option by a key in the options file
 * 
 * @param key The key to be modified
 * @param value The value to set the key to
 * @param path The path to the options file
 * @return true The operation was succsessfull,
 * @return false The operation failed succsessfully
 */
bool setOption(std::string key, auto value, std::string path = "data/options.txt");

/**
 * @brief Write any string at the last line of a file
 * 
 * @param value What to write
 * @param path Which file and where
 * @return true The writing was sucsessfull; 
 * @return false The writing failed
 */
bool writeToLastLine(std::string value, std::string path = "data/options.txt");


/**
 * @brief Saves all options
 * 
 * @param obj The json object containing all the options to be saved
 * @param ignoreLevel The level of ignorance. 0 = Nothing; 1 = key binds; 2 = regular options.
 * @param path The path to the options file
 */
bool saveOptions(json obj, int ignoreLevel = 0, std::string path = "data/options.txt");

/**
 * @brief Creates an Options File
 * 
 * @param force If true, it will replace any options file. If false, it will not do anything if the optionsfile is already present
 * @param optionsStruct The structural data for the config file
 * @param path the path to the options file
 * @return true The creation was sucsessfull; 
 * @return false The creation failed
 */
bool createOptionsFile(bool force = false, std::string path = "data/options.txt", json optionsStruct = options::defaultOptionsStruct);

/**
 * @brief Deletes the options file
 * 
 * @param path The path to the options file
 * @return bool Whether or not the operation was sucsessfull
 */
bool deleteOptionsFile(std::string path = "data/options.txt");

/**
 * @brief Tryes to import the options.txt from mojang
 * 
 * Note: this is currently not implemented or not completly functional
 * 
 * @param local_path The path to the M++ options file
 * @return bool Whether or not the operation was sucsessfull
 */
bool importConfig(std::string localOptPath = "data/options.txt", bool doKeyBinds = true, std::string localKeyPath = "data/keyBinds.txt");

}

#endif