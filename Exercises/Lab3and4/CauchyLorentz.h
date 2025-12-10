// Graduate C++ Course (SUPACOO) 2025
// Assignment 2: Metropolis algorithm to generate standard particle physics distributions
// Isaac Clemenger 9/12/12025 
// Header file for the cauchy-lorentz distribution class

// Include class we inherit from
#include "FiniteFunctions.h"
#include <string>

#pragma once

class CauchyLorentz : public FiniteFunction {

public:
    // Default constructor
    CauchyLorentz();
    // Need to set mean and std dev of the normal distribution in the manual constructor, overload the FiniteFunctions constructor
    CauchyLorentz(double range_min, double range_max, std::string outfile, double gamma, double x_0);

    double callFunction(double x); //Call the function with value x (Override finite functions def)
    void printInfo(); //Dump parameter info about the current function (Override finite functions def)

private:
    // Specific variables
    double m_gamma;
    double m_x_0;
     
    // Specific distribution function
    double CauchyLorentz_Distribution(double x);
    double check_gamma(double gamma);
};