#pragma once
#include "Point.h"
#include<math.h>
#include<time.h>
#include<stdlib.h>

struct Square{

    float p1[2];
    float p2[2];
    float p3[2];
    float p4[2];
    float initAngle;

    Square()
    {
    }
    Square(float length, float bredth,float initAngle)
    {
        this->p1[0] = 0-(bredth/2);
        this->p1[1] = 0+(length/2);
        this->p2[0] = 0+(bredth/2);
        this->p2[1] = 0+(length/2);
        this->p3[0] = 0+(bredth/2);
        this->p3[1] = 0-(length/2);
        this->p4[0] = 0-(bredth/2);
        this->p4[1] = 0-(length/2);
        this->initAngle = initAngle;
    }

    Square rotate(float angle)
    {
        Square newSq;
        newSq.p1[0] = p1[0]*cos(-angle)- p1[1]*sin(-angle);
        newSq.p1[1] = p1[0]*sin(-angle)+ p1[1]*cos(-angle);

        newSq.p2[0] = p2[0]*cos(-angle)- p2[1]*sin(-angle);
        newSq.p2[1] = p2[0]*sin(-angle)+ p2[1]*cos(-angle);
        
        newSq.p3[0] = p3[0]*cos(-angle)- p3[1]*sin(-angle);
        newSq.p3[1] = p3[0]*sin(-angle)+ p3[1]*cos(-angle);
        
        newSq.p4[0] = p4[0]*cos(-angle)- p4[1]*sin(-angle);
        newSq.p4[1] = p4[0]*sin(-angle)+ p4[1]*cos(-angle);
        
        return newSq;
    }
    Square resize(float length, float bredth)
    {
        p1[0] = 0-(bredth/2);
        p1[1] = 0+(length/2);
        p2[0] = 0+(bredth/2);
        p2[1] = 0+(length/2);
        p3[0] = 0+(bredth/2);
        p3[1] = 0-(length/2);
        p4[0] = 0-(bredth/2);
        p4[1] = 0-(length/2);

    }
    Square shift(float x,float y)
    {
        p1[0] = p1[0]+x;
        p1[1] = p1[1]+y;
        p2[0] = p2[0]+x;
        p2[1] = p2[1]+y;
        p3[0] = p3[0]+x;
        p3[1] = p3[1]+y;
        p4[0] = p4[0]+x;
        p4[1] = p4[1]+y;

    }
};