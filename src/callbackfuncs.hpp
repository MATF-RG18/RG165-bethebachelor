//
// Created by nikjan on 3/11/19.
//

#ifndef __CALLBACKFUNCS_HPP__
#define __CALLBACKFUNCS_HPP__

#include <vector>
#include "camera.hpp"
#include "figure.hpp"
#include "image.hpp"

#define FIRST_VIEW (1)
#define SECOND_VIEW (2)
#define THIRD_VIEW (3)


extern Camera camera;
extern int jump_active;
extern int timer_activeX, timer_activeZ;
extern int look_id;
extern float lracceleration, x_pos, z_pos;
extern int direction_keeper;


void initialize_texture();
void draw_coins();
void test_collision(std::vector<Coin*>&);
void draw_score(const char* score, int length, int x, int y);
void fill_vector_of_courses(std::vector<Coin*>& vYear);
void on_reshape(int width, int height);
void on_display(void);
void on_keyboard(unsigned char key, int x, int y);
void on_timer(int value);
void init_callbacks(void);

void on_timer2(int value);



#endif
