// Graduate C++ Course (SUPACOO) 2025
// Assignment 2: Metropolis algorithm to generate standard particle physics distributions
// Isaac Clemenger 9/12/12025 
// Main file to run analysis code

// Include standard packages
#include <iostream>
#include <vector>
#include <string>


// Include custom headers
#include "FiniteFunctions.h"
#include "Normal.h"
#include "CauchyLorentz.h"
#include "CrystalBall.h"
#include "CustomFunctions.h"


// main function
int main() {
    // Define file path
    std::string file_path;
    file_path = "../../Data/MysteryData20000.txt";
    // Store data from file in a vector of floats
    std::vector<double> data;
    data = Extract_data(file_path);

    // create a finite function with range -10,10, plot it and the data
    CrystalBall function(-10,10,"MyCrystalBall2",-2,0.9,1.5,3);
    function.plotFunction();
    function.printInfo();
    function.plotData(data, 100, true);

    std::vector<double> sampled_data;
    Normal sample_function(-10,10,"SampleFunction",-2,0.8);
    sampled_data = function.Metropolis_algorithm(sample_function, 10000, 0.4);
    function.plotData(sampled_data,100,false);
};




