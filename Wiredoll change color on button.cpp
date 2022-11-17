
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

int r1 = 100;
int g1 = 30;
int b1 = 90;

int r2 = 328;
int g2 = 80;
int b2 = 20;

int r3 = 20;
int g3 = 200;
int b3 = 71;
void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) {
    case 'q':/// rectangle color change
        r1 = 20;
        g1 = 200;
        b1 = 70;
        break;
    case 't':/// another rectangle color change
        r2 = 90;
        g2 = 200;
        b2 = 200;
        break;
    case 'a':/// triangle color change
        r3 = 300;
        g3 = 200;
        b3 = 20;
        break;
    case 'e':// close the screen
        exit(0);
        break;
    }
    glutPostRedisplay();
}




void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3ub(r1,g1,b1);
	glVertex3f(0.30f, 0.85f, 0.0f);
	glVertex3f(0.70f, 0.85f, 0.0f);
	glVertex3f(0.70f, 0.65f, 0.0f);
	glVertex3f(0.30f, 0.65f, 0.0f);

	glColor3ub(r2,g2,b2);
	glVertex3f(0.70f, 0.85f, 0.0f);
	glVertex3f(0.73f, 0.88f, 0.0f);
	glVertex3f(0.88f, 0.70f, 0.0f);
	glVertex3f(0.85f, 0.67f, 0.0f);

	glVertex3f(0.30f, 0.85f, 0.0f);
	glVertex3f(0.27f, 0.88f, 0.0f);
	glVertex3f(0.12f, 0.70f, 0.0f);
	glVertex3f(0.15f, 0.67f, 0.0f);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(r3,g3,b3);
	glVertex3f(0.40f, 0.90f, 0.0f);
	glVertex3f(0.60f, 0.90f, 0.0f);
	glVertex3f(0.50, 0.95f, 0.0f);

	glVertex3f(0.40f, 0.90f, 0.0f);
	glVertex3f(0.60f, 0.90f, 0.0f);
	glVertex3f(0.50, 0.85f, 0.0f);

	glVertex3f(0.35f, 0.40f, 0.0f);
	glVertex3f(0.495f, 0.40f, 0.0f);
	glVertex3f(0.495, 0.65f, 0.0f);

	glVertex3f(0.65f, 0.40f, 0.0f);
	glVertex3f(0.505f, 0.40f, 0.0f);
	glVertex3f(0.505, 0.65f, 0.0f);



	glEnd();


    float x,y;
    int i;
    GLfloat radius;
    int triangleAmount=60;
    GLfloat twicePi = 2.0*3.1416;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(138,139,21);
    x= 0.885,y=0.665,radius=0.03;

    glVertex2f(x,y);
    for(i=0;i<=triangleAmount;i++){
    glVertex2f(
        x+(radius*cos(i*twicePi/triangleAmount)),
        y+(radius*sin(i*twicePi/triangleAmount))
        );
    }

    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(138,139,21);
    x= 0.125,y=0.665,radius=0.03;

    glVertex2f(x,y);
    for(i=0;i<=triangleAmount;i++){
    glVertex2f(
        x+(radius*cos(i*twicePi/triangleAmount)),
        y+(radius*sin(i*twicePi/triangleAmount))
        );
    }

    glEnd();
        glBegin(GL_TRIANGLE_FAN);
    glColor3ub(138,139,21);
    x= 0.450,y=0.36,radius=0.03;

    glVertex2f(x,y);
    for(i=0;i<=triangleAmount;i++){
    glVertex2f(
        x+(radius*cos(i*twicePi/triangleAmount)),
        y+(radius*sin(i*twicePi/triangleAmount))
        );
    }

    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(138,139,21);
    x= 0.55,y=0.36,radius=0.03;

    glVertex2f(x,y);
    for(i=0;i<=triangleAmount;i++){
    glVertex2f(
        x+(radius*cos(i*twicePi/triangleAmount)),
        y+(radius*sin(i*twicePi/triangleAmount))
        );
    }

    glEnd();
    glColor3f (1.0, 1.0, 1.0);
        glRasterPos2f(0.40f, 0.75f); //define position on the screen
        char *string = "Designed by Monayem";

      while(*string){
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string++);
      }

glutSwapBuffers();
glFlush ();
}
void init (void)
{

glClearColor (0.0, 0.0, 0.0, 0.2);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -10.0, 10.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (600, 600);
glutInitWindowPosition (150, 150);
glutCreateWindow ("The Wire Doll");
init ();
glutDisplayFunc(display);
glutKeyboardFunc(GerenciaTeclado);
glutMainLoop();
return 0;
}
