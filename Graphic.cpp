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
			distance[i][j] = 1e9;
	for(int i = 0; i<Node_Num; i++){
		nodes[i].setID(i+1);
		nodes[i].setPoint( \
				Circle_R*(cos(2*PI*i/Node_Num)), \
				Circle_R*(sin(2*PI*i/Node_Num)) \
				);
		distance[i%Node_Num][(i+1)%Node_Num] = 1;
		distance[(i+1)%Node_Num][i%Node_Num] = 1;
	}
}

graphic::~graphic(){;}
int graphic::Dijkstra_Algorithm(int n1,int n2){
	int src = n1 -1;
	int tar = n2 -1;
	int d[Node_Num];       
	int parent[Node_Num];  
	bool visit[Node_Num];  
	for (int i=0; i<Node_Num; i++) visit[i] = false;
	for (int i=0; i<Node_Num; i++) d[i] = 1e9;

	d[src] = 0;
	parent[src] = src;

	for (int k=0; k<Node_Num; k++)
	{
		int a = -1, b = -1, min = 1e9;
		for (int i=0; i<Node_Num; i++)
			if (!visit[i] && d[i] < min)
			{
				a = i;  
				min = d[i];
			}

		if (a == -1) break;     
		if (min == 1e9) break;  
		visit[a] = true;
		for (b=0; b<Node_Num; b++)
			if (!visit[b] && d[a] + distance[a][b] < d[b])
			{
				d[b] = d[a] + distance[a][b];
				parent[b] = a;
			}
	}
	for(int i = 0; i<Node_Num;i++)if(i == tar)return d[i];
}
void graphic::GeneratorEdge(int n){
	srand(time (NULL));
	int num1;
	int num2;
	int d = rand() %100+1;
	for(int i = 0; i<n; i++){
		num1 = rand()%Node_Num;
		num2 = rand()%Node_Num;
		if(distance[num1][num2] == -1 &&  \
				distance [num2][num1] == -1 && \
				num1 != num2){
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
	srand( time( NULL));
	int src;
	int tar;
	int dat_num = 0;
	int total_path = 0;
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
	GeneratorEdge(rand()%200);
	while(std::cin>>src>>tar){
		std::cout<<src<<" "<<tar<<" :"<<Dijkstra_Algorithm(src,tar)<<std::endl;
		dat_num ++;
	}
	//std::cout<<dat_num<<" datas length :"<<total_path/dat_num<<std::endl;
	glFlush();
	return ;
}
