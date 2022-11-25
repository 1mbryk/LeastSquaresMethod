#include "PlotGraph.hpp"

const int X_COORD = 100; // X - размерность ] должны
const int Y_COORD = 100; // Y - размерность ] быть равными
const double ITERATIONS = 0.00001;// прорисовка графика (чем меньше тем лучше)

const int x_off = X_COORD / 2;// начало
const int y_off = Y_COORD / 2;// оси координат
int stat_polynomial_degree;
double* stat_coeffs;
double *stat_vector_x;
double *stat_vector_y;
int stat_points_amount;
//исходная функция
void PlotGraph(int argc, char **argv, int polynomial_degree, double *coeffs, double *vector_x, double *vector_y, int points_amount)
{
    
    stat_polynomial_degree = polynomial_degree;
    stat_coeffs = coeffs;
    stat_vector_x = vector_x;
    stat_vector_y = vector_y;
    stat_points_amount = points_amount;
    
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
   
    glutDisplayFunc(display);
    glutMainLoop();
}

double func(double x)
{
    double result = 0;
    for(int i = 0; i <= stat_polynomial_degree; ++i)
    {
        result += stat_coeffs[i]*pow(x,i);
    }
    return result;
}

void drawgrid(float SERIF_OFFSET, float SERIF_DISTANCE)
{
    glBegin(GL_LINES);
        //задаем цвета
        glColor3f(0.0, 0.0, 0.0);

        //рисуем координатные оси
        //горизонталь
        glVertex2f(0.0, Y_COORD / 2);
        glVertex2f(X_COORD, Y_COORD / 2);
        //засечки по горизонтали
        int p = X_COORD / 2;
        for(int i = X_COORD / 2; i < X_COORD; i += SERIF_DISTANCE, p -= SERIF_DISTANCE) {
            glVertex2f(i, Y_COORD / 2);
            glVertex2f(i, Y_COORD / 2 + SERIF_OFFSET);

            glVertex2f(p, Y_COORD / 2);
            glVertex2f(p, Y_COORD / 2 + SERIF_OFFSET);
        }
        //вертикаль
        int t = Y_COORD / 2;
        glVertex2f(X_COORD / 2, Y_COORD);
        glVertex2f(X_COORD / 2, 0.0);
        //засечки по вертикали
        for(int i = Y_COORD / 2; i < Y_COORD; i += SERIF_DISTANCE, t -= SERIF_DISTANCE) {
            glVertex2f(X_COORD / 2, i);
            glVertex2f(Y_COORD / 2 + SERIF_OFFSET, i);

            glVertex2f(X_COORD / 2, t);
            glVertex2f(Y_COORD / 2 + SERIF_OFFSET, t);
        }
    glEnd();
}

void drawfunc()
{
    //рисуем график
    glPointSize(5.0);
    glBegin(GL_POINTS);
        float j = 0;
        glColor3f(0.8, 0.0, 0.8);
        for(float x = -X_COORD * 2; x < X_COORD * 2; x += ITERATIONS)
        {
            //перерасчитываем координаты
//            j = expr;
            j = func(x)/10;
            glVertex2f(x_off + x, y_off + j);//не убирать x и y!! это оффсет по осям!
        }
    double y = 0;
    double x = 0;
    glEnd();
    glPointSize(10.0);
    glColor3d(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < stat_points_amount; ++i)
    {
        x = stat_vector_x[i];
        y = stat_vector_y[i];
        glVertex2d(x_off + x, y_off + y/10);
    }
    glEnd();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    cout << "Osnovnie toshki po vashemu grafiku: \n";

    drawgrid(0.3, 5);
    drawfunc();

    glutSwapBuffers();

    glFlush();
}

