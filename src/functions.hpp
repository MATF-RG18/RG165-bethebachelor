#ifndef __FUNCTIONS_HPP__
#define __FUNCTIONS_HPP__

#include <vector>
#include "figure.hpp"
#include "image.hpp"
#include <GL/glut.h>



typedef enum {first, second, third, fourth}YEAR;
typedef enum {start, game, over}STATE;
void initialize_texture();
void draw_coins();
void test_collision(std::vector<Coin*>&);
void draw_score(const char* score, int length, int x, int y);
void fill_vector_of_courses(std::vector<Coin*>& vYear);
void show_start_scene();
void show_end_scene();

#endif
