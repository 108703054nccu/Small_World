#include <iostream>
#include "Graphic.h"
void displayMe(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2f(10, 20);
	glVertex2f(20, 20);
	glEnd();
	glFlush();
}
int main(int argc, char** argv){
	graphic g;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Draw_Result");
	glutDisplayFunc(displayMe);
	glutMainLoop();
	return 0;
}
