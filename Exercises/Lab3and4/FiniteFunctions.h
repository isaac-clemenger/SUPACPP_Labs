#include <string>
#include <vector>
#include "gnuplot-iostream.h"
#include <random>

#pragma once //Replacement for IFNDEF

class FiniteFunction{

public:
  FiniteFunction(); //Empty constructor
  FiniteFunction(double range_min, double range_max, std::string outfile); //Variable constructor
  ~FiniteFunction(); //Destructor
  double rangeMin(); //Low end of the range the function is defined within
  double rangeMax(); //High end of the range the function is defined within
  double integral(int Ndiv = 1000); 
  std::vector< std::pair<double,double> > scanFunction(int Nscan = 1000); //Scan over function to plot it (slight hack needed to plot function in gnuplot)
  void setRangeMin(double RMin);
  void setRangeMax(double RMax);
  void setOutfile(std::string outfile);
  void plotFunction(); //Plot the function using scanFunction
  
  //Plot the supplied data points (either provided data or points sampled from function) as a histogram using NBins
  void plotData(std::vector<double> &points, int NBins, bool isdata=true); //NB! use isdata flag to pick between data and sampled distributions
  virtual void printInfo(); //Dump parameter info about the current function (Overridable)
  virtual double callFunction(double x); //Call the function with value x (Overridable)

  // Define entire metropolis algorithm here as it is a template function such that it can be used for each of the three distributions
  template<typename type> std::vector<double> Metropolis_algorithm(type sample_function, int Num_points, double sigma){
        // define vector to store data
    std::vector<double> data;
    // initialise random numbers
    unsigned int seed = 67; //unsigned to allow wide range of seeds
    // Define the function we use to generate pseudo random numbers using the input seed
    std::mt19937 mtEngine{seed};
    // Create uniform distribution defined over a given range
    std::uniform_real_distribution<double> uniform_pdf{m_RMin, m_RMax};
    // use the random number generator we defined to draw a number from the uniform distribtuion
    double x  = uniform_pdf(mtEngine);
    // initialise this as the first point in our distribution
    data.push_back(x);
    
    // using a for loop generate as many points as requested
    for (int i = 0; i < Num_points; i++){
        // generate y from normal distribution centered on x, with arbitrary standard deviation
        std::normal_distribution<double> normal_pdf{data[i],sigma};
        double y = normal_pdf(mtEngine);
        
        // compute f(y), f(x_i)
        double f_y = sample_function.callFunction(y);
        double f_x = sample_function.callFunction(data[i]);

        // Metropolis step, find the minimum of this quotient and 1
        double A = std::min(f_y/f_x, 1.0);

        // Accept / reject step
        // first need a distribution from 0 to 1
        std::uniform_real_distribution<double> uniform_pdf_0_to_1{0,1.0};
        double T = uniform_pdf_0_to_1(mtEngine);
        // Accept or reject
        if (T < A) {
            data.push_back(y);
        } else {
            data.push_back(data[i]);
        }
    }
    return data;
  }

  //Protected members can be accessed by child classes but not users
protected:
  double m_RMin;
  double m_RMax;
  double m_Integral;
  int m_IntDiv = 0; //Number of division for performing integral
  std::string m_FunctionName;
  std::string m_OutData; //Output filename for data
  std::string m_OutPng; //Output filename for plot
  std::vector< std::pair<double,double> > m_data; //input data points to plot
  std::vector< std::pair<double,double> > m_samples; //Holder for randomly sampled data 
  std::vector< std::pair<double,double> > m_function_scan; //holder for data from scanFunction (slight hack needed to plot function in gnuplot)
  bool m_plotfunction = false; //Flag to determine whether to plot function
  bool m_plotdatapoints = false; //Flag to determine whether to plot input data
  bool m_plotsamplepoints = false; //Flag to determine whether to plot sampled data 
  double integrate(int Ndiv);
  std::vector< std::pair<double, double> > makeHist(std::vector<double> &points, int Nbins); //Helper function to turn data points into histogram with Nbins
  void checkPath(std::string outstring); //Helper function to ensure data and png paths are correct
  void generatePlot(Gnuplot &gp); 
  
private:
  double invxsquared(double x); //The default functional form
};
