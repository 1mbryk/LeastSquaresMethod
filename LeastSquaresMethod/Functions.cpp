#include "Functions.hpp"


double GetPowersSum(double *vector_x, double *vector_y, int power, int points_amount, bool is_multiplic)
{
    double result = 0;
    double temp_result=0;
    for(int i = 0 ; i < points_amount; ++i)
    {
        temp_result = pow(vector_x[i], power);
        if(is_multiplic)
            temp_result *= vector_y[i];
        result += temp_result;
    }
    return result;
}

double GetResidualVarianse(double*vector_x, double *vector_y, double *polynomial_coeffs, int polynomial_degree, int points_amount)
{
    double temp_result=0;
    double result=0;
    for(int i = 0; i < points_amount; ++i)
    {
        temp_result = vector_y[i];
        for(int j = 0; j < polynomial_degree; ++j)
        {
            temp_result -= polynomial_coeffs[j] * pow(vector_x[i], j);
        }
        result += temp_result;
    }
    return abs(result) * sqrt(1 / points_amount - polynomial_degree - 1);
}


