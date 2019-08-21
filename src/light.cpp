#include "light.hpp"
#include <GL/glut.h>
#include <time.h>

#define ARRAY_SIZE 4





GLfloat light_position[ARRAY_SIZE] = {2, 2, 1, 0};
GLfloat light_ambient[ARRAY_SIZE] = {.1, .1, .1, 0};
GLfloat light_diffuse[ARRAY_SIZE] = {.1, .1, .1, 0};
GLfloat light_specular[ARRAY_SIZE] = {.3, .3, .3, 1};

GLfloat ambient_coeffs[ARRAY_SIZE] = {.3, .3, .7, 1};
GLfloat diffuse_coeffs[6][ARRAY_SIZE] = {
        {1, 0, 0},
        {0, 1, 0},
        {5/255.0, 254/255.0, 1},
        {1, 1, 1},
        {1, 14/255.0, 177/255.0},
        {1, 67/255.0, 8 /255.0}
};


        //{.2, .2, .9, 1};
GLfloat specular_coeffs[ARRAY_SIZE] = { .5, 0, 0, 1 };

extern int colour_counter;
void setLight() {
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
}


void setMaterial() {
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs[colour_counter]);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
}
