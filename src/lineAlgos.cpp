#include <GLFW/glfw3.h>
#include <iostream>


#include "lineAlgos.h"


void drawLineDDA(Point p1, Point p2,float color[4])
{

    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;

    float x = p1.x;
    float y = p1.y;

    int stepSize = std::abs(dx) > std::abs(dy) ? std::abs(dx) : std::abs(dy);

    Point linePoints[stepSize + 1];
    linePoints[0] = {p1.x, p1.y};

    float xInc =float(dx) / float(stepSize);
    float yInc = float(dy) / float(stepSize);
    
    glPointSize(20);
    glColor4fv(color);
    glBegin(GL_POINTS);

    for (int i = 1; i <= stepSize; i++)
    {
        x = x + xInc;
        y = y + yInc;
        linePoints[i] = {int(x), int(y)};
        // std::cout << i << "->" << linePoints[i].x << "," << linePoints[i].y << std::endl;
        glVertex2i(linePoints[i].x, linePoints[i].y);
    }
    glEnd();
    
}


void mlessThan1BSA(Point p1, Point p2, int dx, int dy, float color[4])
{

    int pk = 2 * dy - dx;

    int x = p1.x;
    int y = p1.y;

    Point linePoints[dx + 1];
    linePoints[0] = {x, y};

    glPointSize(5);
    glColor4fv(color);
    glBegin(GL_POINTS);

    for (int i = 1; i <= dx; i++)
    {
        if (pk < 0)
        {
            x++;
            pk = pk + 2 * dy;
        }
        else
        {
            x++;
            y++;
            pk = pk + 2 * dy - 2 * dx;
        }

        linePoints[i] = {x, y};
        // std::cout << i << "->" << linePoints[i].x << "," << linePoints[i].y << std::endl;
        glVertex2i(linePoints[i].x, linePoints[i].y);
    }
    glEnd();
}

void mGreaterThan1BSA(Point p1, Point p2, int dx, int dy,float color[4])
{

    int pk = 2 * dx - dy;

    int x = p1.x;
    int y = p1.y;

    Point linePoints[dy + 1];
    linePoints[0] = {x, y};

    glPointSize(5);
    glColor4fv(color);
    glBegin(GL_POINTS);

    for (int i = 1; i <= dy; i++)
    {
        if (pk < 0)
        {
            y++;
            pk = pk + 2 * dx;
        }
        else
        {
            x++;
            y++;
            pk = pk + 2 * dx - 2 * dy;
        }

        linePoints[i] = {x, y};
        glVertex2i(linePoints[i].x, linePoints[i].y);
        // std::cout << i << "->" << linePoints[i].x << "," << linePoints[i].y << std::endl;
    }
    glEnd();
}

void drawLineBSA(Point p1, Point p2,float color[4])
{
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;

 

    std::abs(dx) > std::abs(dy) ? mlessThan1BSA(p1, p2, dx, dy,color) : mGreaterThan1BSA(p1, p2, dx, dy,color);
   
}

// int main()
// {
//     Point p1{2, 3};
//     Point p2{8, 9};
//     Point p3{80, 90};
//     Point p4{85, 100};
//     drawLineDDA(p1, p2);
//     drawLineBSA(p3, p4);
//     return 0;
// }