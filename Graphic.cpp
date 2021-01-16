#include "Graphic.h"
#include <cmath>
#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#define PI 3.1415926

graphic::graphic(){
	for(int i = 0; i<Node_Num; i++)
		for(int j = 0; j<Node_Num; j++)
			distance[i][j] = -1;
	for(int i = 0; i<Node_Num; i++){
		nodes[i].setID(i+1);
		nodes[i].setPoint( \
				Circle_R*(cos(2*PI*i/1000)), \
				Circle_R*(sin(2*PI*i/1000)) \
				);
		distance[i%Node_Num][(i+1)%Node_Num] = 1;
		distance[(i+1)%Node_Num][i%Node_Num] = 1;
	}
}

graphic::~graphic(){;}

void graphic::Dijkstra_Algorithm(int n1, int n2){
	int short_way_table [Node_Num-1][3];
	for(int i = 0; i<Node_Num; i++){
		if(i != n1-1){
			short_way_table[i][0] = i+1;
			short_way_table[i][1] = distance[n1][i];
			if(short_way_table[i][1] != -1)short_way_table[i][2] = n1;
			else short_way_table[i][2] = 0; 
		}
	}
	//do update motion
	//output end
}//n1 ,n2 1~1000
void graphic::GeneratorEdge(int n){
	srand(time (NULL));
	int num1;
	int num2;
	int d;
	for(int i = 0; i<n; i++){
		num1 = rand()%1000;
		num2 = rand()%1000;
		if(distance[num1][num2] == -1 &&  \
				distance [num2][num1] == -1 && \
				num1 != num2){
			d = rand() %100+1;
			distance[num1][num2] = d;
			distance[num2][num1] = d;
		}
		draw_line( \
					nodes[num1].getPointX(), \
					nodes[num1].getPointY(), \
					nodes[num2].getPointX(), \
					nodes[num2].getPointY()
				 );
	}
}
void graphic::ShowGraphic(void){
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
	GeneratorEdge(100);
	glFlush();
	return ;
}
