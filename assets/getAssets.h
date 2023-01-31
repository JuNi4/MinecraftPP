/**
 * @file getAssets.h
 * @author JuNi4
 * @brief Downloads all assets from mojang
 * @version 0.1
 * @date 2023-01-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

/**
 * @brief posts a http get request
 * 
 * @param url the url to post the get request to, https is automaticly replaced with http
 * @return std::string the body of the response
 */
std::string httpGet(std::string url);

/**
 * @brief downloads a file from a url
 * 
 * @param url the url to get the file from
 * @return int 
 */
int downloadFile(const char* url, const char* filename);

/**
 * @brief Get the Version Meta json object from mojang
 * 
 * @param version the minecraft version to get data from
 * @return json object containing the data of the version or the error
 */
json getVersionMeta(std::string version);

/**
 * @brief Download and extract the assets from a minecraft jar
 * 
 * @param version the minecraft version to get assets from
 */
void getAssets(std::string version);

/**
 * @brief Dowwnload the resources from mojang
 * 
 * @param version the minecraft version to get assets from
 */
void getResources(std::string version);

/**
 * @brief The main function of the programm
 * 
 * @return int Arbuatrary number
 */
int main();