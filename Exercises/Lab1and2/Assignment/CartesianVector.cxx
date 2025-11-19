// Graduate C++ Course (SUPACOO) 2025
// Assignment 1: Analuse a set of 2D data points stored in a text file
// Isaac Clemenger 19/11/12025 
// Implementation file for the class cartesian_vector to store the data

#include "CartesianVector.h"
#include <cmath>

// Function to calculate magnitude
// Const such that the points x,y are not modified
float cartesian_vector::magnitude() const {
        return std::sqrt(x * x + y * y);
}

// Function to calculate product
float cartesian_vector::product() const {
    return x * y;
}

// Function to calculate x^y    
float cartesian_vector::power(float result, int index) const {
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
