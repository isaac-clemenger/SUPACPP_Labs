// Graduate C++ Course (SUPACOO) 2025
// Assignment 1: Analuse a set of 2D data points stored in a text file
// Isaac Clemenger 19/11/12025 
// Implementation file for the custom functions to be used in our data analyisis

#include "CustomFunctions.h"
#include "CartesianVector.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

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

void print_N_lines(int N,std::vector<cartesian_vector> data){
    for(int i=0;i<N;i++){
        std::cout << "Point " << i+1 << ": (" << data[i].get_x() << ", " << data[i].get_y() << ")\n";
    }
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

bool length_check(int data_length, int num_lines){
    if (num_lines > data_length){
        return false;
    } else {
        return true;
    }
};

int integer_check(){
    std::string input;
    // Take input in using getline to capture whole input and not leave anything in the input buffer
    std::getline(std::cin, input);
    // Uses a try catch block wrapped in a while loop to force user into inputting an integer
    while(true)
    {
        try
        {
            // Try to convert input to an integer, can't just try to cast as stoi goes element by element, so will assign partial values
            // Define value to hold converted integer
            int value;
            std::istringstream input_stream(input);
            // Try to extract integer from input stream
            input_stream >> value;
            // First check if that failed, i.e no integer could be extracted
            if (input_stream.fail()) throw std::invalid_argument("Input is not an integer");
            // Now check if there are any remaining characters in the stream by casting to a char, if so then input was not a valid integer
            char remaining;
            if (input_stream >> remaining) throw std::invalid_argument("Input is not a valid integer");
            // If we reach here then input is valid, so return the integer value
            return value;
        } 
        catch (...) 
        {
            std::cout<<"Please enter an integer: \n";
            std::getline(std::cin, input);
        }
    }
}

char correct_character_check(char char1, char char2)
  {  
    std::string input;
    // Take input in using getline to capture whole input and not leave anything in the input buffer
    std::getline(std::cin, input);
    // Uses a try catch block wrapped in a while loop to force user into inputting a correct character
    while(true)
    {
      try
      {
        // Check if they haven't input a single character as requested
        if (input.length() != 1) throw input;
        // now know it's a single character, so we can extract it
        char character;
        character = input[0];
        // Check if the input is a character we want
        if (character == char1 || character == char2) return character; else throw character;
      } 
      catch (...) 
      {
        std::cout<<"Please enter a character that is a "<<char1<<" or "<<char2<<": \n";
        std::getline(std::cin, input);
      }
    }
  }