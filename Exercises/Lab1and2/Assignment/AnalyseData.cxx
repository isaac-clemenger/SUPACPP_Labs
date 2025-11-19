// Graduate C++ Course (SUPACOO) 2025
// Assignment 1: Analuse a set of 2D data points stored in a text file
// Isaac Clemenger 19/11/12025 
// Main file to run analysis code

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Include custom headers
#include "CustomFunctions.h"
#include "CartesianVector.h"

int main() {
    // Define desired file names
    std::string inputFile = "input2D_float.txt";
    std::string errorsFile = "error2D_float.txt";

    // Process input data
    std::vector<cartesian_vector> data;
    data = process_file <cartesian_vector>(inputFile, 1);

    // file size 
    int file_size = data.size();
    // Process error data
    std::vector<std::pair<float,float>> error_data;
    error_data = process_file <std::pair<float,float>>(errorsFile, 1);

    // Ask user if they want to print data
    std::cout << "Would you like to print the data? (y/n): ";
    char print_choice;
    std::cin >> print_choice;
    switch (print_choice)
    {
    case 'y': {
        std::cout << "How many lines would you like to print? ";
        int num_lines;
        std::cin >> num_lines;
        bool valid_input = length_check(file_size, num_lines);
        if (valid_input == true){
            print_N_lines(num_lines, data);
        } else {
            std::cout << "Invalid input. Printing first 5 lines by default." << std::endl;
            print_N_lines(5, data);
        };
        break;
    }
    case 'n': {
        break;
    }
    }

    // Ask user if they want to determine the maginitude of the vectors
    std::cout << "Would you like to calculate the magnitude of the vectors? (y/n): ";
    char magnitude_choice;
    std::cin >> magnitude_choice;
    switch (magnitude_choice)
    {
    case 'y': {
        std::cout << "How many lines would you like to calculate the magnitude for? (There are " << file_size << " lines in the file): ";
        int num_lines;
        std::cin >> num_lines;
        bool valid_input = length_check(file_size, num_lines);
        // Initialise magnitudes vector
        std::vector<float> magnitudes;
        if (valid_input == true){
            for (int i=0; i < num_lines; i++){
                magnitudes.push_back(data[i].magnitude());
                std::cout << "Magnitude of vector " << i+1 << ": " << magnitudes[i] << std::endl;
            };
        } else {
            std::cout << "Invalid input. Calculating magnitude for first 5 lines by default." << std::endl;
            for (int i=0; i < 5; i++){
                magnitudes.push_back(data[i].magnitude());
                std::cout << "Magnitude of vector " << i+1 << ": " << magnitudes[i] << std::endl;
            };
        };
        produce_output_file<float>(magnitudes, "vector_magnitudes.txt", "Magnitudes of each point:");
        break;  
    }
    }

    // Ask user if they want to perform least squares fit
    std::cout << "Would you like to perform a least squares fit of the data? (y/n): ";
    char fit_choice;
    std::cin >> fit_choice;
    switch (fit_choice)
    {   
    case 'y': {
        std::vector<float> fit_params = least_squares_fit(data);
        fit_params.push_back(chi_square_test(data, error_data, fit_params));
        std::cout << "\nLeast squares fit parameters:\n";
        std::cout << "p (slope): " << fit_params[0] << std::endl;
        std::cout << "q (intercept): " << fit_params[1] << "" << std::endl;
        std::cout << "Chi-square test result: " << fit_params[2] << "\n" << std::endl;
        std::vector<std::string> fit_string = {"y = " + std::to_string(fit_params[0]) + " * x + " + std::to_string(fit_params[1]),"Chi Squared = " + std::to_string(fit_params[2])};
        produce_output_file<std::string>(fit_string, "linear_fit_parameters.txt", "Least squares fit of the data:");
        break;
        }
    case 'n': {
        break;
        }
    }

    // Ask user if they want to calculate x^y for the vectors
    std::cout << "Would you like to calculate x^y for the data? (y/n): ";
    char power_choice;
    std::cin >> power_choice;
    switch (power_choice)
    {
    case 'y': {
        std::cout << "How many lines would you like to calculate x^y for? (There are " << file_size << " lines in the file): ";
        int num_lines;
        std::cin >> num_lines;
        bool valid_input = length_check(file_size, num_lines);
        // Initialise power results vector
        std::vector<float> power_results;
        if (valid_input == true){
            for (int i; i < num_lines; i++) {
                power_results.push_back(data[i].power(data[i].get_x(), 2));
                std::cout << "x^y for point " << i+1 << ": " << power_results[i] << std::endl;
            }
        } else {
            std::cout << "Invalid input. Calculating x^y for first 5 lines by default." << std::endl;
            for (int i; i < 5; i++) {
                power_results.push_back(data[i].power(data[i].get_x(), 2));
                std::cout << "x^y for point " << i+1 << ": " << power_results[i] << std::endl;
            }
        };
        produce_output_file<float>(power_results, "power_results.txt", "x^y results for each point:");
        break;
    }
    case 'n': {
        break;  
    }
    }
};