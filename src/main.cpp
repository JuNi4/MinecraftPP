// C++ Default Librarys
#include <iostream>

// Other Peoples Librarys
#include <curl/curl.h>
#include <nlohmann/json.hpp>

// Custom librarys
#include <options/options.hpp>
#include <comms/comms.h>
#include <sounds/v2/soundHandler.h>

#include <os.hpp>
#include <utils.hpp>

using json = nlohmann::json;

int main() {

    server x("mc.hypixel.net");

    x.status();
    
    return 0;
}