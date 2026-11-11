#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

int count_lines(std::string inputfile) {
    std::ifstream data_file(inputfile);
    std::string line;
    int count = 0;
    while (std::getline(data_file, line)) {
        ++count;
    }
    return count;
}

int print_data(std::string inputfile){
    //function to read in a file and print out its contents
    std::ifstream data_file(inputfile);  //read in file 
    
    // check that file has been opened succesfully
    if (!data_file.is_open()) {
        std::cout << "Could not open " << inputfile << std::endl;
        return 1;
    }

    else{
        std::cout << inputfile << " opened successfully! :)" << std::endl;
    }

    int file_length;
    file_length = count_lines(inputfile);

    int N;
    std::cout << "How many lines do you want to print? ";
    std::cin >> N;

    if (N > file_length) {
        std::cout << "Warning: requested " << N << " lines but the file only has "
                  << file_length << ". Printing 5 lines of the file instead." << std::endl;
        N = 5;
    }
    
    std::string line;
    std::getline(data_file, line);      // skip header "x,y"

    int count = 0;
    while (count < N && std::getline(data_file, line)) {
        std::cout << line << std::endl;
        ++count;
    }
    return 0;
}

int store_data(std::string inputfile, std::vector<double>& xs, std::vector<double>& ys){
    //stores data from a file into vectors, and then prints these for checking
    std::ifstream data_file(inputfile);  //read in file 
    std::string line;

    std::getline(data_file, line);      // skip header "x,y"

    //read file contents in variables x and y
    std::string x, y;
    while (std::getline(data_file, x, ',') && std::getline(data_file, y)) {
        xs.push_back(std::stod(x));
        ys.push_back(std::stod(y));
    }

    std::cout << "x values in the file are: " << std::endl;
    for (double val : xs) {
        std::cout << val << std::endl;
    }

    std::cout << "y values in the file are: " << std::endl;
    for (double val : ys) {
        std::cout << val << std::endl;
    }

    return 0;

}

int calc_2D_magnitude(const std::vector<double>& xs, const std::vector<double>& ys, std::vector<double> mags) {
    //returns the magnitudes of vectors given two input arrays of x,y components

    for (int i = 0; i < xs.size(); ++i) {
        mags.push_back(std::sqrt(xs[i] * xs[i] + ys[i] * ys[i]));
    }

    std::cout << "Magnitude of vectors are: " << std::endl;
    for (double m : mags) {
        std::cout << m << std::endl;
    }

    return 0;
}

int main(){
    std::string inputfile = "input2D_float.txt"; 
    std::vector<double> xs;
    std::vector<double> ys;
    std::vector<double> mags;

    print_data(inputfile);
    store_data(inputfile, xs, ys);
    calc_2D_magnitude(xs, ys, mags);

    return 0;
}