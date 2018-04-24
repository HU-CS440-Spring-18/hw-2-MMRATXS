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
static float pN[2];
static float qN[2];
static float rN[2];

void drawLine(float p1[],float p2[])
{
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2fv(p1);
    glVertex2fv(p2);
    glEnd();

}

float* midPoint(float p1[2], float p2[2]){
    static float mP[] = {(p1[0]+p2[0])/2,(p1[1]+p2[1])/2};
    return mP;
}

float eucDist(float p1[2], float p2[2])
{
    return sqrt(pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2));
}

float findAngle(float p1[2],float p2[2]){
    float angle= (atan2(p2[1] - p1[1], p2[0] - p1[0]))*(180/PI);
    return angle;
}

float* findP(float p1[2],float angle,float distance){
    float ang=angle*(PI/180);
    pN[0] = p1[0]+(cos(ang)*(distance/3));
    pN[1] = p1[1]+(sin(ang)*(distance/3));
    return pN;
}

float* findQ(float p1[2],float angle,float distance){
    float ang= (angle + 60)*(PI/180);
    qN[0] = p1[0]+(cos(ang)*(distance/3));
    qN[1] = p1[1]+(sin(ang)*(distance/3));
    return qN;
}

float* findR(float p1[2],float angle,float distance){
    float ang= (angle - 60)*(PI/180);
    // cout<<cos(ang)<<","<<(distance/3)<<endl;
    rN[0] = p1[0]+(cos(ang)*(distance/3));
    rN[1] = p1[1]+(sin(ang)*(distance/3));
    // cout<<r[0]<<","<<r[1]<<endl;
    return rN;
}

void kochLine(float p1[2],float p2[2], int depth){

    cout<<depth;
    
    float angle= findAngle(p1,p2);
    
    float dist = eucDist(p1,p2);

    float* p = findP(p1,angle,dist);
    float* q = findQ(p,angle,dist);
    float* r = findR(q,angle,dist);

    float ab1[2],ab2[2],ab3[2];

    ab1[0]= p[0]; ab1[1]=p[1];
    ab2[0]= q[0]; ab2[1]=q[1];
    ab3[0]= r[0]; ab3[1]=r[1];

    cout<<p2[1]<<endl;

    if(depth==0){
        drawLine(p1,p2);
    }
    if(depth==1){
        drawLine(p1,p);
        drawLine(p,q);
        drawLine(q,r);
        drawLine(r,p2);
        cout<<p2[1]<<endl;
        q=NULL;
        p=NULL;
        r=NULL;
        delete p;
        delete q;
        delete r;
    }
    if(depth>1){
        kochLine(p1,ab1,depth-1);
        kochLine(ab1,ab2,depth-1);
        kochLine(ab2,ab3,depth-1);
        kochLine(ab3,p2,depth-1);
    }
    
}

void kochSnowFlake(float p1[2],float p2[2],float p3[2],int depth){
    kochLine(p1,p2,depth);
    kochLine(p2,p3,depth);
    kochLine(p3,p1,depth);
}

void display() {
    
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    float a[]={-0.5,-0.5};
    float b[]={0,0.5};
    float c[]={0.5,-0.5};
    glPushMatrix();
    kochSnowFlake(a,b,c,3);
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
    glutCreateWindow("Koch Flake");
    glutInitWindowSize(theGlutWindowWidth,theGlutWindowHeight);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutKeyboardFunc( pressKey);

    glutMainLoop();
    return 0;
}
