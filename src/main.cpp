// C++ Default Librarys
#include <iostream>

// Other Peoples Librarys
#include <curl/curl.h>
#include <nlohmann/json.hpp>

// Custom librarys
#include <options/options.hpp>
#include <comms/comms.h>
#include <sounds/v2/soundHandler.h>

#include <utils/os.hpp>
#include <utils/utils.hpp>

using json = nlohmann::json;

int main() {

    server x;

    std::cout << x.status() << "\n";
    
    return 0;
}