#include <stdio.h>
#include <GL/glut.h>
#include <time.h>
#include "callbackfuncs.h"


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

