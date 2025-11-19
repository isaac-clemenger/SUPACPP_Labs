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

/*
class cartesian_vector {
    private:
    // x,y private members so they cannot be modified outside the class
    float x;
    float y;
    public:
    // Default constructor just creates a null vector
    cartesian_vector() : x(0.0), y(0.0) {}
    // Constructor
    cartesian_vector(float x_val, float y_val) : x(x_val), y(y_val) {}

    // Function to calculate magnitude
    // Const such that the points x,y are not modified
    float magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    // Function to calculate product
    float product() const {
        return x * y;
    }

    // Function to calculate x^y
    float power(float result, int index) const {
        // Calculate x^y by recursion
        int exponent = static_cast<int>(std::round(y));
        // Check edge case of 0 exponent
        if (exponent == 0) {
            return 1.0;
        }
        if (index > exponent) {
            return result;
        }
        else {
            result *= x;
            return power(result, index + 1);
        }
    }
    // Getters
    float get_x() const {
        return x;
    }
    float get_y() const {
        return y;
    }
};

void print_N_lines(int N,std::vector<cartesian_vector> data){
    for(int i=0;i<N;i++){
        std::cout << "Point " << i << ": (" << data[i].get_x() << ", " << data[i].get_y() << ")\n";
    }

};

std::vector<float> least_squares_fit(std::vector<cartesian_vector> &data){
    // Define quantiities we need
    float product_sum = 0;
    float x_sum = 0;
    float y_sum = 0;
    float x_squared_sum = 0;
    int N = data.size(); 
    // Passing the vector by reference as seemed neater
    for (auto &point : data) {
        product_sum += point.product();
        x_sum += point.get_x();
        y_sum += point.get_y();
        x_squared_sum += point.get_x() * point.get_x();
    }
    float p = (N * product_sum - x_sum * y_sum) / (N * x_squared_sum - x_sum * x_sum);
    float q = (x_squared_sum * y_sum - x_sum * product_sum) / (N * x_squared_sum - x_sum * x_sum);
    return {p, q};
};

float chi_square_test(std::vector<cartesian_vector> &data, std::vector<std::pair<float,float>> &errors, std::vector<float> &fit_params){
    float chi_square = 0.0;
    int N = data.size();
    float p = fit_params[0];
    float q = fit_params[1];
    for(int i=0; i<N; i++){
        float y = data[i].get_y();
        float y_fit = p * data[i].get_x() + q;
        float error = errors[i].second; // Assuming errors vector holds (error_in_x, error_in_y)
        chi_square += std::pow((y - y_fit) / error, 2);
    };
    return chi_square;

};

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

bool length_check(int data_length, int num_lines){
    if (num_lines > data_length){
        return false;
    } else {
        return true;
    }
};
*/

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