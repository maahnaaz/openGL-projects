
#include <GL/freeglut.h>
#include <math.h>

static double x = 0.00, y = 0.00, z = 0.00;
static double s = 0 ;
void calc(double );
double Px(double );
double Py(double );
double Pz(double );

GLfloat controlpoints[4][3] = {
        { -0.08, -0.09, 0.00}, { -0.1, 0.08, 0.00},
        {-0.05, -0.07, 0.00}, {0.08, 0.07, 0.00}
};

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    calc(s);
    glTranslatef(x, y, z);

    glColor3f(1.0 , 0.0, 0.0);
    glutSolidCube(0.25);

    glFlush();
    glutSwapBuffers();
}

void reshape(int w , int h)
{
    glViewport(0, 0, (GLsizei) w ,(GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 60.0 , (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt( -7.0 , -7.0, -12.0 , 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


}

double Find( double x)//arc length
{
    double b = 0;
    double a[100];
    a[0] = 0.00;
    if( x < a[0] || x == a[0])
        {
            return 0.00;
        }
    for( int  i = 1 ; i < 100 ; i++ )
    {
        b += 0.01;
        a[i] = a[i-1] + sqrt(pow((Px(i)-Px(i-1)),2)+pow((Py(i)-Py(i-1)),2)+pow((Pz(i)-Pz(i-1)),2));
        if( x < a[i] || x == a[i])
        {
            return b;
        }
    }
}

void calc( double u)//calculating new position
{
    x = Px(u);
    y = Py(u);
    z = Pz(u);
}
double Px(double t)
{//(1-t)3 P1 + 3t(1-t)2 P2 + 3t2(1-t) P3 + t3 P4
    double answer = pow(1-t,3)*controlpoints[0][0] + 3*t*pow(1-t,2)*controlpoints[1][0] + 3*pow(t,2)*(1-t)*controlpoints[2][0] + pow(t,3)*controlpoints[3][0];
    return answer;
}

double Py(double t)
{
    double answer = pow(1-t,3)*controlpoints[0][1] + 3*t*pow(1-t,2)*controlpoints[1][1] + 3*pow(t,2)*(1-t)*controlpoints[2][1] + pow(t,3)*controlpoints[3][1];
    return answer;
}


double Pz(double t)
{
    double answer = pow(1-t,3)*controlpoints[0][2] + 3*t*pow(1-t,2)*controlpoints[1][2] + 3*pow(t,2)*(1-t)*controlpoints[2][2] + pow(t,3)*controlpoints[3][2];
    return answer;
}


void timer(int value)//linear speed
{
    calc(Find(s));
    s+=0.01;
   /* int t= - 180;
    s=sin(t-180/2);
    t+=0.01;
    //another speed function
    */
    //s+=0.00 //uniform speed
    glutTimerFunc(20, timer, value);
    glutPostRedisplay();

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Movement");

    timer(0);
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
