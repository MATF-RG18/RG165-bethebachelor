#include "boban.hpp"
#include <cmath>
#include <GL/glut.h>
#include <iostream>

extern GLuint boban_pic;
void Boban::draw() {
	
	glPushMatrix();
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, boban_pic);
	glBegin(GL_POLYGON);
		glTexCoord2f(0, 0);
		glVertex3f(x_position + .3, y_position, z_position);
		glTexCoord2f(1, 0);
		glVertex3f(x_position - .3, y_position, z_position);
		glTexCoord2f(1, 1);
		glVertex3f(x_position - .3, y_position + .5, z_position);
		glTexCoord2f(0, 1);
		glVertex3f(x_position + .3, y_position + .5, z_position);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glTranslatef(x_position, y_position+.2, z_position-3.6);
	glScalef(0.8, 0.7, 10);
	glutSolidCube(.7);
	glPopMatrix();

}


extern float u, y_pos;
extern int jump_active, timer_activeX, direction_keeper;
bool on_head = false;

bool Boban::doesStudentWalkOnMyHead(Student& st) {
	bool A = st.x_front < x_position + .5 and  st.x_front > x_position - .5;
	bool B = st.y_front < y_position + 0.005 and st.y_front > y_position - 1.3;
	bool C = st.z_front < z_position and st.z_front > z_position - 6;
	bool D = st.z_front < z_position - 0.5 and st.z_front > z_position - 10;
	if (A and B and C and !D) {
		//jump_active = 0;
		y_pos = 4.2;
		on_head = true;
	} else if (A and B and C) {
		exit(EXIT_FAILURE);
	}

	return false;
}


void Boban::didStudentLeaveMyHead(Student& st) {

}