//
// Created by nikjan on 3/11/19.
//

#ifndef __CALLBACKFUNCS_HPP__
#define __CALLBACKFUNCS_HPP__

#include "camera.hpp"

#define FIRST_VIEW (1)
#define SECOND_VIEW (2)
#define THIRD_VIEW (3)







void on_reshape(int width, int height);
void on_display(void);
void on_keyboard(unsigned char key, int x, int y);
void on_timer(int value);
void init_callbacks(void);

void on_timer2(int value);


#endif
