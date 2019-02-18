#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>

static int window_width, window_height;
int timer_activeX = 0, timer_activeZ = 0;
float x_pos = 0, tmp_z = 0, z_pos = 0;

GLfloat light_position[] = {1, 1, 1, 0};
GLfloat light_ambient[] = {.5, .5, .5, 0};
GLfloat light_diffuse[] = {.1, .1, .5, 0};
GLfloat light_specular[] = {.3, .3, .3, 1};

GLfloat ambient_coeffs[] = {.3, .3, .7, 1};
GLfloat diffuse_coeffs[] = {.2, .2, .9, 1 };
GLfloat specular_coeffs[] = { .5, 0, 0, 1 };

void on_keyboard(unsigned char key, int x, int y);
void on_reshape(int width, int height);
void on_timer(int value);
void on_timer2(int value);
void on_display(void);


void drawPlane();
void drawFigure();

void shuffle_colours(void);

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
        case 'a': case 'A': {
            if (timer_activeX == 0)
                glutTimerFunc(50, on_timer, 0);
            timer_activeX = -1;
        }break;
        case 'd': case 'D': {
            if (timer_activeX == 0)
                glutTimerFunc(50, on_timer, 0);
            timer_activeX = 1;
        }break;
        case 'w': case 'W': {
            if (timer_activeZ == 0)
                glutTimerFunc(50, on_timer2, 0);
            timer_activeZ = 1;
        }break;
        case 'x': case 'X': {
            timer_activeX = 0;
        }break;
        case 's': case 'S': {
            timer_activeZ = 0;
        }break;
    }
}

void on_reshape(int width, int height) {
    window_width = width;
    window_height = height;
}

void on_display(void) {


    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, window_width, window_height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width / (float)window_height,
            1, 25
    );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 2, 3 + z_pos, 0, 0, z_pos, 0, 1, 0);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    drawPlane();

    drawFigure();
    glutSwapBuffers();
}


/* Funckija za iscrtavanje figurice,
 * tj loptice u pocetnoj fazi
 */
void drawFigure() {
    glPushMatrix();
    if (tmp_z <= -5){
        tmp_z += 5;
        shuffle_colours();
    }
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glTranslatef(x_pos, .2, z_pos);
    glutSolidSphere(.1, 20, 20);
    glPopMatrix();
}


void shuffle_colours(void) {
    //FIXME
    diffuse_coeffs[0] = 1. *rand() / RAND_MAX;
    diffuse_coeffs[1] = 1. * rand() / RAND_MAX;
    diffuse_coeffs[2] = 1. * rand() / RAND_MAX;
}

void drawPlane() {
    glPushMatrix();
    glTranslatef(0, 0, z_pos);
    glScalef(1.5, .05, 15);
    glutSolidCube(4);
    glPopMatrix();
}

void on_timer(int value) {
    if (value != 0)
        return;
    x_pos += (timer_activeX * .06);
    glutPostRedisplay();
    if (x_pos <= -3 || x_pos >= 3)
        exit(EXIT_FAILURE);

    if (timer_activeX != 0 or timer_activeZ != 0)
        glutTimerFunc(50, on_timer, 0);

}
//2.tajmer sluzi za pokretanje animacije duz pravca Z - ose
void on_timer2(int value) {
    if (value != 0)
        return;
    z_pos += (-timer_activeZ * .075);
    tmp_z += (-timer_activeZ * .075);
    glutPostRedisplay();
    if (timer_activeZ != 0)
        glutTimerFunc(50, on_timer2, 0);
}
