#include <cstdlib>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLUT/glut.h>
#include <iostream>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include "sqPrototype.h"

using namespace std;

int theGlutWindowWidth=320,theGlutWindowHeight=320,score=0;

const double PI = 3.14159265;

void drawLine(float p1[],float p2[])
{
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2fv(p1);
    glVertex2fv(p2);
    glEnd();

}

drawSquare(Square sq){
    float p1[] ={-(sq.size)/2,(sq.size)/2};
    float p2[] ={(sq.size)/2,(sq.size)/2};
    float p3[] ={(sq.size)/2,-(sq.size)/2};
    float p4[] ={-(sq.size)/2,-(sq.size)/2};
    
    drawLine(p1,p2);
    drawLine(p2,p3);
    drawLine(p3,p4);
    drawLine(p4,p1);
}
void display() {
    
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    Square face(1);
    Square eye1(0.1);
    Square eye2(0.1);
    Square nose(0.1);
    Square lips(0.1);

    glPushMatrix();
    glRotatef(45,0,0,1);
    drawSquare(face);
    glPopMatrix();

    glPushMatrix();
    glRotatef(45,0,0,1);
    drawSquare(nose);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.25,0.2,0);
    drawSquare(eye1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.25,0.2,0);
    drawSquare(eye2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-0.2,0);
    glScalef(5,1,1);
    drawSquare(lips);
    glPopMatrix();

    glFlush();

}


void pressKey(unsigned char key,int x, int y){
    switch(key)
        {
            case 'q':
                exit(1); 
                break;
            case 'Q':
                exit(1);
                break;
            default:
            break;
        };
}
 
int main(int argc, char** argv) {


    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup Test");
    glutInitWindowSize(theGlutWindowWidth,theGlutWindowHeight);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutKeyboardFunc( pressKey);

    glutMainLoop();
    return 0;
}
