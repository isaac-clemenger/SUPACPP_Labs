// Graduate C++ Course (SUPACOO) 2025
// Assignment 2: Metropolis algorithm to generate standard particle physics distributions
// Isaac Clemenger 9/12/12025 
// Implementation file for the Cauchy-Lorentz distribution class

// Include class we inherit from
#include "FiniteFunctions.h"
#include "CauchyLorentz.h"

#include <cmath>

// overload constructor
CauchyLorentz::CauchyLorentz(double range_min, double range_max, std::string outfile, double gamma, double x_0) 
: FiniteFunction(range_min, range_max, outfile), m_gamma(gamma), m_x_0(x_0) {
    if (m_gamma <= 0 ){
        std::cout<<"invalid input for gamma (gamma must be > 0), setting gamma=1 by default"<< std::endl;
        m_gamma = 1; 
    }
}

/*
############################
Define function
############################
*/
// numerical constants
const double pi = 3.141592653589793238462643383279;

double CauchyLorentz::CauchyLorentz_Distribution(double x){
    return 1/(pi*m_gamma*(1+std::pow((x - m_x_0)/m_gamma, 2)));
}

double CauchyLorentz::callFunction(double x) {return this->CauchyLorentz_Distribution(x);};

/*
###########
Printing
###########
*/

void CauchyLorentz::printInfo(){
  std::cout << "rangeMin: " << m_RMin << std::endl;
  std::cout << "rangeMax: " << m_RMax << std::endl;
  std::cout << "integral: " << m_Integral << ", calculated using " << m_IntDiv << " divisions" << std::endl;
  std::cout << "function: " << m_FunctionName << std::endl;
  std::cout << "distribution gamma: " << m_gamma << std::endl;
  std::cout << "distribution x_0: " << m_x_0 << std::endl;
}

/*
###########
Validation
###########
*/
