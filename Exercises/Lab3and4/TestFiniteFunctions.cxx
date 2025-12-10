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
    FiniteFunction invXsq(-10,10,"MyInvXsq");
    invXsq.plotFunction();
    invXsq.printInfo();
    invXsq.plotData(data, 100, true);

    // repeat for normal distribution
    Normal NormalDist(-10,10,"MyNormal",-2,0.8);
    NormalDist.plotFunction();
    NormalDist.printInfo();
    NormalDist.plotData(data, 100, true);

    // repeat for Cauchy-Lorentz distribution
    CauchyLorentz CauchyLorentzDist(-10,10,"MyCauchyLorentz",0.8,-2);
    CauchyLorentzDist.plotFunction();
    CauchyLorentzDist.printInfo();
    CauchyLorentzDist.plotData(data, 100, true);

    // Finally for Crystal ball
    CrystalBall CrystalBallDist(-10,10,"MyCrystalBall",-2,0.9,1.5,3);
    CrystalBallDist.plotFunction();
    CrystalBallDist.printInfo();
    CrystalBallDist.plotData(data, 100, true);

    /*
    std::vector<double> sampled_data;
    Normal sample_function(-10,10,"SampleFunction",-2,0.8);
    sampled_data = function.Metropolis_algorithm(sample_function, 10000, 0.4);
    function.plotData(sampled_data,100,false);
    */
};




