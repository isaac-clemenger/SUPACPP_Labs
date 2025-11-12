#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>

class cartesian_vector {
    public:
        float x;
        float y;
    // Constructor
    cartesian_vector(float x_val, float y_val) : x(x_val), y(y_val) {}

    // Function to calculate magnitude
    // Const such that the points x,y are not modified
    float magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    // Function to calculate product
    float product() const {
        return x * y;
    }

    // Function to calculate x^y
    float power(float result, int index) const {
        // Calculate x^y by recursion
        int exponent = static_cast<int>(std::round(y));
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
    // Getters
    float get_x() const {
        return x;
    }
    float get_y() const {
        return y;
    }
};

void print_N_lines(int N,std::vector<cartesian_vector> data){
    for(int i=0;i<N;i++){
        std::cout << "Point " << i << ": (" << data[i].get_x() << ", " << data[i].get_y() << ")\n";
    }

};

std::vector<float> least_squares_fit(std::vector<cartesian_vector> &data){
    // Define quantiities we need
    float product_sum = 0;
    float x_sum = 0;
    float y_sum = 0;
    float x_squared_sum = 0;
    int N = data.size(); 
    // Passing the vector by reference as seemed neater
    for (auto &point : data) {
        product_sum += point.product();
        x_sum += point.get_x();
        y_sum += point.get_y();
        x_squared_sum += point.get_x() * point.get_x();
    }
    float p = (N * product_sum - x_sum * y_sum) / (N * x_squared_sum - x_sum * x_sum);
    float q = (x_squared_sum * y_sum - x_sum * product_sum) / (N * x_squared_sum - x_sum * x_sum);
    return {p, q};
};



int main() {
    std::string inputFile = "input2D_float.txt";
    std::ifstream data_file;
    data_file.open(inputFile);
    if (!data_file.is_open()) {
        std::cerr << "Error opening file: " << inputFile << std::endl;
        return -1;
    }
    else {
        std::cout << "File opened successfully: " << inputFile <<"\n"<< std::endl;
    }    

    std::vector<cartesian_vector> data;
    std::string line;
    int header_lines = 1;
    // Read and ignore header lines
    for (int i = 0; i < header_lines; ++i) {
        std::getline(data_file, line);
    }
    // Read in desired data 
    while (std::getline(data_file, line)) {
        // Store line as an input stream such that we can read x and y from it
        std::istringstream iss(line);
        // data is comma delimited
        std::string x_str, y_str;
        std::getline(iss, x_str, ','); 
        std::getline(iss, y_str);
        float x = std::stof(x_str);
        float y = std::stof(y_str);
        cartesian_vector vec(x, y);
        data.push_back(vec)
    ;
    }
    // Close file now we've extracted data
    data_file.close();

    int N = 10;
    print_N_lines(N, data);
    std::vector<float> fit_params = least_squares_fit(data);
    std::cout << "\nLeast squares fit parameters:\n";
    std::cout << "p (slope): " << fit_params[0] << std::endl;
    std::cout << "q (intercept): " << fit_params[1] << "\n" << std::endl;

    // Calculate x^y for the first point
    std::cout << "x^y for the first point: " << data[2].power(data[2].get_x(),2) << std::endl;
}