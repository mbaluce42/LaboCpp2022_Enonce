


Test1:		Test1.cpp Modele.o
			g++ Test1.cpp Modele.o -o Test1

Modele.o:	Modele.cpp Modele.h
			g++ Modele.cpp -c