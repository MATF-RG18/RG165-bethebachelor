#ifndef __BOBAN_HPP__
#define __BOBAN_HPP__ 1

#include <GL/gl.h>


class Boban {
public:
	void draw();
private:
	GLdouble x_position = 0, y_postion = 0, z_position = -3;
	double radius = 2;
};



#endif