// This file will be obsolete when I make the optionsfile a JSON (or something else) file.
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

/*
// Config Tests
std::ifstream cFile ("data/options.txt");
std::cout << "Settings:\n";
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
        std::cout << " " << name << ": " << value << '\n';
        // Set Options
        if (name == "fps") { FPS = std::stoi(value); }
        if (name == "renderDistance") { renderDistance = std::stoi(value); }
        if (name == "fov") { FOV = 70+40*std::stof(value); std::cout << FOV << "\n"; }
        if (name == "title") { windowTitle = value.c_str(); }
    }
    
}
else {
    std::cerr << "Couldn't open config file for reading.\n";
}*/