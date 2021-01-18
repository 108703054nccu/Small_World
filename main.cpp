#include <iostream>
#include "Graphic.h"
void displayMe(void){
	graphic g;
	g.ShowGraphic();
}
int main(int argc, char** argv){
	graphic g;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Draw_Result");
	glutDisplayFunc(displayMe);
	glutMainLoop();
	return 0;
}
