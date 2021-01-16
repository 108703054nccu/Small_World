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
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Draw_Result");
	glutDisplayFunc(displayMe);
	glutMainLoop();
	return 0;
}
