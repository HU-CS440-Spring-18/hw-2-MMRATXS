#pragma once

struct Point{

    float x;
    float y;

    Point()
    {
    }
    Point(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    Point shift(float x,float y)
    {
        Point newPoint;
        newPoint.x = this->x + x;
        newPoint.y = this->y + y;

        return newPoint;
    }
};
