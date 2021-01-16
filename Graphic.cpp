#include "Graphic.h"
#include <cmath>
#include <GL/glut.h>
#define PI 3.1415926

graphic::graphic(){
	for(int i = 0; i<Node_Num; i++){
		nodes[i].setID(i+1);
		nodes[i].setPoint( \
				Circle_R*(2*PI/1000), \
				Circle_R*(2*PI/1000) \
				);
		distance[i%Node_Num][(i+1)%Node_Num] = 1;
		distance[(i+1)%Node_Num][i%Node_Num] = 1;
	}
}

graphic::~graphic(){;}

void graphic::ShowGraphic(void){
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i = 0; i<Node_Num; i++){
		if(i+1<Node_Num){
		draw_line( \
			nodes[i].getPointX(), \
			nodes[i].getPointY(), \
			nodes[i+1].getPointX(), \
			nodes[i+1].getPointY()
			);
		}
		else if(i+1 == Node_Num){
					draw_line( \
			nodes[i].getPointX(), \
			nodes[i].getPointY(), \
			nodes[0].getPointX(), \
			nodes[0].getPointY()
			);

		}
	}
	glFlush();
	return ;
}
