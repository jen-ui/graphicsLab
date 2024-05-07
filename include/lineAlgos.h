#ifndef ADD_H
#define ADD_H

struct Point
{
    int x, y;
};

void drawLineDDA(Point p1, Point p2,float color[4]);
void mlessThan1BSA(Point p1, Point p2, int dx, int dy,float color[4]);
void mGreaterThan1BSA(Point p1, Point p2, int dx, int dy,float color[4]);
void drawLineBSA(Point p1, Point p2, float color[4]);

#endif  