#include "Graphic.h"
#include <cmath>
#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
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
	int short_path_table[Node_Num][2];
	int dismatrix[Node_Num][Node_Num];
	int minpoint = n1;
	int minedge = INT_MAX; 
	for(int i = 0; i<Node_Num; i++){
		if( i+1 == n1){
			short_path_table[i][0] = n1;
			short_path_table[i][1] = 0; 
		}
		short_path_table[i][0] = i+1;
		short_path_table[i][1] = INT_MAX; 
	}
	for(int i = 0; i<Node_Num; i++){
		for(int j = 0; j<Node_Num; j++){
			dismatrix[i][j] = distance[i][j];
		}
	}
	while(minpoint != n2){
		for(int i = 0; i<Node_Num; i++){
			if(short_path_table[i][1] >= 0){
				if(dismatrix[i][minpoint-1] > 0 && \
						dismatrix[i][minpoint-1]+short_path_table[minpoint-1][1] < \
						short_path_table[i][1]){
					short_path_table[i][1] = \
								 dismatrix[i][minpoint-1]+short_path_table[minpoint-1][1]; 
				}	
				dismatrix[i][minpoint-1] = -2;
				dismatrix[minpoint-1][i] = -2;
			}
		}
		short_path_table[minpoint-1][1] = -1;
		for(int i =0; i<Node_Num ;i++){
			if(short_path_table[i][1] >= 0 && \
					short_path_table[i][1] < minedge){
				minpoint = i+1; 
			}
		}
	}

	std::cout<<short_path_table[minpoint][1];
}//n1 ,n2 1~1000;ischanged = -2;not arrive = -1
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
	Dijkstra_Algorithm(1, 200);
	glFlush();
	return ;
}
