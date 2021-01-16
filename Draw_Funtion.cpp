#include "Draw_Funtion.h"

void draw_funtion::draw_line(float O_x, float O_y, float E_x, float E_y){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0.0);
	glVertex3f(2, 0, 0.0);
	glEnd();
	glFlush();
}
