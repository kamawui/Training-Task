#pragma once
#include <string>
#include "json.hpp"

void checkIfFileOpened(const std::ifstream&);
void checkIfFileOpened(const std::ofstream&);
nlohmann::json parseJSON(const std::string&);