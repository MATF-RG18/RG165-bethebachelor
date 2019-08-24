#include <GL/glut.h>
#include <iostream>
#include <random>
#include "figure.hpp"
#include "light.hpp"
#include "callbackfuncs.hpp"
#include "functions.hpp"
#include "boban.hpp"




unsigned courses_left = 40;
double forward_acceleration;
float double_speed = 1;
int window_width, window_height;
STATE state = start;
Plane plane;
Student student;
Boban boban;


extern int timer_activeX, timer_activeZ, jump_active, look_id, direction_keeper;
extern float lracceleration, x_pos, z_pos, ind_for_colors;
extern bool win, on_head;
extern Camera camera;
extern YEAR year;


void on_reshape(int width, int height) {
    window_width = width;
    window_height = height;
}

void on_display(void) {

	//Osnovna podesavanja scene
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

	//Ako je jump modu student poseban ugao kamere se aktivira
	if (jump_active) 
		camera.setLook(FOURTH_VIEW);
	else	
		camera.setLook(look_id);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	
	if (state == start) 
		show_start_scene();
	else if (state == game) {
		//Iscrtavanje parketa
		plane.draw();
		
		//Iscrtavanje figurice
		student.draw();

		//Iscrtavanje trenutno dostupnih tokena
		draw_coins();


		//Provera da li je stignuto do 3.nivoa i da li moze da se generise Boban :)
		if (boban.isReady()) {
			boban.draw();
			//Ove metode imaju side effect jer obezbedjuju penjanje na i spustanje sa grede Boban.
			if (!on_head)
				boban.doesStudentWalkOnMyHead(student);
			else 
				boban.didStudentLeaveMyHead(student);
		}
		
		//Pakovanje bafera za ispis rezultata
		std::string buffer("Ostalo ti je jos ");
		buffer += std::to_string(courses_left) + " ispita do kraja.\n";

		std::string buffer2("Tvoj dug je: ");
		buffer2 += std::to_string(student.getDebt()) + "rsd.";

		draw_score(buffer2.data(), buffer2.size(),  0, 440);
		draw_score(buffer.data(), buffer.size(), 0, 580);
	} else {
        z_pos = 0;
        show_end_scene();
    }
    glPopMatrix();
    glutSwapBuffers();
}

void on_keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27: exit(0); break;
        case 'a': case 'A':
            if (timer_activeX == 0 and !jump_active)
                glutTimerFunc(450, on_timer, 0);
            timer_activeX = -1;
            break;
        case 'd': case 'D':
            if (timer_activeX == 0 and !jump_active)
                glutTimerFunc(450, on_timer, 0);
            timer_activeX = 1;
            break;
        case 'w': case 'W':
            if (timer_activeZ == 0 and state == game)
                glutTimerFunc(50, on_timer2, 0);
            timer_activeZ = 1;
            break;
        case 'x': case 'X':
            timer_activeX = 0;
            timer_activeZ = 0;
            break;
        case 'q': case 'Q':
			//Ukljucivanje jump moda i iskljucivanje
			//mogucnosti menjanja x koordinate u toku skoka
			//timer_activeX = 0
			if (!jump_active and !on_head) {
                jump_active = 1;
                direction_keeper = timer_activeX;
                timer_activeX = 0;
                glutPostRedisplay();
            }
            break;
        case 32:
            double_speed = 1.8;
            break;
		case 13:
			state = game;
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

	//Promena x koordinate je moguca samo kad nije u jump modu jer
	//bi u suprotnom skok bio neprirodan
    if (!jump_active) {
        x_pos += (timer_activeX * lracceleration);
        glutPostRedisplay();
    }

	//Provera da li je doslo do sletanja sa staze
    if (x_pos <= -3 || x_pos >= 3) {
		state = over;
		win = false;
        return;
	}
        

    if (timer_activeX and timer_activeZ) {
        glutTimerFunc(50, on_timer, 0);
    }

}

void on_timer2(int value) {
    if (value != 0)
        return;

	//Menjanje brzine u odnosu na nivo
    switch (year) {
        case first:
            forward_acceleration = .1; break;
        case second:
            forward_acceleration = .17; break;
        case third:
            forward_acceleration = .24; break;
        case fourth:
            forward_acceleration = .31; break;
    }

	//Azuriranje z ose
    z_pos += (-timer_activeZ * forward_acceleration * double_speed);
    glutPostRedisplay();
    
	if (timer_activeZ != 0)
        glutTimerFunc(50, on_timer2, 0);
}

void on_up_keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 32:
            double_speed = 1;
    }
}

void init_callbacks(void) {
    glutKeyboardFunc(on_keyboard);
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);
    glutKeyboardUpFunc(on_up_keyboard);
}

