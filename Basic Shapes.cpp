#include <GL/gl.h>
#include <GL/glut.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_POLYGON);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 10 * 3.1415926 * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}


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

	glColor3f (1, 0, 0);
 DrawCircle(150, -100, 80, 300);

    glLineWidth(2.5);

glColor3f (1, 0, 0);

	glBegin(GL_LINES); //Main rectangle coordinates

	glVertex2d(-200,200);
	glVertex2d(0,200);

	glEnd();//End

	glColor3f (1, 0, 0);

	glBegin(GL_TRIANGLES); //Main rectangle coordinates

	glVertex2f(40,200);
	glVertex2f(140,400);
	glVertex2f(240,200);

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
