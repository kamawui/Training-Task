#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"

void checkIfFileOpened(const std::ifstream& file)
{
    if (!file.is_open()) {
        throw std::runtime_error("Error: failed to open a file");
    }
}

void checkIfFileOpened(const std::ofstream& file)
{
    if (!file.is_open()) {
        throw std::runtime_error("Error: failed to open a file");
    }
}

// gets data from a file and returns it in json format
nlohmann::json parseJSON(const std::string& fileName) 
{
    std::ifstream file(fileName);

    checkIfFileOpened(file);

    nlohmann::json data;
    file >> data;

    file.close();

    return data;
}



