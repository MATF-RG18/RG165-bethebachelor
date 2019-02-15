#include <stdio.h>
#include <GL/glut.h>

static int window_width, window_height;

void on_keyboard(unsigned char key, int x, int y);
void on_reshape(int width, int height);
void on_display(void);

void drawAxis();
void drawPlane();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);


    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    glutKeyboardFunc(on_keyboard);
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);


    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}


void on_keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27: exit(0); break;
    }
}

void on_reshape(int width, int height) {
    window_width = width;
    window_height = height;
}


void on_display(void) {
    GLfloat light_position[] = {1, 1, 1, 0};
    GLfloat light_ambient[] = {.1, .1, .55, 0};
    GLfloat light_diffuse[] = {.2, .2, .7, 1};
    GLfloat light_specular[] = {.5, .5, .5, 1};

    GLfloat ambient_coeffs[] = {.3, .3, .7, 1};
    GLfloat diffuse_coeffs[] = { .1, .1, .7, 1 };
    GLfloat specular_coeffs[] = { 0, 0, 1, 1 };


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
    gluLookAt(0, 4, 4, 0, 0, 0, 0, 1, 0);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);



    //drawAxis();
    drawPlane();
    glutSwapBuffers();
}

void drawAxis() {
    /*
     * Isctvanje osa
     */

    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(10, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 10, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 10);
    glEnd();
}

void drawPlane() {
    glPushMatrix();
    glScalef(1.5, .05, 2.25);
    glutSolidCube(4);
    glPopMatrix();
}
