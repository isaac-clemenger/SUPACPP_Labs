// Graduate C++ Course (SUPACOO) 2025
// Assignment 1: Analuse a set of 2D data points stored in a text file
// Isaac Clemenger 19/11/12025 
// Declaration file for the custom functions to be used in our data analyisis

#pragma once
#include <vector>
#include "CartesianVector.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<float> least_squares_fit(std::vector<cartesian_vector> &data);

void print_N_lines(int N,std::vector<cartesian_vector> data);

float chi_square_test(std::vector<cartesian_vector> &data, std::vector<std::pair<float,float>> &errors, std::vector<float> &fit_params);

template<typename type> std::vector<type> process_file(std::string filename, int header_lines) {
    // Function to process data files and store them in vectors of a certain type
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(-1);       
    } else {
        std::cout << "File opened successfully: " << filename << std::endl;
    }    
    std::string line;
    // Skip header lines 
    for (int i = 0; i < header_lines; ++i) {
        std::getline(file, line);
    }

    // Create vector to hold data of a certain type
    std::vector<type> data;
    // Read in data line by line
    while (std::getline(file, line)) {
        // Store line as an input stream such that we can read x and y from it
        std::istringstream iss(line);
        // data is comma delimited
        std::string x_str, y_str;
        // Take up to first comma
        std::getline(iss, x_str, ',');
        // Take the rest of the line as y 
        std::getline(iss, y_str);
        // Convert strings to floats
        float x = std::stof(x_str);
        float y = std::stof(y_str);
        // Create an object to store x and y and add them to our vector
        type vec(x, y);
        data.push_back(vec);
    }
    // Close file now we've read in data
    file.close();
    // Return extracted data
    return data;
};

template<typename type> void produce_output_file(std::vector<type> output_data, std::string output_file_name, std::string file_header) {
    std::ofstream output_file(output_file_name);
    if (!output_file.is_open()) {
        std::cout << "Unable to open file for writing: " << output_file_name << std::endl;
        return;
    } else {
        // Header line
        output_file << file_header << "\n";
        // Insert data line by line
        for (auto &output_line : output_data) {
            output_file << output_line << "\n";
        };
        // Close file
        output_file.close();
        std::cout << "Output saved to " << output_file_name << std::endl;
    }
};

bool length_check(int data_length, int num_lines);

int integer_check();

char correct_character_check(char char1, char char2);

