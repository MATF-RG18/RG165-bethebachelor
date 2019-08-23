#include "boban.hpp"
#include <cmath>
#include <GL/glut.h>

extern GLuint boban_pic;
void Boban::draw() {
	
	glPushMatrix();
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, boban_pic);
	glBegin(GL_POLYGON);
		glTexCoord2f(0, 0);
		glVertex3f(x_position + .5, y_position, z_position);
		glTexCoord2f(1, 0);
		glVertex3f(x_position - .5, y_position, z_position);
		glTexCoord2f(1, 1);
		glVertex3f(x_position - .5, y_position + .5, z_position);
		glTexCoord2f(0, 1);
		glVertex3f(x_position + .5, y_position + .5, z_position);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glTranslatef(x_position, y_position+.2, z_position-1.2);
	glScalef(1.2, 0.7, 3);
	glutWireCube(.7);
	glPopMatrix();
	//glTranslatef(-x_position, -y_position, -z_position);
}



bool Boban::didStudentPunchMeInTheFace(Student& st) {
	return false;
}