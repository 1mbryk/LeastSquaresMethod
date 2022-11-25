#pragma once
#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <cstdlib>
#include <cmath>
#include "main.hpp"
using namespace std;

void drawgrid(float SERIF_OFFSET, float SERIF_DISTANCE);
void drawfunc();
void display();
void PlotGraph(int argc, char **argv, int polynomial_degree, double *coeffs, double *vector_x, double *vector_y, int points_amount);
double func(double x);
