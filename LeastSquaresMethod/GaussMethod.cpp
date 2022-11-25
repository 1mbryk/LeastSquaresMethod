#include "GaussMethod.hpp"

void ExecuteGaussMethod(double **matrix,double *free_member_column, double *solution, int size)
{
    TransformToTriangle(matrix, free_member_column, size);
    ReverseMotion(matrix, solution, free_member_column, size);
}

void TransformToTriangle(double **matrix, double *free_member_column, int size)
{
    double coeff = 0;
    for(int i = 0; i < size; ++i)
    {
        if(matrix[i][i]!=1 && matrix[i][i]!=0)
            DivideRow(matrix[i], free_member_column[i], matrix[i][i], size);
        // IsDepended????
        for(int j = i + 1; j < size; ++j)
        {
            coeff = ((0 - matrix[j][i]) / matrix[i][i]);
            SumRow(matrix[j], matrix[i], coeff, size);
            free_member_column[j] += free_member_column[i]*coeff;
        }
    }
    
}

void ReverseMotion(double **matrix,double *solution, double *free_member_column, int size)
{
    for(int i = size - 1; i >=0; --i)
    {
        solution[i] = free_member_column[i];
        for(int j = size - 1; j > i; --j)
        {
            solution[i] -= matrix[i][j] * solution[j];
        }
    }
}

void DivideRow(double *row, double &free_member, double num, int size)
{
    for(int i = 0; i < size; ++i)
    {
        row[i] /= num;
    }
    free_member/=num;
}

void SwapRow(double *&row1, double *&row2)
{
    auto temp = row1;
    row1 = row2;
    row2 = temp;
}

void SumRow(double *row1, const double *row2, double coeff, int size)
{
    for(int i = 0; i < size; ++i)
    {
        row1[i] += row2[i]*coeff;
    }
}
