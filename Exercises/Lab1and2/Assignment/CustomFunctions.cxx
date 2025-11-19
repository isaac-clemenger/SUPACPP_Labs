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

bool length_check(int data_length, int num_lines) {
    if (num_lines > data_length){
        return false;
    } else {
        return true;
    }
};