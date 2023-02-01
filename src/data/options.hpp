#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <algorithm>

// Obsolete. Please do not use. They were only a placeholder
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
 * @brief Get the Options json object
 * 
 * @param path The path to the options.txt
 * @return nlohmann::json The json object containing all the options (with mostly correct types)
 */
nlohmann::json getOptions(std::string path = "data/options.txt") {
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
 * @return nlohmann::json The json object containing all the options
 */
nlohmann::json getRawOptions(std::string path = "data/options.txt") {
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