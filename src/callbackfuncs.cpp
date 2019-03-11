//
// Created by nikjan on 3/11/19.
//

#include <GL/glut.h>
#include "callbackfuncs.hpp"
#include "draw.hpp"
#include "light.hpp"
#include "camera.hpp"




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
            1, 25
    );
    camera.setLook(look_id);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    drawPlane();

    drawFigure();
    glutSwapBuffers();
}

void on_keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27: exit(0); break;
        case 'a': case 'A':
            if (timer_activeX == 0)
                glutTimerFunc(450, on_timer, 0);
            timer_activeX = -1;
            break;
        case 'd': case 'D':
            if (timer_activeX == 0)
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
            timer_activeX = 0;
            break;
        case '1':
            look_id = FIRST_VIEW;
            glutPostRedisplay();
            break;
        case '2':
            look_id = SECOND_VIEW;
            glutPostRedisplay();
            break;
        case '3':
            look_id = THIRD_VIEW;
            glutPostRedisplay();
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

    if (timer_activeX != 0 or timer_activeZ != 0)
        glutTimerFunc(50, on_timer, 0);

}

/*
 * 2.tajmer sluzi za pokretanje animacije duz pravca Z - ose
*/
void on_timer2(int value) {
    if (value != 0)
        return;
    z_pos += (-timer_activeZ * .075);
    tmp_z += (-timer_activeZ * .075);
    glutPostRedisplay();
    if (timer_activeZ != 0)
        glutTimerFunc(50, on_timer2, 0);
}


void init_callbacks(void) {
    glutKeyboardFunc(on_keyboard);
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);
}