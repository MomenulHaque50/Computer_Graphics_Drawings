#include<windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <GL/gl.h>

#include <GL/glut.h>
#include <math.h>
float  counter=0.026;
float angle = 0.0;
float b=0.0;
float c=0.0;
void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) {
    case 'm':/// rectangle color change
        b=0.00003;
        c=0.2;
         glutPostRedisplay();
        break;
  case 's':/// rectangle color change
        b=0.0;
        c=0.0;
         glutPostRedisplay();
        break;
    case 'e':// close the screen
        exit(0);
        break;
    }
    glutPostRedisplay();
}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      // Clear The Screen And The Depth Buffer
    glLoadIdentity();
glBegin(GL_LINES);
glColor3ub(238,139,21);
glVertex3f(-10.0f, 0.1f, 0.0f);
glVertex3f(10.0f, 0.1f, 0.0f);
glEnd();
counter=counter+b;
glTranslated(counter,0.024,0.0);

glBegin(GL_QUADS);
glColor3ub(300,140,20);
glVertex3f(0.20f, 0.15f, 0.0f);
glVertex3f(0.40f, 0.15f, 0.0f);
glVertex3f(0.40f, 0.55f, 0.0f);
glVertex3f(0.20f, 0.55f, 0.0f);


glBegin(GL_QUADS);
glColor3ub(100,100,100);
glTranslated(counter,0.0,0.0);
glVertex3f(0.25f, 0.40f, 0.0f);
glVertex3f(0.35f, 0.40f, 0.0f);
glVertex3f(0.35f, 0.50f, 0.0f);
glVertex3f(0.25f, 0.50f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(300,140,20);
glTranslated(counter,0.0,0.0);
glVertex3f(0.40f, 0.15f, 0.0f);
glVertex3f(0.80f, 0.15f, 0.0f);
glVertex3f(0.80f, 0.40f, 0.0f);
glVertex3f(0.40f, 0.40f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(500,250,125);
glTranslated(counter,0.0,0.0);
glVertex3f(0.65f, 0.40f, 0.0f);
glVertex3f(0.75f, 0.40f, 0.0f);
glVertex3f(0.75f, 0.50f, 0.0f);
glVertex3f(0.65f, 0.50f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(500,250,125);
glTranslated(counter,0.0,0.0);
glVertex3f(0.15f, 0.55f, 0.0f);
glVertex3f(0.45f, 0.55f, 0.0f);
glVertex3f(0.45f, 0.60f, 0.0f);
glVertex3f(0.15f, 0.60f, 0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(238,139,21);
glTranslated(counter,0.0,0.0);
glVertex3f(0.66f, 0.50f, 0.0f);
glVertex3f(0.74f, 0.50f, 0.0f);
glVertex3f(0.73f, 0.55f, 0.0f);
glVertex3f(0.67f, 0.55f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(238,139,21);
glTranslated(counter,0.0,0.0);
glVertex3f(0.80f, 0.20f, 0.0f);
glVertex3f(0.90f, 0.20f, 0.0f);
glVertex3f(0.80, 0.30f, 0.0f);
glEnd();


    float x,y;
    int i;
    GLfloat radius;
    int triangleAmount=40;
    GLfloat twicePi = 2.0*3.1416;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238,139,21);
    glRotated(angle,0,0,1);
    x= 0.30,y=0.15,radius=0.06;

    glVertex2f(x,y);
    for(i=0;i<=triangleAmount;i++){
    glVertex2f(
        x+(radius*cos(i*twicePi/triangleAmount)),
        y+(radius*sin(i*twicePi/triangleAmount))
        );
    }
       angle-=c;
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238,139,21);
     glRotated(angle,0,0,1);
    x= 0.45,y=0.15,radius=0.06;

    glVertex2f(x,y);
    for(i=0;i<=triangleAmount;i++){
    glVertex2f(
        x+(radius*cos(i*twicePi/triangleAmount)),
        y+(radius*sin(i*twicePi/triangleAmount))
        );
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238,139,21);
    x= 0.70,y=0.15,radius=0.06;

    glVertex2f(x,y);
    for(i=0;i<=triangleAmount;i++){
    glVertex2f(
        x+(radius*cos(i*twicePi/triangleAmount)),
        y+(radius*sin(i*twicePi/triangleAmount))
        );
    }
    angle-=0.2;
    glEnd();
glColor3f (1.0, 1.0, 1.0);
        glRasterPos2f(0.40f, 0.25f); //define position on the screen
        char *string = "Monayem";

      while(*string){
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string++);
      }
glutSwapBuffers();
glFlush ();
}
void init (void)
{

glClearColor (0.0, 0.0, 0.0, 0.0);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -10.0, 10.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (600, 600);
glutInitWindowPosition (100, 100);
glutCreateWindow ("A Running Train");
init ();
glutDisplayFunc(display);
glutKeyboardFunc(GerenciaTeclado);
glutIdleFunc(display);
glutMainLoop();
return 0;
}
