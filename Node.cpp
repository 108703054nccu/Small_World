#include "Node.h"

node::node(){
	Id = 0;
	PointX = 0.0f;
	PointY = 0.0f;	
}

node::~node(){;}

void node::setID(int i){
	Id = i;
	return ;
}

int node::getID(){
	return Id;
}

void node::setPoint(float x, float y){
	PointX = x;
	PointY = y;
	return ;
}

float node::getPointX(){
	return PointX;
}

float node::getPointY(){
	return PointY;
}
