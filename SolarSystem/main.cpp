
#include <GL/freeglut.h>

GLfloat year = 0 , day = 0 , moon = 0 , planet=0 ;
GLfloat rotationSpeed = 0.13;
GLfloat daysInYear = 365;
GLfloat moonAroundEarthRate = 2 * rotationSpeed;
GLfloat dayRate = 5.0 * rotationSpeed;
GLfloat yearRate = daysInYear / 360.0 * dayRate * rotationSpeed;
GLfloat planetrate=5.0*rotationSpeed;


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {50.0};

    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);

    glMaterialfv(GL_FRONT , GL_SPECULAR , mat_specular);
    glMaterialfv(GL_FRONT , GL_SHININESS , mat_shininess);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void display(void)
{

//sun
    glPushMatrix();
    glRotatef((GLfloat)year,0.0,1.0,0.0);
    glutSolidSphere( 0.75, 20 , 15);
    glRotatef((GLfloat) year , 0.0, 1.0, 0.0);
    glTranslatef( 3.0 , 0.0 ,0.0);
//earth
    glPushMatrix();
    glRotatef( (GLfloat) day , 0.0 , 1.0 , 0.0);
    glutSolidSphere( 0.3, 10, 8);
    glPopMatrix();
//moon
    glPushMatrix();

    glRotatef( (GLfloat) moon , 1.0 , 0.0 , 0.0);
    glTranslatef( 0.0 , 0.5 , 0.0);
    glRotatef(- (GLfloat) moon,0.0,1.0,0.0);
    glutSolidSphere( 0.05 , 8, 6);
    glPopMatrix();

    glPopMatrix();
     glutSwapBuffers();
    glFlush();


}
void display1(void){
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      glPushMatrix();
    glRotatef((GLfloat)year,0.0,1.0,0.0);
    glutSolidSphere( 0.5, 20 ,15);
    glRotatef((GLfloat) year , 0.0, 1.0, 0.0);
    glTranslatef( 1.5 , 0 ,1.0);
     glPushMatrix();
    glRotatef((GLfloat)planet,0.0,1.0,0.0);
    glutSolidSphere( 0.2, 10 , 8);
    glPopMatrix();
    glPopMatrix();
}


void reshape(int w , int h)
{
    glViewport(0, 0, (GLsizei) w ,(GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 60.0 , (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt( 0.0 , 0.0, 10.0 , 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

}

void idle(void)
{

    day += dayRate;
    year += yearRate;
    moon += moonAroundEarthRate;
    planet +=planetrate;
    display();
    display1();

}
int main ( int argc , char** argv)
{
    glutInit(&argc , argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize( 600 , 600);
    glutInitWindowPosition( 200 , 200);
    glutCreateWindow("Solar System");
    init();
    glutDisplayFunc(display);
    glutDisplayFunc(display1);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainLoop();

    return 0;
}
