#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include "callbackfuncs.hpp"
#include "draw.hpp"



extern GLfloat diffuse_coeffs[4];

extern GLfloat specular_coeffs[4];
Camera camera;
int look_id = 1;
int timer_activeX = 0, timer_activeZ = 0;
int jump_active = 0;
float x_pos = 0, z_pos = 0;
float lracceleration = 0.06;





/* Funckija za iscrtavanje figurice,
 * tj loptice u pocetnoj fazi
 */
float tmp_z = 0;
float u = 0;
void drawFigure() {
    glPushMatrix();
	std::cout << tmp_z << std::endl;
    if (tmp_z <= -5){
		tmp_z = 0;
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
