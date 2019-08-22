#include <GL/glut.h>
#include <iostream>
#include <random>
#include <memory.h>
#include "figure.hpp"
#include "light.hpp"
#include "callbackfuncs.hpp"
#include "functions.hpp"



extern Camera camera;
extern int jump_active;
extern int timer_activeX, timer_activeZ;
extern int look_id;
extern float lracceleration, x_pos, z_pos;
extern int direction_keeper;
int window_width, window_height;
extern float ind_for_colors;
Plane plane;
Student student;
unsigned courses_left = 40;

double forward_acceleration;

float double_speed = 1;


void on_reshape(int width, int height) {
    window_width = width;
    window_height = height;
}



void on_display(void) {


    setLight();
    setMaterial();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, window_width, window_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width / (float)window_height,
            1, z_pos
    );
    camera.setLook(look_id);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);



    plane.draw();
    student.draw();


    draw_coins();


    std::string buffer("Ostalo ti je jos ");
    buffer += std::to_string(courses_left) + " ispita do kraja.\n";

    draw_score(buffer.data(), buffer.size(), 0, 580);
    glPopMatrix();
    glutSwapBuffers();
}

void on_keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27: exit(0); break;
        case 'a': case 'A':
            if (timer_activeX == 0 and !jump_active)
                glutTimerFunc(450, on_timer, 0);
            timer_activeX = -1;
            break;
        case 'd': case 'D':
            if (timer_activeX == 0 and !jump_active)
                glutTimerFunc(450, on_timer, 0);
            timer_activeX = 1;
            break;
        case 'w': case 'W':
            if (timer_activeZ == 0)
                glutTimerFunc(50, on_timer2, 0);
            timer_activeZ = 1;
            break;
        case 'x': case 'X':
            timer_activeX = 0;
            timer_activeZ = 0;
            break;
        case 'q': case 'Q':
            jump_active = 1;
            direction_keeper = timer_activeX;
            timer_activeX = 0;
            glutPostRedisplay();
            break;
        case 32:
            double_speed = 1.8;
            break;
        case '1':
            if (look_id != 1)
                glutPostRedisplay();
            look_id = FIRST_VIEW;
            break;
        case '2':
            if (look_id != 2)
                glutPostRedisplay();
            look_id = SECOND_VIEW;
            break;
        case '3':
            if (look_id != 3)
                glutPostRedisplay();
            look_id = THIRD_VIEW;

            break;
    }
}


void on_timer(int value) {
    if (value != 0)
        return;
    x_pos += (timer_activeX * lracceleration);
    glutPostRedisplay();
    if (x_pos <= -3 || x_pos >= 3)
        exit(EXIT_FAILURE);

    if (timer_activeX and timer_activeZ)
        glutTimerFunc(50, on_timer, 0);

}

extern YEAR year;
void on_timer2(int value) {
    if (value != 0)
        return;
    switch (year) {
        case first:
            forward_acceleration = .1; break;
        case second:
            forward_acceleration = .17; break;
        case third:
            forward_acceleration = .24; break;
        case fourth:
            forward_acceleration = .31; break;
    }
    z_pos += (-timer_activeZ * forward_acceleration * double_speed);
	ind_for_colors += (-timer_activeZ * forward_acceleration * double_speed);
    glutPostRedisplay();
    if (timer_activeZ != 0)
        glutTimerFunc(50, on_timer2, 0);
}

void on_up_keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 32:
            double_speed = 1;
    }
}


void init_callbacks(void) {
    glutKeyboardFunc(on_keyboard);
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);
    glutKeyboardUpFunc(on_up_keyboard);
}

