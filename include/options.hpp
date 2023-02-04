#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <filesystem>

using json = nlohmann::json;

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

int length(auto value) {
    return end(value) - begin(value);
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
nlohmann::json getOptions(std::string path = "data/options.txt") {
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
nlohmann::json getRawOptions(std::string path = "data/options.txt") {
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
 * @return true The operation was succsessfull
 * @return false The operation failed succsessfully
 */
bool setOption(std::string key, auto value, std::string path = "data/options.txt") {
    std::cout << key << " " << value << " " << path << "\n";
    // check if options file exists
    if (!std::filesystem::is_regular_file(path)) { return false; }
    // Load config file
    std::fstream fp (path);

    if (fp.is_open()) {
        // line string
        std::string line;

        // if the key was found in the options file
        bool found = false;

        // Tempoary string
        std::string tmp = "";
        // Key position info
        int keyPos;
        //int keyLineLenght;

        while ( getline(fp, line) ) {
            if(line[0] == '#' || line.empty()) { tmp += line + "\n"; continue; } // skip if line is empty or comment 

            // Get key and value
            auto delimiterPos = line.find(":");
            auto name = line.substr(0, delimiterPos);
            //auto val = line.substr(delimiterPos + 1);

            if ( key != name ) { 
                tmp += line + "\n";
                continue;
            }

            found = true;

            // Get positional information of key line
            keyPos = length(tmp);
            //keyLineLenght = length(line);
        }

        // The char* to be written to the file
        const char* setting = (key + ":" + value + "\n").c_str();
        std::cout << setting;

        // Set key to value
        if ( found ) {
            // write new config value at position
            fp.seekp(keyPos);

            fp.write(setting, length(std::string(setting)));
            // write the remaining part of config file
            fp.seekp(keyPos+length(std::string(setting)));
            //fp.write(tmp.c_str(), sizeof(tmp.c_str()));
            std::cout << "found and written!\n";
        }


        fp.close();
    }

    return true;
}