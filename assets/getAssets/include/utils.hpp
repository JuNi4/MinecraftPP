/**
 * @file print.hpp
 * @author JuNi4
 * @brief simple python-like print funktion
 * @version 0.1
 * @date 2023-01-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

void print(std::string value, std::string end = "\n") {
    std::cout << value << end;
}

int len(auto value) {
    return end(value) - begin(value);
}