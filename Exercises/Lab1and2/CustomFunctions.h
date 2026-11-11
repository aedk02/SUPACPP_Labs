#pragma once

#include <string>
#include <vector>


int count_lines(std::string inputfile);

int print_data(std::string inputfile);

int store_data(std::string inputfile, std::vector<double>& xs, std::vector<double>& ys);

int calc_2D_magnitude(const std::vector<double>& xs, const std::vector<double>& ys, std::vector<double> mags);

void line_fit(std::string inputfile);