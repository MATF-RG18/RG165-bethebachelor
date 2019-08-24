#include <memory.h>
#include "functions.hpp"
#include <iostream>
#include <random>


bool gen_coins1 = false, gen_coins2 = false, gen_coins3 = false, gen_coins4 = false;
int increment = 0;
int sub_inx = 0;
unsigned polozeno_ove_godine = 0, ostalo_ispita_za_ovu_godinu = 10;
extern float z_pos;
bool game_over = false;

GLuint names[40];
GLuint parquet;
GLuint boban_pic;
GLuint matf_pic;


std::vector<Coin*> vYear1(10);
std::vector<Coin*> vYear2(10);
std::vector<Coin*> vYear3(10);
std::vector<Coin*> vYear4(10);



std::vector<std::string> courses = {
        "UOAR1", "LAAG", "P1", "DS1", "EJ1",
        "UOAR2", "A1", "P2", "DS2", "EJ2",
        "G", "OS", "AISP", "A2", "UVIT",
        "ALG", "A3", "OOP", "KIAA", "ASTRO",
        "RBP", "UNM", "PPJ", "V", "RG",
        "S", "IP1", "VI", "PP", "KK",
        "RM", "RI", "IP2", "RS", "DS3",
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


void initialize_texture() {
    Image* image;

    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glGenTextures(40, names);
    glGenTextures(1, &parquet);
	glGenTextures(1, &boban_pic);
	glGenTextures(1, &matf_pic);
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
    std::string name = "../src/images/parquet.bmp";
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



	image = image_init(0, 0);
    std::string boban_name = "../src/images/boban_kao.bmp";
    image_read(image, strdup(boban_name.c_str()));

    glBindTexture(GL_TEXTURE_2D, boban_pic);
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

	image = image_init(0, 0);
    std::string matf_logo = "../src/images/welcome.bmp";
    image_read(image, strdup(matf_logo.c_str()));

    glBindTexture(GL_TEXTURE_2D, matf_pic);
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

extern Student student;
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
        ostalo_ispita_za_ovu_godinu = 10 - polozeno_ove_godine;
        if (ostalo_ispita_za_ovu_godinu > 2) {
            student.setDebt(student.getDebt() + 144000);
        } else {
            student.setDebt(student.getDebt() + ostalo_ispita_za_ovu_godinu * 2350);
        }

        if (student.getDebt() > 500000) {
            game_over = true;
            exit(EXIT_FAILURE);
        }

        polozeno_ove_godine = 0;
        change_colour();
        increment += 55;
        bool finishedYear = true;
        for (auto it: *vYear)
            if(!it->isPassed())
                finishedYear = false;

        if (finishedYear) {
            year = ++year;
            ostalo_ispita_za_ovu_godinu = 10;
        }
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


    for (auto course: *vYear)
        if (!course->isPassed())
            course->draw();

    test_collision(*vYear);
}

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



void test_collision(std::vector<Coin*>& vYear) {
    for (auto course: vYear) {
        if (course->touched(student.x_front, student.x_back, student.y_front, student.y_back,
                            student.z_front, student.z_back)) {
            course->confirmPassed();
            polozeno_ove_godine++;
        }
    }
}


void show_start_scene() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, matf_pic);
    glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);

    glTexCoord2f(0, 0);
    glVertex3f(-5, -3, 0);

    glTexCoord2f(1, 0);
    glVertex3f(4.5, -3, 0);

    glTexCoord2f(1, 1);
    glVertex3f(4.5, 3, 0);

    glTexCoord2f(0, 1);
    glVertex3f(-5, 3, 0);

    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
}
