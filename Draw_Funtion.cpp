#include "Draw_Funtion.h"

void draw_funtion::draw_line(float O_x, float O_y, float E_x, float E_y){
	glBegin(GL_LINES);
	glVertex2f(O_x,O_y);
	glVertex2f(E_x,E_y);
	glEnd();
}
