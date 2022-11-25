#pragma once
#include "main.hpp"

void ExecuteGaussMethod(double **matrix, double *free_member_column, double *solution, int size);
void TransformToTriangle(double **matrix, double *free_member_column, int size);
void DivideRow(double *row, double &free_member, double num, int size);
void SwapRow(double *&row1, double *&row2);
void SumRow(double *row1, const double *row2,  double coeff, int size);
void ReverseMotion(double **matrix,double *solution, double *free_member_column, int size);
