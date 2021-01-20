#include "Graphic.h"
#include <cmath>
#include <GL/glut.h>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <vector>
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
struct Node {int b, d;};
bool operator<(Node n1, Node n2) {return n1.d > n2.d;}

int graphic::dijkstra_with_priority_queue(int n1,int n2){
	int src = n1-1;
	int tar = n2-1;
	int d[Node_Num];
	int parent[Node_Num];
	bool visit[Node_Num];
	for (int i=0; i<Node_Num; i++) visit[i] = false;
	for (int i=0; i<Node_Num; i++) d[i] = 1e9;
	std::priority_queue<Node> pq;
	d[src] = 0;
	parent[src] = src;
	pq.push((Node){src, d[src]});
	for (int i=0; i<Node_Num; i++)
	{
		int a = -1;
		while (!pq.empty() && visit[a = pq.top().b])pq.pop();   
		if (a == -1) break;
		visit[a] = true;
		for (int b=0; b<Node_Num; b++)
			if (!visit[b] && d[a] + distance[a][b] < d[b])
			{
				d[b] = d[a] + distance[a][b];
				parent[b] = a;
				pq.push( (Node){b, d[b]} );
			}
	}
	for(int i = 0; i<Node_Num;i++)if(i == tar)return d[i];
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
int graphic::GeneratorEdge(int n){
	srand(time (NULL));
	int num1;
	int num2;
	int d = rand()%10+1;
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
	return d;
}
void graphic::ShowGraphic(void){
	srand( time( NULL));
	int src;
	int tar;
	int dat_num = 0;
	int total_path = 0;
	int total_path_q = 0;
	int edge = 0;
	int length = 0;
	int time_of_array;
	int time_of_queue;
	int a,b;
	std::vector<int> all_in_data_src;
	std::vector<int> all_in_data_tar;
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
	edge = 100;
	length = GeneratorEdge(edge);
	while(std::cin>>src>>tar){
		all_in_data_src.push_back(src);
		all_in_data_tar.push_back(tar);
		dat_num ++;
	}
	a = clock();
	for(int i = 0; i<dat_num; i++)total_path += Dijkstra_Algorithm(all_in_data_src.at(i),all_in_data_tar.at(i));
	b = clock();
	time_of_array = b-a;
	a = clock();
	for(int i = 0; i<dat_num; i++)total_path_q+= dijkstra_with_priority_queue(all_in_data_src.at(i),all_in_data_tar.at(i));
	b = clock();
	time_of_queue = b-a;
	std::cout<<"In araay, X(edge) :"<<edge<< \
		" ;y(length) :"<<length<< \
		" ;z(times) :"<<dat_num<< \
		" ;datas length :"<<total_path/dat_num<< \
		" ;spent (s):"<<time_of_array<<std::endl;
	std::cout<<"In priority queue,X(edge) :"<<edge<< \
		" ;y(length) :"<<length<< \
		" ;z(times) :"<<dat_num<< \
		" ;datas length :"<<total_path_q/dat_num<< \
		" ;spent (s):"<<time_of_queue<<std::endl;
	glFlush();
	return ;
}
