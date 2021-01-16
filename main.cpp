#include <iostream>
#include "Graphic.h"
void displayMe(void)
{
	graphic g;
	g.ShowGraphic();
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
