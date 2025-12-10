// Graduate C++ Course (SUPACOO) 2025
// Assignment 2: Metropolis algorithm to generate standard particle physics distributions
// Isaac Clemenger 9/12/12025 
// Implementation file for the crystal ball distribution class

// Include class we inherit from
#include "FiniteFunctions.h"
#include "CrystalBall.h"

#include <cmath>

// overload constructor
CrystalBall::CrystalBall(double range_min, double range_max, std::string outfile, double x_bar, double sigma, double alpha, double n) 
: FiniteFunction(range_min, range_max, outfile), m_x_bar(x_bar), m_sigma(sigma), m_alpha(alpha), m_n(n) {
    // validate inputs
    if (m_alpha <= 0 ){
        std::cout<<"invalid input for alpha (alpha must be > 0), setting alpha=1 by default"<< std::endl;
        m_alpha = 1; 
    }
    if (m_n <= 1){
        std::cout<<"invalid input for n (n must be > 1), setting n=2 by default"<< std::endl;
        m_n = 2; 
    }
}

/*
############################
Define function
############################
*/
// numerical constants
const double pi = 3.141592653589793238462643383279;

double CrystalBall::CrystalBall_Distribution(double x){
    // Determine prefactor
    double C;
    double D;
    double N;
    // Define repeated terms
    double alpha_exponential;
    alpha_exponential = std::exp(-0.5*std::pow(m_alpha,2));
    double n_alpha_quotient = m_n/m_alpha;

    C = n_alpha_quotient * (1 / (m_n -1)) * alpha_exponential;
    D = sqrt(pi/2) * (1 + std::erf(m_alpha/(sqrt(2))));

    N = 1/(m_sigma*(C+D));
    // Compute inequatilty to determine shape of function
    double inequaltity;
    inequaltity = (x - m_x_bar)/m_sigma;
    if (inequaltity > (-1*m_alpha)) {
        double exponent;
        exponent = -0.5*std::pow(inequaltity,2);
        return N * std::exp(exponent);
    } else {
        double A = std::pow(n_alpha_quotient, m_n) * alpha_exponential;
        double B = n_alpha_quotient - m_alpha;
        return N * A * std::pow(B-inequaltity, -1 * m_n);
    }
}

double CrystalBall::callFunction(double x) {return this->CrystalBall_Distribution(x);};

/*
###########
Printing
###########
*/

void CrystalBall::printInfo(){
  std::cout << "rangeMin: " << m_RMin << std::endl;
  std::cout << "rangeMax: " << m_RMax << std::endl;
  std::cout << "integral: " << m_Integral << ", calculated using " << m_IntDiv << " divisions" << std::endl;
  std::cout << "function: " << m_FunctionName << std::endl;
  std::cout << "distribution x_bar: " << m_x_bar << std::endl;
  std::cout << "distribution sigma: " << m_sigma << std::endl;
  std::cout << "distribution alpha: " << m_alpha << std::endl;
  std::cout << "distribution n: " << m_n << std::endl;
}