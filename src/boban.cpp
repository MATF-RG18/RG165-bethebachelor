#include <cmath>
#include <iostream>
#include "boban.hpp"
#include "functions.hpp"

bool on_head = false;

extern STATE state;
extern bool win, downing;
extern float u, y_pos;
extern int jump_active, timer_activeX, direction_keeper;
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
	glutWireCube(.7);
	glPopMatrix();

}


//Provera da li je student skocio na gredu ili udario u nju 
//ili nista od ta dva
bool Boban::doesStudentWalkOnMyHead(Student& st) {
	bool A = st.x_front < x_position + .5 and  st.x_front > x_position - .5;
	bool B = st.y_front < y_position + 0.005 and st.y_front > y_position - 1.3;
	bool C = st.z_front < z_position and st.z_front > z_position - 6;
	bool D = st.z_front < z_position - 0.5 and st.z_front > z_position - 6;
	
	std::cout << A << B << C << std::endl;
	if (A and B and C and !D) {
		y_pos = 4.2;
		on_head = true;
	} else if (A and B and C) {
		state = over;
		win = false;
	}

	return false;
}

//Provera da li je i kad pao sa grede
void Boban::didStudentLeaveMyHead(Student& st) {
	bool A = st.z_front < z_position - 7.5;
	bool B = st.x_front > x_position + .5 or st.x_front < x_position - .5;
	if (A or B) {
		on_head = false;
		downing = true;
	}
	if (A) 
		st.setDebt(st.getDebt() / 2);
	
}
