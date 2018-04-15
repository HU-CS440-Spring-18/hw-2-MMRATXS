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
    drawLine(sq.p1,sq.p2);
    drawLine(sq.p2,sq.p3);
    drawLine(sq.p3,sq.p4);
    drawLine(sq.p1,sq.p4);
}
void display() {
    
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    Square face(1,1,0);
    Square eye1(0.1,0.1,0);
    Square eye2(0.1,0.1,0);
    Square nose(0.1,0.1,0);
    Square lips(0.1,0.5,0);


    face=face.rotate(45*(PI/180));
    nose=nose.rotate(45*(PI/180));
    lips.shift(0,-0.2);
    eye1.shift(-0.25,0.2);
    eye2.shift(0.25,0.2);
    drawSquare(face);
    drawSquare(eye1);
    drawSquare(eye2);
    drawSquare(nose);
    drawSquare(lips);
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
