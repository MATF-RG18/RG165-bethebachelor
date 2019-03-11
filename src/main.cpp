#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include "light.hpp"
#include "draw.hpp"
#include "camera.hpp"


#define FIRST_VIEW (1)
#define SECOND_VIEW (2)
#define THIRD_VIEW (3)

static int window_width, window_height;
int timer_activeX = 0, timer_activeZ = 0;
float x_pos = 0, tmp_z = 0, z_pos = 0;


Camera camera;

float lracceleration = 0.06;
int jump_active = 0;
int look_id = 1;
extern GLfloat diffuse_coeffs[4];

extern GLfloat specular_coeffs[4];

void on_keyboard(unsigned char key, int x, int y);
void on_reshape(int width, int height);
void on_timer(int value);
void on_timer2(int value);
void on_display(void);

void init(int , char**);

int main(int argc, char** argv) {
    init(argc, argv);

    glutKeyboardFunc(on_keyboard);
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);

    glutMainLoop();
    return 0;
}

void init(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    srand((unsigned)time(NULL));

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
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
