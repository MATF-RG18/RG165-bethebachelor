//
// Created by nikjan on 3/11/19.
//

#ifndef RG165_BETHEBACHELOR_CALLBACKFUNCS_H
#define RG165_BETHEBACHELOR_CALLBACKFUNCS_H

#include "camera.hpp"

#define FIRST_VIEW (1)
#define SECOND_VIEW (2)
#define THIRD_VIEW (3)

static int window_width, window_height;
Camera camera;
int look_id = 1;
int timer_activeX = 0, timer_activeZ = 0;
int jump_active = 0;
float x_pos = 0, tmp_z = 0, z_pos = 0;
float lracceleration = 0.06;
void on_timer2(int value);


void on_reshape(int width, int height);
void on_display(void);
void on_keyboard(unsigned char key, int x, int y);
void on_timer(int value);


#endif //RG165_BETHEBACHELOR_CALLBACKFUNCS_H
