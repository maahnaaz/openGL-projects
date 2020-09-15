
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

static int body=0,shoulder1 = 0 , shoulder2 =0 , elbow = 0 , hand1 = 0 , hand2 = 0 ;

void init(void)
{
    glClearColor(0.0 , 0.0 , 0.0 , 0.0);

}

void display(void)
{
    glClear( GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef (-1.0, 0.0, 0.0);
    glRotatef((GLfloat) shoulder1 , 0.0 , 0.0 , 1.0);
    glRotatef((GLfloat) shoulder2 , 0.0 , 1.0 , 0.0);
    glTranslatef(1.0 , 0.0 , 0.0);

    glPushMatrix();
    glScalef(1.0 , 4.0 , 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef (0.75, 0.0, 0.0);
    glRotatef ((GLfloat) body, 0.0, 0.0, 1.0);
    glTranslatef (1.8, 0.0, 0.0);

    glPushMatrix();
    glScalef(4.0 , 1.0 , 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef (1.8, 0.0, 0.0);
    glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
    glTranslatef (1.8, 0.0, 0.0);
    glPushMatrix();
    glScalef (4.0, 1.0, 1.0);
    glutWireCube (1.0);
    glPopMatrix();

    glTranslatef (1.3, 0.0, 0.0);
    glRotatef ((GLfloat) hand1 , 0.0, 0.0, 1.0);
    glRotatef ((GLfloat) hand2 , 1.0 , 0.0, 0.0);
    glTranslatef (1.3, 0.0, 0.0);
    glScalef (1.5, 1.0, 1.0);
    glutSolidCube (1.0);
    glPopMatrix();

    glPopMatrix();

   glutSwapBuffers();

}

void reshape( int w , int h)
{
    glViewport( 0 , 0 , (GLsizei) w , (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(110.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0 , 0.0, -10.0 , 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

}

void key(unsigned char key , int x , int y)
{
    switch(key)
    {
    case 'p' :
        body = (body + 5) % 360;
        glutPostRedisplay();
        break;
    case 'o' :
        body = (body - 5) % 360;
        glutPostRedisplay();
        break;
    case 's' :
        shoulder1 = (shoulder1 + 5) % 360;
        glutPostRedisplay();
        break;
    case 'd' :
        shoulder1 = (shoulder1 - 5) % 360;
        glutPostRedisplay();
        break;
    case 'f' :
        shoulder2 = (shoulder2 + 5) % 360;
        glutPostRedisplay();
        break;
    case 'g' :
        shoulder2 = (shoulder2 - 5) % 360;
        glutPostRedisplay();
        break;
    case 'w' :
        elbow = (elbow + 5) % 360;
        glutPostRedisplay();
        break;
    case 'e' :
        elbow = (elbow - 5) % 360;
        glutPostRedisplay();
        break;
    case 'x' :
        hand1 = (hand1 + 5) % 360;
        glutPostRedisplay();
        break;
    case 'c' :
        hand1 = (hand1 - 5) % 360;
        glutPostRedisplay();
        break;
    case 'v' :
        hand2 = (hand2 + 5) % 360;
        glutPostRedisplay();
        break;
    case 'b' :
        hand2 = (hand2 - 5) % 360;
        glutPostRedisplay();
        break;
    default:
        break;
    }

}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GL_DOUBLE | GL_RGB);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (200, 200);
    glutCreateWindow("Arm");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}
