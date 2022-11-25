#include "main.hpp"
using namespace std;


int main(int argc, char **argv)
{
    int polynomial_degree = 0;
    int points_amount = 0;
    double *vector_x = nullptr;
    double *vector_y = nullptr;
    
    double **sums_powers_matrix = nullptr;
    double *right_part = nullptr;
    double *polynomial_coeffs = nullptr;
    
    Initialization( polynomial_degree, points_amount, vector_x, vector_y, sums_powers_matrix, right_part, polynomial_coeffs);
    ExecuteGaussMethod(sums_powers_matrix, right_part, polynomial_coeffs, polynomial_degree + 1);
    for (int i = 0; i < polynomial_degree + 1; ++i)
    {
        cout << "a" + to_string(i) + ": " << polynomial_coeffs[i] << endl;
    }
    
    cout << "Residual Variance: " << GetResidualVarianse(vector_x, vector_y, polynomial_coeffs, polynomial_degree, points_amount) << endl;
    
    PlottingGraph graph(argc, argv, polynomial_degree,  points_amount, polynomial_coeffs, vector_x, vector_y);
    delete [] vector_x;
    delete [] vector_y;
    for (int i = 0; i < polynomial_degree; ++i)
    {
        delete [] sums_powers_matrix[i];
    }
    delete [] sums_powers_matrix;
    delete [] right_part;
    delete [] polynomial_coeffs;
    return 0;
}

void Initialization(int &polynomial_degree, int &points_amount, double *&vector_x, double *& vector_y, double **&sums_powers_matrix, double *&right_part, double *&solution)
{
    cout << "Enter polynomial degree: ";
    cin >> polynomial_degree;
    
    cout << "Enter amount of points: ";
    cin >> points_amount;
    
    vector_x = new double[points_amount];
    vector_y = new double[points_amount];
    
    right_part = new double[polynomial_degree + 1]{0};
    solution = new double[polynomial_degree + 1];
    sums_powers_matrix = new double*[polynomial_degree + 1];
    for(int i = 0; i < polynomial_degree + 1; ++i)
    {
        sums_powers_matrix[i] = new double[polynomial_degree + 1]{0};
    }
    // // // // //
    cout << "Enter x: " << endl;
    for(int i = 0; i < points_amount; ++i)
    {
        cin >> vector_x[i];
    }
    
    cout << "Enter y: " << endl;
    for(int i = 0; i < points_amount; ++i)
    {
        cin >> vector_y[i];
    }

    for(int j = 0; j < polynomial_degree + 1; ++j)
    {
        for (int i = 0; i < polynomial_degree + 1; ++i)
        {
            sums_powers_matrix[j][i] = GetPowersSum(vector_x, vector_y,  i + j, points_amount, false);
        }
    }
    
    for(int i = 0; i < polynomial_degree + 1; ++i)
    {
        right_part[i] = GetPowersSum(vector_x, vector_y, i, points_amount, true);
    }
}
