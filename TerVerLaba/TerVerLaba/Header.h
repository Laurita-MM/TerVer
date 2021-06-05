#pragma once
#include <cmath>
#include <map>

double geom_probability(double x);
double distribution_function(double x, std::map <int, int> mp);
double th_func(double x);
double distr_func(double x, double* w, int size);