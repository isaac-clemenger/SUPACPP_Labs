// Graduate C++ Course (SUPACOO) 2025
// Assignment 2: Metropolis algorithm to generate standard particle physics distributions
// Isaac Clemenger 9/12/12025 
// Header file for the crystal ball distribution class

// Include class we inherit from
#include "FiniteFunctions.h"
#include <string>

#pragma once

class CrystalBall : public FiniteFunction {

public:
    // Default constructor
    CrystalBall();
    // Need to set mean and std dev of the normal distribution in the manual constructor, overload the FiniteFunctions constructor
    CrystalBall(double range_min, double range_max, std::string outfile, double x_bar, double sigma, double alpha, double n);

    double callFunction(double x); //Call the function with value x (Override finite functions def)
    void printInfo(); //Dump parameter info about the current function (Override finite functions def)

private:
    // Specific variables
    double m_x_bar;
    double m_sigma;
    double m_alpha;
    double m_n;
     
    // Specific distribution function
    double CrystalBall_Distribution(double x);
};