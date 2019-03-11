#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include "draw.hpp"



extern GLfloat diffuse_coeffs[4];

extern GLfloat specular_coeffs[4];

extern float tmp_z, x_pos, z_pos;
extern float lracceleration;


/* Funckija za iscrtavanje figurice,
 * tj loptice u pocetnoj fazi
 */

extern int jump_active;
float u = 0;
void drawFigure() {
    glPushMatrix();
    if (tmp_z <= -5){
        tmp_z += 5;
        lracceleration += .005;
        shuffle_colours();
    }
    if (jump_active) {
        glTranslatef(x_pos, .2 + sin(u), z_pos);
        u += .1;
    } else glTranslatef(x_pos, .2, z_pos);
    if (jump_active == 1 and u >= 3.14) {
        jump_active = 0;
        u = 0;
    }

    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glutSolidSphere(.1, 20, 20);
    glPopMatrix();
}


void shuffle_colours(void) {
    diffuse_coeffs[0] = 1. *rand() / RAND_MAX;
    diffuse_coeffs[1] = 1. * rand() / RAND_MAX;
    diffuse_coeffs[2] = 1. * rand() / RAND_MAX;
}


void drawPlane() {
    glPushMatrix();
    glTranslatef(0, 0, z_pos);
    glScalef(1.5, .05, 25);
    glutSolidCube(4);
    glPopMatrix();
}