#ifndef _DRAW_HPP
#define _DRAW_HPP

#include "camera.hpp"

Camera camera;
int look_id = 1;
int timer_activeX = 0, timer_activeZ = 0;
int jump_active = 0;
float x_pos = 0, z_pos = 0;
float lracceleration = 0.06;

void drawFigure();
void shuffle_colours(void);
void drawPlane();

#endif
