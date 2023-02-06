/**
 * @brief gets the length of a string
 * 
 * @param value The string to get the length of
 * @return int The length of the string
 */
int length(auto value) {
    return end(value) - begin(value);
}

/**
 * @brief gets the type of the operating system
*/
std::string getOsName()
{
    #ifdef _WIN32
    return "Windows 32-bit";
    #elif _WIN64
    return "Windows 64-bit";
    #elif __APPLE__ || __MACH__
    return "Mac OSX";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #elif __unix || __unix__
    return "Unix";
    #else
    return "Other";
    #endif
}