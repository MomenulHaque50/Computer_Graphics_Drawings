#include <GL/gl.h>
#include <GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
float triangle [3][3]= {{200, 300,400},{100,300,100},{1,1,1}};
float rot_mat[3][3]= {{0},{0},{0}};
float result[3][3]= {{0},{0},{0}};

float tx, ty;
float sx, sy;
float theta;


void multiply (){

 int i, j, l;
 for( i=0;i<3;i++)
 {
     for(j=0;j<3;j++)
     {
         result[i][j]=0;
         for(l=0;l<3;l++)
         result[i][j]=result[i][j]+rot_mat[i][l]*triangle[l][j];
     }
 }

}

void rrotate(float m, float n)
{
    rot_mat[0][0]=cos(theta);
    rot_mat[0][1]=-sin(theta);
    rot_mat[0][2]=m;
    rot_mat[1][0]=sin(theta);
    rot_mat[1][1]=cos(theta);
    rot_mat[1][2]=n;
    rot_mat[2][0]=0;
    rot_mat[2][1]=0;
    rot_mat[2][0]=1;
    multiply();
}

void rotation(void)
{

glClear (GL_COLOR_BUFFER_BIT);

glColor3f (1, 0, 0);

	glBegin(GL_TRIANGLES);

	//Main Triangle
	glVertex2f(triangle[0][0],triangle[1][0]);
	glVertex2f(triangle[0][1],triangle[1][1]);
	glVertex2f(triangle[0][2],triangle[1][2]);

	glEnd();//End triangle coordinates

	rrotate(0,0);
	glColor3f(0,1,0);
glBegin(GL_TRIANGLES); //Rotate triangle coordinates

	glVertex2f(result[0][0],result[1][0]);
	glVertex2f(result[0][1],result[1][1]);
	glVertex2f(result[0][2],result[1][2]);

	glEnd();//End triangle coordinates

glFlush ();
}
void translation(void)
{

glClear (GL_COLOR_BUFFER_BIT);

glColor3f (1, 0, 0);

	glBegin(GL_TRIANGLES); //Main triangle coordinates

	glVertex2f(triangle[0][0],triangle[1][0]);
	glVertex2f(triangle[0][1],triangle[1][1]);
	glVertex2f(triangle[0][2],triangle[1][2]);

	glEnd();//End triangle coordinates

	glColor3f(0,1,0);
glBegin(GL_TRIANGLES); //Translation triangle coordinates


	glVertex2f(triangle[0][0]+tx,triangle[1][0]+ty);
	glVertex2f(triangle[0][1]+tx,triangle[1][1]+ty);
	glVertex2f(triangle[0][2]+tx,triangle[1][2]+ty);

	glEnd();//End triangle coordinates

glFlush ();
}
void reflection(void)
{

glClear (GL_COLOR_BUFFER_BIT);

glColor3f (1, 0, 0);

	glBegin(GL_TRIANGLES); //Begin triangle coordinates

	glVertex2f(triangle[0][0],triangle[1][0]);
	glVertex2f(triangle[0][1],triangle[1][1]);
	glVertex2f(triangle[0][2],triangle[1][2]);

	glEnd();//End triangle coordinates

	glColor3f(0,1,0);
glBegin(GL_TRIANGLES); //Reflection triangle coordinates


	glVertex2f(triangle[0][0],triangle[1][0]*(-1));
	glVertex2f(triangle[0][1],triangle[1][1]*(-1));
	glVertex2f(triangle[0][2],triangle[1][2]*(-1));


	glEnd();//End triangle coordinates

glFlush ();
}
void shearing(void)
{

glClear (GL_COLOR_BUFFER_BIT);

glColor3f (1, 0, 0);

	glBegin(GL_POLYGON); //Main rectangle coordinates

	glVertex2f(0,0);
	glVertex2f(0,100);
	glVertex2f(100,100);
	glVertex2f(100,0);

	glEnd();//End rectangle coordinates

	glColor3f (0, 1, 0);

	glBegin(GL_POLYGON); //Shearing rectangle coordinates


	glVertex2f(110,110);
	glVertex2f(110+(210*0.5),210);
	glVertex2f(210+(210*0.5),210);
	glVertex2f(210,110);



	glEnd();//End rectangle coordinates


glFlush ();
}

void scaling(void)
{

glClear (GL_COLOR_BUFFER_BIT);

glColor3f (1, 0, 0);

	glBegin(GL_POLYGON); //Main rectangle coordinates

	glVertex2f(0,0);
	glVertex2f(0,100);
	glVertex2f(100,100);
	glVertex2f(100,0);



	glEnd();//End rectangle coordinates

	glColor3f (0, 1, 0);

	glBegin(GL_POLYGON); //Scaling rectangle coordinates

	glVertex2f(100*2,100*2);
	glVertex2f(100*2,200*2);
	glVertex2f(200*2,200*2);
	glVertex2f(200*2,100*2);



	glEnd();//End rectangle coordinates


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
cout<<" 1. Translation.\n";
cout<<" 2. Rotation.\n";
cout<<" 3. Scaling.\n";
cout<<" 4. Shearing.\n";
cout<<" 5. Reflection.\n";
cout<<"Enter your option:";
cin>>i;
     switch (i)
     {
          case 1:
              tx=100;
               ty=100;
               glutCreateWindow ("Triangle Translation");
            glutDisplayFunc(translation);
             break;
          case 2:
              theta= ((3.1416/180)*90);
              glutCreateWindow ("Triangle Rotation");
            glutDisplayFunc(rotation);
             break;
          case 3:
               glutCreateWindow ("Triangle Scaling");
            glutDisplayFunc(scaling);
             break;
          case 4:
             glutCreateWindow ("Triangle Shearing");
            glutDisplayFunc(shearing);
             break;
              case 5:
                        glutCreateWindow ("Triangle Reflection");
            glutDisplayFunc(reflection);
             break;
          default:
             cout<<"Wrong Option Input";
     }

myinit ();
glutMainLoop();
return 0;
}
