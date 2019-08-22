#ifndef _DRAW_HPP
#define _DRAW_HPP 1

#include "camera.hpp"
#include <string>
#include "figure.hpp"

class Plane {
public:
    void draw();
};

class Student {
    GLdouble angle = 0;
    GLdouble legs_angle = 0;
    int8_t  direction = 1;
public:
    GLdouble x_front, x_back;
    GLdouble y_front, y_back;
    GLdouble z_front, z_back;
    void draw();
};


class Coin {
    std::string professor;
    GLdouble x_front, x_back;
    GLdouble y_front, y_back;
    GLdouble z_front, z_back;
    bool passed = false;
    std::string name;
    GLdouble disk_inner, disk_outer;
    GLuint disk_slices, disk_loops;
    GLdouble cyl_base, cyl_top, cyl_height;
    GLuint cyl_slices, cyl_stacks;
    GLdouble angle = 0;
    float z_position, x_position;
    unsigned inx;
public:
    Coin(const std::string &name, GLdouble disk_inner, GLdouble disk_outer, GLuint disk_slices,
         GLuint disk_loops, GLdouble cyl_base, GLdouble cyl_top, GLdouble cyl_height, GLuint cyl_slices,
         GLuint cyl_stacks, float z_position, float x_positon, std::string professor, unsigned inx);

    void draw();
    std::string getName() {
        return name;
    }
    bool isPassed() {
        return passed;
    }
    void confirmPassed() {
        passed = true;
    }
    std::string getProfessor() {
        return professor;
    }
    bool touched(GLdouble student_x_front, GLdouble student_x_back, GLdouble student_y_front,
                GLdouble student_y_back, GLdouble student_z_front, GLdouble studnet_z_back) const;
};


void change_colour(void);


#endif

