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
    // Metropolis sample of the data
    std::vector<double> sampled_invXsq = invXsq.Metropolis_algorithm(invXsq, 10000, 0.4);
    invXsq.plotData(sampled_invXsq,100,false);

    // repeat for normal distribution (this is what data is generated from)
    Normal NormalDist(-10,10,"MyNormal",-2,1);
    NormalDist.plotFunction();
    NormalDist.printInfo();
    NormalDist.plotData(data, 100, true);
    // Metropolis sample of the data
    std::vector<double> sampled_normal = NormalDist.Metropolis_algorithm(NormalDist, 10000, 0.4);
    NormalDist.plotData(sampled_normal,100,false);

    // repeat for Cauchy-Lorentz distribution
    CauchyLorentz CauchyLorentzDist(-10,10,"MyCauchyLorentz",0.8,-2);
    CauchyLorentzDist.plotFunction();
    CauchyLorentzDist.printInfo();
    CauchyLorentzDist.plotData(data, 100, true);
    // Metropolis sample of the data
    std::vector<double> sampled_CauchyLorentz = CauchyLorentzDist.Metropolis_algorithm(CauchyLorentzDist, 10000, 0.4);
    CauchyLorentzDist.plotData(sampled_CauchyLorentz,100,false);

    // Finally for Crystal ball
    CrystalBall CrystalBallDist(-10,10,"MyCrystalBall",-2,0.9,1.5,3);
    CrystalBallDist.plotFunction();
    CrystalBallDist.printInfo();
    CrystalBallDist.plotData(data, 100, true);
    // Metropolis sample of the data
    std::vector<double> sampled_CrystalBall = CrystalBallDist.Metropolis_algorithm(CrystalBallDist, 10000, 0.4);
    CrystalBallDist.plotData(sampled_CrystalBall,100,false);

};




