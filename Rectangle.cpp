#include <GL/gl.h>
#include <GL/glut.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void drawing(void)
{

glClear (GL_COLOR_BUFFER_BIT);

glColor3f (1, 0, 0);

	glBegin(GL_POLYGON); //Main rectangle coordinates

	glVertex2f(-200,-200);
	glVertex2f(-200,0);
	glVertex2f(0,0);
	glVertex2f(0,-200);



	glEnd();//End


glFlush ();
}

void myinit (void)
{

glClearColor (0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-500, 500, -500, 500);
glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{

int i;
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (0,0);


 glutCreateWindow ("Drawing");
 glutDisplayFunc(drawing);


myinit ();
glutMainLoop();
return 0;
}
