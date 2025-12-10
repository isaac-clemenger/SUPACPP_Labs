// Graduate C++ Course (SUPACOO) 2025
// Assignment 2: Metropolis algorithm to generate standard particle physics distributions
// Isaac Clemenger 9/12/12025 
// Implementation file for a few custom functions

#include "CustomFunctions.h"
// Function to read in data
std::vector<double> Extract_data(std::string file_path) {
    // open file using input stream
    std::ifstream file;
    file.open(file_path);
    std::vector<double> data; 
    if (!file.is_open()) {
        std::cerr << "Error: could not open data file: " << file_path << std::endl;
        return data;
    }
    std::string line;
    while (std::getline(file,line)){
        std::istringstream iss(line);
        float data_point = std::stod(line);
        data.push_back(data_point);
    }
    file.close();
    return data;
}