#include <GL/glut.h>
#include <iostream>
#include <random>
#include <memory.h>
#include "figure.hpp"
#include "light.hpp"
#include "callbackfuncs.hpp"

static int window_width, window_height;
extern float ind_for_colors;
Plane plane;
Student student;
typedef enum {first, second, third, fourth}YEAR;
YEAR year = first;

YEAR operator++(YEAR& year) {
    if (year == first)
        year = second;
    else if (year == second)
        year = third;
    else if (year == third)
        year = fourth;
    return year;
}

bool gen_coins1 = false, gen_coins2 = false, gen_coins3 = false, gen_coins4 = false;
unsigned courses_left = 40;
int increment = 0;

int sub_inx = 0;

std::vector<std::string> courses = {
        "UOAR1", "LAAG", "P1", "DS1", "EJ1",
        "UOAR2", "A1", "P2", "DS2", "EJ2",
        "G", "OS", "AISP", "A2", "UVIT",
        "ALG", "A3", "OOP", "KIAA", "ASTRO",
        "RBP", "UNM", "PPJ", "V", "RG",
        "S", "IP1", "VI", "PP", "KK",
        "RM", "RI", "IP2", "RS", "DS3"
        "UUTZ", "FP", "PROJBP", "UIDT", "PZV"
};


std::vector<std::string> professors = {
        "jovanaKovacevic", "zoranRakic", "predragJanicic", "slavkoMoconja", "zoranPavlovic",
        "jovanaKovacevic", "aleksandarVucic", "predragJanicic", "zoranStanic", "zoranPavlovic",
        "tijanaSukilovic", "miroslavMaric", "miodragZivkovic", "branislavPrvulovic", "vladimirFilipovic",
        "zoranPetrovic", "aleksandraMarinkovic", "aleksandarKartelj", "vesnaMarinkovic", "andjelkaKovacevic",
        "nenadMaric", "aleksandraDelic", "milanBankovic", "milanJovanovic", "vesnaMarinkovic",
        "bojanaMilosevic", "nenadMaric", "predragJanicic", "milenaJanicic", "filipMaric",
        "aleksandarKartelj", "aleksandarKartelj", "nenadMaric", "sasaMalkov", "aleksandarSavic",
        "lenkaZivadinovic", "sasaMalkov", "sasaMalkov", "filipMaric", "vladimirFilipovic"
};



std::vector<Coin*> vYear1(10);
std::vector<Coin*> vYear2(10);
std::vector<Coin*> vYear3(10);
std::vector<Coin*> vYear4(10);



//Ova funkcija je manje-vise prepisana sa nekog klipa na YT.
void draw_score(const char* score, int length, int x, int y) {
    glMatrixMode(GL_PROJECTION);
    double *matrix = new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    glOrtho(0, 600, 0, 600, -5, 5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x, y);
    for (int i = 0; i < length; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, score[i]);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
}


void fill_vector_of_courses(std::vector<Coin*>& vYear) {

    for (int i = 0; i < vYear.size(); i++) {
        std::random_device rd;
        std::uniform_real_distribution<> distZ(-55 - increment, -3 - increment);
        std::uniform_real_distribution<> distX(-2.5, 2.5);
        float z_coord = distZ(rd);
        float x_coord = distX(rd);
        if (vYear[i] != nullptr and !vYear[i]->isPassed()) {
            delete vYear[i];
            vYear[i] = new Coin(courses[sub_inx], 0, .3, 20, 20, .3, .3, .2, 20, 20, z_coord, x_coord, professors[sub_inx], sub_inx++);
        } else if (vYear[i] == nullptr) {
            vYear[i] = new Coin(courses[sub_inx], 0, .3, 20, 20, .3, .3, .2, 20, 20, z_coord, x_coord, professors[sub_inx], sub_inx++);
        }
        else
            sub_inx++;
    }
}

void on_reshape(int width, int height) {
    window_width = width;
    window_height = height;
}


extern GLuint head;
void on_display(void) {


    setLight();
    setMaterial();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, window_width, window_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width / (float)window_height,
            1, z_pos
    );
    camera.setLook(look_id);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);



    plane.draw();
    student.draw();


    draw_coins();


    std::string buffer("Ostalo ti je jos ");
    buffer += std::to_string(courses_left) + " ispita do kraja.\n";

    draw_score(buffer.data(), buffer.size(), 0, 580);
    glPopMatrix();
    glutSwapBuffers();
}

void test_collision(std::vector<Coin*>& vYear) {
    for (auto course: vYear) {
		if (course->touched(student.x_front, student.x_back, student.y_front, student.y_back,
                            student.z_front, student.z_back))
            course->confirmPassed();
    }
}


