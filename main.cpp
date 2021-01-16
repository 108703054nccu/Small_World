#include <iostream>
#include "Graphic.h"
void displayMe(void)
{
	//graphic g;
	//g.ShowGraphic();;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(15.0, 0.0, 0.0);
	//glVertex3f(0.0, 0.5, 0.0);
	//glVertex3f(0.0, 0.0, 0.5);
	glEnd();
	glFlush();
}
int main(int argc, char** argv){
	graphic g;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Draw_Result");
	glutDisplayFunc(displayMe);
	glutMainLoop();
	return 0;
}
