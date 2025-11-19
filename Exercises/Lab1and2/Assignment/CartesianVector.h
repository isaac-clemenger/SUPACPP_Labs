// Graduate C++ Course (SUPACOO) 2025
// Assignment 1: Analuse a set of 2D data points stored in a text file
// Isaac Clemenger 19/11/12025 
// Declaration file for the class cartesian_vector to store the data

#pragma once

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
    float magnitude() const;

    // Function to calculate product
    float product() const;

    // Function to calculate x^y
    float power(float result, int index) const;

    // Getters
    float get_x() const {return x;}
    float get_y() const {return y;}
};