void draw_coins() {
    bool gen_coins;
    std::vector<Coin*>* vYear;
    switch (year) {
        case first:
            gen_coins = gen_coins1;
            vYear = &vYear1;
            break;
        case second:
            gen_coins = gen_coins2;
            vYear = &vYear2;
            break;
        case third:
            gen_coins = gen_coins3;
            vYear = &vYear3;
            break;
        case fourth:
            gen_coins = gen_coins4;
            vYear = &vYear4;
            break;
    }

    if (-0.01 - increment >= z_pos and z_pos > -55 - increment) {
        if (!gen_coins) {
            fill_vector_of_courses(*vYear);
            switch (year) {
                case first:
                    gen_coins1 = true;
                    break;
                case second:
                    gen_coins2 = true;
                    break;
                case third:
                    gen_coins3 = true;
                    break;
                case fourth:
                    gen_coins4 = true;
                    break;
            }
        }
    } else {
        change_colour();
        increment += 55;
        bool finishedYear = true;
        for (auto it: *vYear)
            if(!it->isPassed())
                finishedYear = false;

        if (finishedYear) {
            year = ++year;
        }
        else {
            switch (year) {
                case first:
                    gen_coins1 = false;
                    sub_inx = 0;
                    break;
                case second:
                    gen_coins2 = false;
                    sub_inx = 10;
                    break;
                case third:
                    gen_coins3 = false;
                    sub_inx = 20;
                    break;
                case fourth:
                    gen_coins4 = false;
                    sub_inx = 30;
                    break;
            }
        }
    }


    for (auto course: *vYear)
        if (!course->isPassed())
            course->draw();

    test_collision(*vYear);
}

void on_keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27: exit(0); break;
        case 'a': case 'A':
            if (timer_activeX == 0)
                glutTimerFunc(450, on_timer, 0);
            timer_activeX = -1;
            break;
        case 'd': case 'D':
            if (timer_activeX == 0)
                glutTimerFunc(450, on_timer, 0);
            timer_activeX = 1;
            break;
        case 'w': case 'W':
            if (timer_activeZ == 0)
                glutTimerFunc(50, on_timer2, 0);
            timer_activeZ = 1;
            break;
        case 'x': case 'X':
            timer_activeX = 0;
            timer_activeZ = 0;
            break;
        case 'q': case 'Q':
            jump_active = 1;
            direction_keeper = timer_activeX;
            timer_activeX = 0;
            glutPostRedisplay();
            break;
        case '1':
            if (look_id != 1)
                glutPostRedisplay();
            look_id = FIRST_VIEW;
            break;
        case '2':
            if (look_id != 2)
                glutPostRedisplay();
            look_id = SECOND_VIEW;
            break;
        case '3':
            if (look_id != 3)
                glutPostRedisplay();
            look_id = THIRD_VIEW;

            break;
    }
}


void on_timer(int value) {
    if (value != 0)
        return;
    x_pos += (timer_activeX * lracceleration);
    glutPostRedisplay();
    if (x_pos <= -3 || x_pos >= 3)
        exit(EXIT_FAILURE);

    if (timer_activeX and timer_activeZ)
        glutTimerFunc(50, on_timer, 0);

}

/*
 * 2.tajmer sluzi za pokretanje animacije duz pravca Z - ose
*/

void on_timer2(int value) {
    if (value != 0)
        return;
    z_pos += (-timer_activeZ * .095);
	ind_for_colors += (-timer_activeZ * .095);
    glutPostRedisplay();
    if (timer_activeZ != 0)
        glutTimerFunc(50, on_timer2, 0);
}


void init_callbacks(void) {
    glutKeyboardFunc(on_keyboard);
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);
}


GLuint names[40];
GLuint parquet;

void initialize_texture() {
	Image* image;
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glGenTextures(40, names);
	glGenTextures(1, &parquet);

    for (int i = 0; i < professors.size(); i++) {
        image = image_init(0, 0);
        std::string name = "../src/images/" + professors[i] + ".bmp";
        image_read(image, strdup(name.c_str()));

        glBindTexture(GL_TEXTURE_2D, names[i]);
        glTexParameteri(GL_TEXTURE_2D,
                        GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D,
                        GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D,
                        GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,
                        GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                     image->width, image->height, 0,
                     GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
        image_done(image);
    }
	
	
	
	image = image_init(0, 0);
	std::string name = "../src/images/parket.bmp";
	image_read(image, strdup(name.c_str()));

	glBindTexture(GL_TEXTURE_2D, parquet);
	glTexParameteri(GL_TEXTURE_2D,
					GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D,
					GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D,
					GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,
					GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
				 image->width, image->height, 0,
				 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	image_done(image);


}
