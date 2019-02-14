#include <stdio.h>
#include <GL/glut.h>

static int window_width, window_height;

void on_keyboard(unsigned char key, int x, int y);
void on_reshape(int width, int height);
void on_display(void);
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
    gluLookAt(2, 4, 6, 0, 0, 0, 0, 1, 0);


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
    glutSwapBuffers();
}