#include <GL/gl.h>
#include <GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
///float triangle [3][3]= {{200, 300,400},{100,300,100},{1,1,1}};
float triangle [3][3];
float rectangle [3][4];





void reflection_triangle (void)
{

glClear (GL_COLOR_BUFFER_BIT);

glColor3f (1, 0, 0);

	glBegin(GL_TRIANGLES); ///Main triangle coordinates

	glVertex2f(triangle[0][0],triangle[1][0]);
	glVertex2f(triangle[0][1],triangle[1][1]);
	glVertex2f(triangle[0][2],triangle[1][2]);

	glEnd();///End triangle coordinates

	glColor3f(0,1,0);
glBegin(GL_TRIANGLES); ///Reflection triangle coordinates


	glVertex2f(triangle[0][0],triangle[1][0]*(-1));
	glVertex2f(triangle[0][1],triangle[1][1]*(-1));
	glVertex2f(triangle[0][2],triangle[1][2]*(-1));

	glEnd();///End triangle coordinates
	glColor3f(0,0,1);
glBegin(GL_TRIANGLES); ///Reflection triangle coordinates


	glVertex2f(triangle[0][0]*(-1),triangle[1][0]);
	glVertex2f(triangle[0][1]*(-1),triangle[1][1]);
	glVertex2f(triangle[0][2]*(-1),triangle[1][2]);

	glEnd();///End triangle coordinates

glFlush ();
}
void reflection_rectangle (void)
{

glClear (GL_COLOR_BUFFER_BIT);

glColor3f (1, 0, 0);

	glBegin(GL_POLYGON); ///Main triangle coordinates

	glVertex2f(rectangle[0][0],rectangle[1][0]);
	glVertex2f(rectangle[0][1],rectangle[1][1]);
	glVertex2f(rectangle[0][2],rectangle[1][2]);
	glVertex2f(rectangle[0][3],rectangle[1][3]);

	glEnd();///End triangle coordinates

	glColor3f(0,1,0);
glBegin(GL_POLYGON); ///Reflection triangle coordinates


	glVertex2f(rectangle[0][0],rectangle[1][0]*(-1));
	glVertex2f(rectangle[0][1],rectangle[1][1]*(-1));
	glVertex2f(rectangle[0][2],rectangle[1][2]*(-1));
	glVertex2f(rectangle[0][3],rectangle[1][3]*(-1));

	glEnd();///End triangle coordinates
	glColor3f(0,0,1);
glBegin(GL_POLYGON); ///Reflection triangle coordinates


	glVertex2f(rectangle[0][0]*(-1),rectangle[1][0]);
	glVertex2f(rectangle[0][1]*(-1),rectangle[1][1]);
	glVertex2f(rectangle[0][2]*(-1),rectangle[1][2]);
	glVertex2f(rectangle[0][3]*(-1),rectangle[1][3]);

	glEnd();///End triangle coordinates

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
cout<<" Chose your option:\n";
cout<<" 1. Reflection Triangle.\n";
cout<<" 2. Reflection Rectangle.\n";
cout<<" 3. reflection Pentagon.\n";
cout<<"Enter your option:";
cin>>i;
     switch (i)
     {
          case 1:
              cout<<"Enter triangle values:"<<endl;
              for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                cin>>triangle[i][j];
                    }
              }
               glutCreateWindow ("Triangle Reflection");
            glutDisplayFunc(reflection_triangle);
             break;
          case 2:
             cout<<"Enter rectangle values:"<<endl;
              for(int i=0;i<3;i++){
                    for(int j=0;j<4;j++){
                cin>>rectangle[i][j];
                    }
              }
               glutCreateWindow ("Rectangle Reflection");
            glutDisplayFunc(reflection_rectangle);
             break;
          case 3:

             break;
          default:
             cout<<"Wrong Option Input";
     }

myinit ();

glutMainLoop();

return 0;
}
