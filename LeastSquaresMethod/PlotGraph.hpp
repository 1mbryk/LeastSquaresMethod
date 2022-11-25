#pragma once
#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <cstdlib>
#include <cmath>
#include "main.hpp"
using namespace std;

class PlottingGraph
{
private:
    const static int X_COORD = 100;
    const static int Y_COORD = 100;
    constexpr static double ITERATIONS = 0.00001;
    
    const static int X_OFF = X_COORD / 2;
    const static int Y_OFF = Y_COORD / 2;
    
    static int polynomial_degree;
    static int points_amount;
    static double *coeffs;
    static double *vector_x;
    static double *vector_y;
    
    static int argc;
    static char** argv;
    
    static void drawGrid(const double SERIF_OFFSET, const double SERIF_DISTANCE);
    static void drawFunc();
    static double func(const double arg);
    static void display();
public:
    PlottingGraph();
    PlottingGraph(int argc, char **argv, int polynomial_degree, int points_amount, double *coeffs, double* vector_x, double *vector_y);
    
    void static startPlotting();
    ~PlottingGraph();
};
