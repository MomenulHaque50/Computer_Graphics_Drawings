#include <windows.h>
#include<GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void init(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(0, 600, 600, 0);
}

void drawstring(int x, int y, char *s)
{
    char *c;
    glRasterPos2i(x, y);
    for (c = s; *c != '\0'; *c++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);

///Tree body
    glColor3f(1.8f,1.5f,0.5f);
    glBegin(GL_QUADS);
        glVertex2f(238.05f,194.62f);
        glVertex2f(210.56f,194.62f);
        glVertex2f(210.56f,295.62f);
        glVertex2f(238.05f,295.62f);
    glEnd();
    ///Tree tub
    glColor3f(0.4f,0.5f,0.5f);
    glBegin(GL_QUADS);
        glVertex2f(280.88f,282.27f);
        glVertex2f(167.73f,282.27f);
        glVertex2f(190.73f,365.04f);
        glVertex2f(260.88f,365.04f);
    glEnd();
    ///string box
    glColor3f(0.4f,0.5f,0.5f);
    glBegin(GL_LINE_LOOP);
        glVertex2d(75, 425);
        glVertex2d(500, 425);
        glVertex2d(500, 385);
        glVertex2d(75, 385);
    glEnd();
  ///tree leaf1
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(156.37f,137.95f);
        glVertex2f(290.84f,137.95f);
        glVertex2f(223.60f,66.24f);
    glEnd();
///tree leaf2
    glBegin(GL_TRIANGLES);
        glVertex2f(130.48f,175.80f);
        glVertex2f(320.72f,175.80f);
        glVertex2f(225.60f,97.01f);
    glEnd();
    ///tree leaf3
    glBegin(GL_TRIANGLES);
        glVertex2f(117.53f,216.94f);
        glVertex2f(328.69f,216.94f);
        glVertex2f(223.11f,115.94f);
    glEnd();
        ///Generate String
     glColor3f(0.4f,0.5f,0.5f);
    drawstring(160, 400, "Christmas Tree");
    drawstring(100, 415, "Momenul50");
    glFlush();
}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 300);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Tree");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}