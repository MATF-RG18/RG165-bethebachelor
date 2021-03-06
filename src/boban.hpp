#ifndef __BOBAN_HPP__
#define __BOBAN_HPP__

#include <GL/gl.h>
#include "figure.hpp"




class Boban {
public:
	void draw();
	bool doesStudentWalkOnMyHead(Student& st);
	void didStudentLeaveMyHead(Student& st);
	void setX(float x) {
		x_position = x;
	}
	void setZ(float z) {
		z_position = z;
	}
	bool isReady() {
		return ready;
	}
	void setReady() {
		ready = true;
	}
private:
	GLdouble x_position, y_position = 2.5, z_position;
	bool ready = false;
};



#endif