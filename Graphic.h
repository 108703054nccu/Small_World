#ifndef GRAPHIC_H
#define GRAPHIC_H
#include "Node.h"
#include "Draw_Funtion.h"
#define Node_Num 1000
#define Circle_R 1
class graphic:public draw_funtion{
	public:
		graphic();
		~graphic();
		void GeneratorEdge(int);
		void ShowGraphic(void);
		void Dijkstra_Algorithm(int, int);
	private:
		node nodes[Node_Num];
		int distance[Node_Num][Node_Num];
};


#endif //GRAPHIC_H
