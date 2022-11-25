#include "PlotGraph.hpp"

int PlottingGraph::polynomial_degree = 0;
int PlottingGraph::points_amount = 0;
int PlottingGraph::argc = 0;
char** PlottingGraph::argv = nullptr;
double *PlottingGraph::coeffs = nullptr;
double *PlottingGraph::vector_x = nullptr;
double *PlottingGraph::vector_y = nullptr;

PlottingGraph::PlottingGraph()
{
    PlottingGraph::polynomial_degree = 0;
    PlottingGraph::points_amount = 0;
    PlottingGraph::coeffs = nullptr;
    PlottingGraph::vector_x = nullptr;
    PlottingGraph::vector_y = nullptr;
    PlottingGraph::argc = 0;
    PlottingGraph::argv = nullptr;
}

PlottingGraph::PlottingGraph(int argc, char **argv, int polynomial_degree, int points_amount, double *coeffs, double* vector_x, double *vector_y)
{
    PlottingGraph::argc = argc;
    PlottingGraph::argv = argv;
    PlottingGraph::polynomial_degree = polynomial_degree;
    PlottingGraph::points_amount = points_amount;

    PlottingGraph::coeffs = new double[polynomial_degree + 1];
    copy(coeffs, coeffs + polynomial_degree + 1, PlottingGraph::coeffs);

    PlottingGraph::vector_x = new double[points_amount];
    copy(vector_x, vector_x + points_amount, PlottingGraph::vector_x);

    PlottingGraph::vector_y = new double[points_amount];
    copy(vector_y, vector_y + points_amount, this->vector_y);

    

    startPlotting();

}

void PlottingGraph::startPlotting()
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(500, 200);
    glutCreateWindow("PLOTS");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //пространство координат
    glOrtho(0.0, X_COORD, 0.0, Y_COORD, -1.0, 1.0);

    glutDisplayFunc(PlottingGraph::display);
    glutMainLoop();
}

void PlottingGraph::drawGrid(const double SERIF_OFFSET, const double SERIF_DISTANCE)
{
    glBegin(GL_LINES);

    glColor3d(0.0, 0.0, 0.0);

    glVertex2d(0.0, Y_COORD/2); // draw horixontal axis
    glVertex2d(X_COORD, Y_COORD/2);


    for (int i = X_COORD / 2; i < X_COORD; i+= SERIF_DISTANCE) // draw serifs on oX axis
    {
        glVertex2d(i, Y_COORD / 2); // on positive direction
        glVertex2d(i, Y_COORD/ 2 + SERIF_OFFSET);

        glVertex2d(X_COORD - i, Y_COORD /2); // on negative
        glVertex2d(X_COORD - i, Y_COORD / 2 + SERIF_OFFSET);
    }

    glVertex2d(X_COORD / 2, Y_COORD); // draw vecrtical axis
    glVertex2d(X_COORD / 2, 0.0);

    for (int i = Y_COORD/2; i < Y_COORD; i+= SERIF_DISTANCE)
    {
        glVertex2d(X_COORD / 2, i);
        glVertex2d(X_COORD / 2, i + SERIF_OFFSET);

        glVertex2d(X_COORD / 2, Y_COORD - i);
        glVertex2d(Y_COORD / 2 + SERIF_OFFSET, Y_COORD - i);


    }
    glEnd();

}

void PlottingGraph::drawFunc()
{
    glPointSize(5.0);
    glBegin(GL_POINTS);
    {
        double y = 0;
        glColor3d(0.8, 0.0, 0.8);
        for(double x = -X_COORD * 2; x < X_COORD*2; x += ITERATIONS)
        {
            y = func(x) / 10;
            glVertex2d(X_OFF + x, Y_OFF + y);
        }

    }
    glEnd();

    glPointSize(10.0);
    glColor3d(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    {
        for (int i = 0; i < points_amount; ++i)
        {
            glVertex2d(X_OFF + vector_x[i],Y_OFF + vector_y[i]/10);
        }
    }
    glEnd();
        
}

void PlottingGraph::display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid(0.3, 5);
    drawFunc();
    glutSwapBuffers();
    glFlush();
}

double PlottingGraph::func(const double arg)
{
    double result = 0;
    double check[11];
    copy(coeffs, coeffs + 11, check);
        for(int i = 0; i <= polynomial_degree; ++i)
        {
            result += coeffs[i] * pow(arg,i);
        }
        return result;
}

PlottingGraph::~PlottingGraph()
{
    delete[] PlottingGraph::coeffs;
    delete[] PlottingGraph::vector_x;
    delete[] PlottingGraph::vector_y;

    PlottingGraph::coeffs = nullptr;
    PlottingGraph::vector_x = nullptr;
    PlottingGraph::vector_y = nullptr;
}
