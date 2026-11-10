#include <iostream>
#include <cmath>

int main() {
    double x, y;

    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "Enter y: ";
    std::cin >> y;

    double mag = std::sqrt(x * x + y * y);
    std::cout << "Magnitude: " << mag << std::endl;

    return 0;
}