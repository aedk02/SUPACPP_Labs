#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include "CustomFunctions.h"


int main() {
    std::string inputfile = "input2D_float.txt";

    int choice;
    std::cout << "Which function would you like to use?\n"
              << "1 - Print N lines of data\n"
              << "2 - Print the magnitude of every data point\n"
              << "Choice: ";
    std::cin >> choice;

    if (choice == 1) {
        print_data(inputfile);
    } else if (choice == 2) {
        std::vector<double> xs, ys, mags;
        store_data(inputfile, xs, ys);
        calc_2D_magnitude(xs, ys, mags);
    } else {
        std::cout << "Invalid choice." << std::endl;
    }

    line_fit(inputfile);

    return 0;
}