#include <iostream>
#include <cmath>

int main(){
    // Initialisation
    double x;
    double y;
    double magnitude;
    
    std::cout<< "Enter the x component of the vector: ";
    std::cin >> x;

    std::cout<< "Enter the y component of the vector: ";
    std::cin >> y;
    
    magnitude = std::sqrt(x * x + y * y);

    std::cout << "The magnitude of vector (x,y) is: " << magnitude << std::endl;
}