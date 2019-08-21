#include <stdio.h>
#include <GL/glut.h>
#include <time.h>
#include "callbackfuncs.hpp"
#include "image.hpp"


static GLuint names[2];

void init(int , char**);
void initialize_texture();

int main(int argc, char** argv) {
    init(argc, argv);
    init_callbacks();
	initialize_texture();
    glutMainLoop();
    return 0;
}

void init(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    srand((unsigned)time(nullptr));

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
}

void initialize_texture() {
	Image* image;
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	image = image_init(0, 0);
	char vucic[100] = "./professors/filipMaric.bmp";
	image_read(image, vucic);
	glGenTextures(2, names);
	
	glBindTexture(GL_TEXTURE_2D, names[0]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	glBindTexture(GL_TEXTURE_2D, 0);
	image_done(image);
}