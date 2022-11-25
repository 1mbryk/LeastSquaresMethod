#pragma once
#include "main.hpp"
#include <cmath>

double GetPowersSum(double* vector_x, double *vector_y, int power, int points_amount, bool is_multiplic);
double GetResidualVarianse(double*vector_x, double *vector_y, double *polynomial_coeffs, int polynomial_degree, int points_amount);
