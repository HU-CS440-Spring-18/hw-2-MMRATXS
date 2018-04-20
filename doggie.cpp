#include <cstdlib>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLUT/glut.h>
#include <iostream>
#include "sqPrototype.h"

using namespace std;

int theGlutWindowWidth=600,theGlutWindowHeight=320,score=0;
GLfloat vertices1[] = { -0.05, 0.3, 0.05, 0.3, 0.05,-0.3, -0.05,-0.3};
GLfloat vertices2[] = { -0.05, 0.3, 0.05, 0.3, 0.05,-0.3, -0.05,-0.3};
bool flag=true;

void drawSquare(float len, float breadth){
    
    GLfloat arr[] = { -(breadth/2), (len/2), (breadth/2), (len/2), (breadth/2),-(len/2), -(breadth/2),-(len/2)};
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, arr);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void drawSquare(GLfloat arr[]){
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, arr);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
}
void display() {

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.9, 0.3, 0.2);

    glTranslatef(0,0.3,0);
    //body
    drawSquare(0.35,1);
    //face
    glTranslatef(-0.5,0,0);
    glutSolidSphere(0.2,20,20);
    glTranslatef(0,-0.6,0);    
    glutSolidSphere(0.1,20,20);
    // eyes
    glTranslatef(0,0.68,0);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(0.01,20,20);
    glTranslatef(-0.1,0,0);
    glutSolidSphere(0.01,20,20);
    // bodycurve
    glColor3f(0.9, 0.3, 0.2);
    glTranslatef(1.1,-0.08,0);
    glutSolidSphere(0.175,20,20);
    // legs
    glTranslatef(-0.7,-0.4,0);
    drawSquare(vertices1);
    glTranslatef(0.15,0,0);
    drawSquare(vertices2);
    glTranslatef(0.35,0,0);
    drawSquare(vertices1);
    glTranslatef(0.15,0,0);
    drawSquare(vertices2);
    glutSwapBuffers();

}

void move(){
    if(flag){
        glTranslatef(-0.5,0.1,0);
        vertices1[4] = -0.05;
        vertices1[6] = -0.15;
        glutPostRedisplay();}
    else{
        glTranslatef(-0.5,0.1,0);
        vertices1[4] = 0.05;
        vertices1[6] = -0.05;
        glutPostRedisplay();
    }
    flag=!flag;
}

void kick(){
        glTranslatef(-0.45,0.1,0);
        vertices1[4] = -0.15;
        vertices1[6] = -0.25;
        glutPostRedisplay();
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
            case 'm':
                move();
                break;
            case 'k':
                kick();
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
