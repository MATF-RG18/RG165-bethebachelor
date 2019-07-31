#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include "callbackfuncs.hpp"
#include "draw.hpp"



extern GLfloat diffuse_coeffs[7][4];

extern GLfloat specular_coeffs[4];
Camera camera;
int look_id = 3;
int timer_activeX = 0, timer_activeZ = 0;
int jump_active = 0;
float x_pos = 0, z_pos = 0;
float lracceleration = 0.06;
int colour_counter = 0;




/* Funckija za iscrtavanje figurice,
 * tj loptice u pocetnoj fazi
 */
float tmp_z = 0;
float u = 0;
void drawFigure() {
    glPushMatrix();
	//std::cout << tmp_z << std::endl;
    if (tmp_z <= -5){
		tmp_z = 0;
        change_colour();
    }

    if (jump_active) {
        glTranslatef(x_pos, .2 + sin(u), z_pos);
        u += .1;
    }
    else glTranslatef(x_pos, .2, z_pos);


    if (jump_active == 1 and u >= 3.14) {
        jump_active = 0;
        u = 0;
    }

    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs[colour_counter]);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glutSolidSphere(.1, 20, 20);
    glPopMatrix();
}


void change_colour(void) {
    colour_counter = (colour_counter + 1) % 7;
}


void drawPlane() {
    std::cout << z_pos << std::endl;


    glPushMatrix();
    glTranslatef(0, 0, z_pos);
    glScalef(1.5, .05, 25);

    glutSolidCube(4);
    glPopMatrix();
}
