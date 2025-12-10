// Graduate C++ Course (SUPACOO) 2025
// Assignment 2: Metropolis algorithm to generate standard particle physics distributions
// Isaac Clemenger 9/12/12025 
// Implementation file for the normal distribution class

// Include class we inherit from
#include "FiniteFunctions.h"
#include "Normal.h"

#include <cmath>

// overload constructor
Normal::Normal(double range_min, double range_max, std::string outfile, double mu, double sigma) 
: FiniteFunction(range_min, range_max, outfile), m_mu(mu), m_sigma(sigma) {}

/*
############################
Define function
############################
*/
// numerical constants
const double pi = 3.141592653589793238462643383279;

double Normal::Normal_Distribution(double x){
    double coeff = 1/(m_sigma*sqrt(2*pi));
    double exponent = -0.5 * std::pow(((x - m_mu)/m_sigma),2);
    return coeff * std::exp(exponent);
}

double Normal::callFunction(double x) {return this->Normal_Distribution(x);};

/*
###########
Printing
###########
*/

void Normal::printInfo(){
  std::cout << "rangeMin: " << m_RMin << std::endl;
  std::cout << "rangeMax: " << m_RMax << std::endl;
  std::cout << "integral: " << m_Integral << ", calculated using " << m_IntDiv << " divisions" << std::endl;
  std::cout << "function: " << m_FunctionName << std::endl;
  std::cout << "distribution mean: " << m_mu << std::endl;
  std::cout << "distribution standard deviation: " << m_sigma << std::endl;
}