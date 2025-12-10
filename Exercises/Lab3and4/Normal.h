// Graduate C++ Course (SUPACOO) 2025
// Assignment 2: Metropolis algorithm to generate standard particle physics distributions
// Isaac Clemenger 9/12/12025 
// Header file for the normal distribution class

// Include class we inherit from
#include "FiniteFunctions.h"
#include <string>

#pragma once

class Normal : public FiniteFunction {

public:
    // Default constructor
    Normal();
    // Need to set mean and std dev of the normal distribution in the manual constructor, overload the FiniteFunctions constructor
    Normal(double range_min, double range_max, std::string outfile, double mu, double sigma);

    double callFunction(double x); //Call the function with value x (Override finite functions def)
    void printInfo(); //Dump parameter info about the current function (Override finite functions def)

private:
    // Specific variables
    double m_mu;
    double m_sigma;
     
    // Specific distribution function
    double Normal_Distribution(double x);
};