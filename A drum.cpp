#include<windows.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<string.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#define tPi 6.2832
#define SPEED 10.0
int play = 0;
float a =0.0;
void dispFilledelipse(GLfloat x, GLfloat y, GLfloat xcenter, GLfloat ycenter)
{

    int trN = 100;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= trN; i++)
    {
        glVertex2f(
            x + ((xcenter)*cos(i * tPi / trN)),
            y + ((ycenter)*sin(i * tPi / trN)));
    }
    glEnd();
}

void drawstring(int x, int y, char *s)
{
    char *c;
    glRasterPos2i(x, y);
    for (c = s; *c != '\0'; *c++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(0, 600, 600, 0);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,1);
    glPushMatrix();
    glTranslatef(225.7968127490041f,213.09760956175307f,0.0f);
    glRotatef(0,0,0,1);
    dispFilledelipse(0,0,91.02205041221248,19.27931837008393);
    glPopMatrix();

    glColor3f(0.87,0.15,0.92);
    glPushMatrix();
    glTranslatef(226.79282868525894f,289.31719458214513f,0.0f);
    glRotatef(0,0,0,1);
    dispFilledelipse(0,0,91.02205041221254,14.817498954209146);

    glPopMatrix();
    glColor3f(0.37,0.15,0.12);
    ///drum body
    glBegin(GL_QUADS);
    glVertex2f(318.73f,214.41f);
    glVertex2f(134.46f,214.41f);
    glVertex2f(134.46f,292.24f);
    glVertex2f(318.73f,292.24f);
    glEnd();
    ///drum stick
    glBegin(GL_QUADS);
    glVertex2f(187.21f,155.30f+a);
    glVertex2f(93.69f,117.16f+a);
    glVertex2f(89.89f,126.48f+a);
    glVertex2f(183.41f,164.61f+a);
    glEnd();
///stick ball
    glColor3f(0.07f,0.0f,0.0f);
    glPushMatrix();
    glTranslatef(193.30179282868534f,163.42131474103581f+a,0.0f);
    glRotatef(0,0,0,1);
    dispFilledelipse(0,0,14.471815707467137,14.471815707467137);
    glPopMatrix();


    glColor3f(0.7f,0.9f,0.5f);
    glPushMatrix();
    glTranslatef(225.796812749004f,217.08167330677287f,0.0f);
    glRotatef(0,0,0,1);
    dispFilledelipse(0,0,91.02205041221251,14.348546408425712);
    glPopMatrix();

///drum design
    glColor3f(0.5f,0.2f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(223.29f,230.46f);
    glVertex2f(170.88f,230.91f);
    glVertex2f(197.73f,305.58f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(204.46f,303.62f);
    glVertex2f(255.22f,305.17f);
    glVertex2f(232.13f,229.74f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(290.63f,229.48f);
    glVertex2f(239.78f,229.75f);
    glVertex2f(265.61f,307.28f);
    glEnd();

    glColor3f(0.2f,0.15f,0.1f);
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glVertex2d(75, 425);
    glVertex2d(500, 425);
    glVertex2d(500, 385);
    glVertex2d(75, 385);
    glEnd();
    ///string name
    drawstring(100, 415, "Momenul50");
    glutPostRedisplay();
    glFlush();
}
///speed function
void idle()

{
    if(play==1)
    {
        a+=SPEED/100;
    }
    if(a>50)
    {
        a=0;
    }
}
void main_menu(int index)
{
    switch(index)
    {
    case 1:
        if(index==1)
        {
            play=1;
            a=0;
        }
    case 2:
        if(index==2)
        {
            play=0;
            a=0;
        }
        break;
    }
    glutPostRedisplay();
}
///keyboard function
void keyboardFunc( unsigned char key, int x, int y )
{
    switch( key )
    {
    case 'p':
    case 'P':
        play=1;
        break;
    case 's':
    case 'S':
        play=0;
        break;
    }
    glutPostRedisplay();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 200);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Momenul");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutCreateMenu(main_menu);
    glutKeyboardFunc(keyboardFunc);
    glutAddMenuEntry("Play",1);
    glutAddMenuEntry("Stop",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}