#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include "lineAlgos.h"


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

//center of the logo
int x_center = 100;
int y_center = 100;

int logo_radius = 700;

struct histogramData{
    int x_value;
    int frequency;
};

histogramData D1[5];

int x = 0;



// colors used in the logo
float blue[] = {0.529, 0.808, 0.922, 1.0};
float yellow[] = {1.0, 1.0, 0.0, 1.0};
float black[] = {0.0, 0.0, 0.0, 1.0};
float red[] = {1.0, 0.0, 0.0, 1.0};
float light_pink[] = {1.0, 0.714, 0.757, 1.0};
float white[] = {1.0, 1.0, 1.0, 1.0};

//calculate x coordinate
float calc_xcoord(float xcoord, float theta,float radius){
    return radius * std::cos(theta) + xcoord;
}

//calculate y coordinate
float calc_ycoord(float ycoord, float theta, float radius)
{
    return radius * std::sin(theta) + ycoord;
}

int getResolution()
{
    // Get primary monitor
    GLFWmonitor *primaryMonitor = glfwGetPrimaryMonitor();
    if (!primaryMonitor)
    {
        std::cerr << "Failed to get primary monitor" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Get monitor mode
    const GLFWvidmode *mode = glfwGetVideoMode(primaryMonitor);
    if (!mode)
    {
        std::cerr << "Failed to get video mode" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Print monitor resolution
    std::cout << "Monitor Resolution: " << mode->width << "x" << mode->height << std::endl;
}

void drawInnerTriangle(float x_center, float y_center, float radius, float colour[]){
    float theta1 = 2 * M_PI*3 / 12;
    float theta2 = 2 * M_PI*11 / 12;
    float theta3 = 2 * M_PI*7 / 12;

    glColor4fv(colour);
    
    float x1 = calc_xcoord(x_center, theta1, radius);
    float y1 = calc_ycoord(y_center, theta1, radius);
    float x2 = calc_xcoord(x_center, theta2, radius);
    float y2 = calc_ycoord(y_center, theta2, radius);
    float x3 = calc_xcoord(x_center, theta3, radius);
    float y3 = calc_ycoord(y_center, theta3, radius);

    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void drawOuterTriangle(float x_center, float y_center, float radius, float colour[],float lineWidth){
    float theta1 = 2 * M_PI*1 / 12;
    float theta2 = 2 * M_PI*5 / 12;
    float theta3 = 2 * M_PI*9 / 12;
    glLineWidth(lineWidth);
    glColor4fv(colour);

    float x1 = calc_xcoord(x_center, theta1, radius);
    float y1 = calc_ycoord(y_center, theta1, radius);
    float x2 = calc_xcoord(x_center, theta2, radius);
    float y2 = calc_ycoord(y_center, theta2, radius);
    float x3 = calc_xcoord(x_center, theta3, radius);
    float y3 = calc_ycoord(y_center, theta3, radius);

    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}


    void drawCircle(float x_center, float y_center, float radius, int segments, float colour[])
{
   
    glBegin(GL_POLYGON);
    glColor4fv(colour);

    float delta_theta = 2.0 * M_PI / segments;

    for (int i = 0; i < segments;i++){
        float theta1 = delta_theta * i;
        float theta2 = delta_theta * (i + 1);
        
        float x1 = calc_xcoord(x_center, theta1, radius);
        float y1 = calc_ycoord(y_center, theta1, radius);
        float x2 = calc_xcoord(x_center, theta2, radius);
        float y2 = calc_ycoord(y_center, theta2, radius);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
      
    }
    glEnd();
}
void drawIncompleteCirles(float x_center, float y_center, float radius, float colour[],float lineWidth){
    float theta1 = 2 * M_PI*1 / 12;
    float theta2 = 2 * M_PI*5 / 12;
    float theta3 = 2 * M_PI*9 / 12;
    glLineWidth(lineWidth);
    glColor4fv(colour);

    float x1 = calc_xcoord(x_center, theta1, radius);
    float y1 = calc_ycoord(y_center, theta1, radius);
    float x2 = calc_xcoord(x_center, theta2, radius);
    float y2 = calc_ycoord(y_center, theta2, radius);
    float x3 = calc_xcoord(x_center, theta3, radius);
    float y3 = calc_ycoord(y_center, theta3, radius);
    drawCircle(x1, y1, 70, 1080, black);
    
    drawCircle(x2, y2, 70, 1080, black);

    drawCircle(x3, y3, 70, 1080, black);
  
}
void fillIncompleteCirles(float x_center, float y_center, float radius, float colour[],float lineWidth){
    float theta1 = 2 * M_PI*1 / 12;
    float theta2 = 2 * M_PI*5 / 12;
    float theta3 = 2 * M_PI*9 / 12;
    glLineWidth(lineWidth);
    glColor4fv(colour);

    float x1 = calc_xcoord(x_center, theta1, radius);
    float y1 = calc_ycoord(y_center, theta1, radius);
    float x2 = calc_xcoord(x_center, theta2, radius);
    float y2 = calc_ycoord(y_center, theta2, radius);
    float x3 = calc_xcoord(x_center, theta3, radius);
    float y3 = calc_ycoord(y_center, theta3, radius);
    
    drawCircle(x1, y1, 60, 1080, white);
      drawCircle(x2, y2, 60, 1080, white);
    
    drawCircle(x3, y3, 60, 1080, white);
}



void drawPetals(float x_center, float y_center, float radius, int segments){
    float delta_theta = 2.0 * M_PI / segments;
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor4fv(black);

    for (int i = 0; i < segments; i++)
    {
        float theta1 = delta_theta * i;
        float theta2 = delta_theta * (i + 1);
        
        float x1 = calc_xcoord(x_center, theta1, radius);
        float y1 = calc_ycoord(y_center, theta1, radius);
        float x2 = calc_xcoord(x_center, theta2, radius);
        float y2 = calc_ycoord(y_center, theta2, radius);
        // float x_mid = (x1 + x2) / 2;
        // float y_mid = (y1 + y2) / 2;
        // float arc_radius = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        // drawCircle(x_mid, y_mid,arc_radius , 360);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor4fv(red);
    for (int i = 0; i < segments; i++)
    {
        float theta1 = delta_theta * i;
        float theta2 = delta_theta * (i + 1);
        
        float x1 = calc_xcoord(x_center, theta1, radius);
        float y1 = calc_ycoord(y_center, theta1, radius);
        float x2 = calc_xcoord(x_center, theta2, radius);
        float y2 = calc_ycoord(y_center, theta2, radius);

        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }

    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor4fv(black);

    for (int i = 0; i < segments;i++){
       float  theta = delta_theta * i;

       float x = calc_xcoord(x_center, theta, radius);
       float y = calc_ycoord(y_center, theta, radius);
       glVertex2f(x_center, y_center);
       glVertex2f(x, y);
    }
    glEnd();
}

void draw_KU(float x_center, float y_center,float colour[])
{
  

    glLineWidth(15);
    glColor4fv(colour);
    glBegin(GL_LINES);
    glVertex2f(x_center-60, y_center + 100);
    glVertex2f(x_center-60, y_center - 100);
    glEnd(); 

    glBegin(GL_POLYGON);
    glVertex2f(x_center - 58, y_center);
    glVertex2f(x_center +65, y_center - 100);
    glVertex2f(x_center +190, y_center);
    glVertex2f(x_center +65, y_center + 100);
    
    glEnd();

    glColor4fv(light_pink);
    glBegin(GL_POLYGON);
    glVertex2f(x_center+20, y_center);
    glVertex2f(x_center +110, y_center - 70);
    glVertex2f(x_center +160, y_center-35);
    glVertex2f(x_center +65, y_center + 40);

    
    glEnd();
}


void drawLogo(){
    drawPetals(x_center, y_center, logo_radius, 12);
    drawCircle(x_center, y_center, logo_radius - (logo_radius / 5), 1080, black);
    drawCircle(x_center, y_center, logo_radius - (logo_radius / 5 + 15), 1080, blue);
    drawCircle(x_center, y_center, logo_radius - ((logo_radius / 5) * 2), 1080, black);
    drawCircle(x_center, y_center, logo_radius - ((logo_radius / 5) * 2 + 15), 1080, yellow);
    drawInnerTriangle(x_center, y_center, logo_radius - ((logo_radius / 5) * 2), black);
    drawInnerTriangle(x_center, y_center, logo_radius - ((logo_radius / 5) * 2 + 30), light_pink);
    draw_KU(x_center, y_center, black);
    drawIncompleteCirles(x_center, y_center, logo_radius - ((logo_radius / 5) * 2), black, 10);
    drawOuterTriangle(x_center, y_center, logo_radius - ((logo_radius / 5) * 2), black, 10);
    drawOuterTriangle(x_center, y_center, logo_radius - ((logo_radius / 5) * 2 + 30), white, 10);
    drawOuterTriangle(x_center, y_center, logo_radius - ((logo_radius / 5) * 2 + 60), black, 5);
    fillIncompleteCirles(x_center, y_center, logo_radius - ((logo_radius / 5) * 2), black, 10);

}

void drawHistograms(){
    Point p1;
    Point p2;
    for ( int i = 0; i < 5; i++)
        {
            p1 = {D1[i].x_value*20, 0};
            p2 = {D1[i].x_value*20, D1[i].frequency*20};
            std::cout<< p1.x << "," << p1.y <<"and"<<p2.x<<","<<p2.y<< std::endl;
            drawLineDDA(p1, p2,red);
        }
}

    int main()
{
    time_t t;
    srand((unsigned)time(&t));

    for (int i = 0; i < 5; i++)
    {
        D1[i].x_value = (i+1)*2;
        D1[i].frequency = rand() % 11;
    }

    GLFWwindow *window;

    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    getResolution();

        /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(500, 500, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetWindowPos(window, 500, 500);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        glClearColor(1.0, 1.0, 1.0, 1.0);
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-10, x_center * 2+10,-10, y_center * 2+10, 0, 1);
        glColor3f(1.0, 1.0, 1.0);


        drawHistograms();
        drawLineBSA({0,0}, {0,y_center*2},black);
        drawLineBSA({0,0}, {x_center*2,0},black);
        // drawLineDDA({0,y_center*2}, {x_center*2,y_center*2});
        // drawLineDDA({x_center*2,0}, {x_center*2,y_center*2});

        

        // drawLineDDA(p1, p3);
        // drawLineDDA(p3, {x_center, y_center});
        // drawLineDDA(p3, {110, 100});

        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();
//     Point p1{2, 3};
//     Point p2{8, 9};
//     Point p3{80, 90};
//     Point p4{85, 100};
//    drawLineDDA(p1, p2);
//     drawLineBSA(p3, p4);
    
    return 0;
}
