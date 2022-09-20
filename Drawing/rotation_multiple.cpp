#include <GL/gl.h>
#include <GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
///float triangle [3][3]= {{200, 300,400},{100,300,100},{1,1,1}};
float triangle [3][3];
float rectangle [3][4];

float rot_mat[3][3]= {{0},{0},{0}};
float result[3][3]= {{0},{0},{0}};
float rec_result[3][4]= {{0},{0},{0}};
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
void rec_multiply (){

 int i, j, l;
 for( i=0;i<3;i++)
 {
     for(j=0;j<4;j++)
     {
         rec_result[i][j]=0;
         for(l=0;l<3;l++)
          rec_result[i][j]=rec_result[i][j]+rot_mat[i][l]*rectangle[l][j];
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
void rec_rrotate(float m, float n)
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
    rec_multiply();
}


void rotation_triangle (void)
{

glClear (GL_COLOR_BUFFER_BIT);

glColor3f (1, 0, 0);

	glBegin(GL_TRIANGLES);

	///Main Triangle
	glVertex2f(triangle[0][0],triangle[1][0]);
	glVertex2f(triangle[0][1],triangle[1][1]);
	glVertex2f(triangle[0][2],triangle[1][2]);

	glEnd();///End triangle coordinates
	rrotate(0,0);
	glColor3f(0,1,0);
glBegin(GL_TRIANGLES); ///Rotate triangle coordinates

	glVertex2f(result[0][0],result[1][0]);
	glVertex2f(result[0][1],result[1][1]);
	glVertex2f(result[0][2],result[1][2]);

	glEnd();///End triangle coordinates

glFlush ();
}
void rotation_rectangle (void)
{

glClear (GL_COLOR_BUFFER_BIT);

glColor3f (1, 0, 0);

	glBegin(GL_POLYGON); ///Main triangle coordinates

	glVertex2f(rectangle[0][0],rectangle[1][0]);
	glVertex2f(rectangle[0][1],rectangle[1][1]);
	glVertex2f(rectangle[0][2],rectangle[1][2]);
	glVertex2f(rectangle[0][3],rectangle[1][3]);

	glEnd();///End triangle coordinates
rec_rrotate(0,0);
	glColor3f(0,1,0);
glBegin(GL_POLYGON); ///Rotate triangle coordinates

	glVertex2f(rec_result[0][0],rec_result[1][0]);
	glVertex2f(rec_result[0][1],rec_result[1][1]);
	glVertex2f(rec_result[0][2],rec_result[1][2]);
	glVertex2f(rec_result[0][3],rec_result[1][3]);

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
cout<<" 1. Rotation Triangle.\n";
cout<<" 2. Rotation Rectangle.\n";
cout<<" 3. Rotation Pentagon.\n";
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
              cout<<"Enter the rotation angle:";
              float t_angle;
              cin>>t_angle;
              theta= ((3.1416/180)*t_angle);
               glutCreateWindow ("Triangle Rotation");
            glutDisplayFunc(rotation_triangle);
             break;
          case 2:
             cout<<"Enter rectangle values:"<<endl;
              for(int i=0;i<3;i++){
                    for(int j=0;j<4;j++){
                cin>>rectangle[i][j];
                    }

              }
              cout<<"Enter the rotation angle:";
              cin>>t_angle;
              theta= ((3.1416/180)*t_angle);
               glutCreateWindow ("Rectangle Rotation");
            glutDisplayFunc(rotation_rectangle);

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
