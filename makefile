Small_World.out: Node.o Graphic.o Draw_Funtion.o
	g++ main.cpp -o Small_World.out Node.o Graphic.o Draw_Funtion.o -lGL -lGLU -lglut 
Node.o: Node.h Node.cpp
	g++ -c Node.cpp
Graphic.o:Graphic.h Graphic.cpp
	g++ -c Graphic.cpp
Draw_Funtion.o:Draw_Funtion.h Draw_Funtion.cpp
	g++ -c Draw_Funtion.cpp 
clean:
	rm -f Draw_Funtion.o Graphic.o Node.o Small_World.out
