#ifndef NODE_H
#define NODE_H
#include <vector>
class node{	
	public:
		node();
		~node();
		void setID(int);
		int getID();
		void setPoint(float, float);
		float getPointX();
		float getPointY();
	private:
		int Id;
		float PointX;
		float PointY;
};

#endif //NODE_H
