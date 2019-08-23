#ifndef __BOBAN_HPP__
#define __BOBAN_HPP__ 1

#include <GL/gl.h>
#include "figure.hpp"


class Boban {
public:
	void draw();
	bool doesStudentWalkOnMyHead(Student& st);
private:
	GLdouble x_position = 0, y_position = 2.5, z_position = -10;
	double radius = 2;
};



#endif