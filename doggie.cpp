#include <cstdlib>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLUT/glut.h>
#include <iostream>
#include "sqPrototype.h"

using namespace std;

int theGlutWindowWidth=600,theGlutWindowHeight=320,score=0;
bool flag=true,tailFlag=true;
float ang1=0,ang2=0;
float ang1Leg1=0,ang2Leg1=0;
float tailAngle=-30,tailY=0.1;
float xMove=0;
float ballx=-0.5;
bool moveV=false,ballMove=false,wagTail=false;
long int ballFrame=0,tailFrame=0;
int timer=500;

drawLeg(float x, float y, float angle1,float angle2){
    //legs1
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(angle1,1,1,0);
    glScalef(1,4,1);
    glutSolidCube(0.08);
    glPopMatrix();
    //joint
    glPushMatrix();
    if(flag)
        glTranslatef(x+((angle2/90)*0.1),y-0.32,0);
    else
        glTranslatef(x-((angle2/90)*0.1),y-0.32,0);
    glRotatef(angle1,1,1,0);
    glScalef(1,4,1);
    glutSolidCube(0.08);
    glPopMatrix();
}

void display() {

    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.9, 0.3, 0.2);

    
    //Curve
    glPushMatrix();
    glTranslatef(0.5+xMove,0.2,0);
    glutSolidSphere(0.2,20,20);
    glPopMatrix();

    //Body
    glPushMatrix();
    glTranslatef(0+xMove,0.2,0);
    glScalef(2.5,1,1);
    glutSolidCube(0.4);
    glPopMatrix();

    //Face
    glPushMatrix();
    glTranslatef(-0.5+xMove,0.2,0);
    glutSolidSphere(0.2,20,20);
    glPopMatrix();

    //Eye1
    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslatef(-0.5+xMove,0.3,0);
    glutSolidSphere(0.02,20,20);
    glPopMatrix();
    //Eye2
    glPushMatrix();
    glTranslatef(-0.6+xMove,0.3,0);
    glutSolidSphere(0.02,20,20);
    glPopMatrix();
    
    //Tail
    glColor3f(0.9, 0.3, 0.2);
    glPushMatrix();
    glTranslatef(0.8+xMove,tailY,0);
    glRotatef(tailAngle,1,1,1);
    glScalef(6,1,1);
    glutSolidCube(0.07);
    glPopMatrix();

    drawLeg(-0.3+xMove,-0.15,ang1Leg1,ang2Leg1);
    drawLeg(-0.1+xMove,-0.15,ang1,ang2);
    drawLeg(0.2+xMove, -0.15,ang1,ang2);
    drawLeg(0.4+xMove, -0.15,ang1,ang2);
    
    //Ball
    glPushMatrix();
    glTranslatef(ballx,-0.5,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();

    glutSwapBuffers();

}

void move(){
    if(flag){
        ang1=45;
        ang2=45;
        ang1Leg1=45;
        ang2Leg1=45;
        xMove-=0.1;
        glutPostRedisplay();
    }
    else{
        ang1=0;
        ang2=0;
        ang1Leg1=0;
        ang2Leg1=0;
        xMove-=0.1;
        glutPostRedisplay();
    }
    flag=!flag;
}

void kick(){
    ang1Leg1=45;
    if(flag)
        ang2Leg1=45;
    else
        ang2Leg1=-45;
    
    flag=!flag;
    ballFrame+=1;
    ballx-=0.01;
    if(ballFrame>20){ballMove=false;}
    glutPostRedisplay();
}

void wagTailF(){
    if(tailFlag){
        tailY+=0.003;
        tailAngle+=1;
    }
    else{
        tailY-=0.003;
        tailAngle-=1;
    }
    
    tailFrame+=1;
    if(tailFrame>30){
        tailFrame=0;
        tailFlag=!tailFlag;
    }
    glutPostRedisplay();
}

void loop(int a){
    if(moveV){
        move();
    }
    if(ballMove){
        kick();
    }
    if(wagTail){
        wagTailF();
    }
    glutPostRedisplay();
    glutTimerFunc(timer,loop,0);
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
                timer=500;
                ang1Leg1=ang2Leg1=0;
                flag=true;
                moveV=true;
                ballMove=false;
                wagTail=false;
                break;
            case 'k':
                ballFrame=0;
                timer=65;
                flag=true;
                ballMove=true;
                moveV=false;
                wagTail=false;
                kick();
                break;
            case 'w':
                timer=30;
                tailFlag=true;
                wagTail=true;
                ballMove=false;
                moveV=false;
                wagTailF();
                break;
            case 's':
                moveV=false;
                ballMove=false;
                wagTail=false;
                break;
            default:
            break;
        };
}

const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };


int main(int argc, char** argv) {


    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup Test");
    glutInitWindowSize(theGlutWindowWidth,theGlutWindowHeight);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutKeyboardFunc( pressKey);
    
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glutTimerFunc(timer,loop,0);
    glutMainLoop();
    return 0;
}
