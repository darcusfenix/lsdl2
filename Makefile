main: main.cpp  Game.o Vector2D.o Asteroide.o Poligonoirreg.o 
	g++ -std=c++0x -std=c++11  main.cpp Asteroide.o Vector2D.o Game.o  Poligonoirreg.o -o main -Wall -lSDL2 
Game.o: Game.cpp Game.h
	g++ -std=c++11 Game.cpp Game.h -c -Wall -lSDL2
Vector2D.o: Vector2D.cpp Vector2D.h
	g++ Vector2D.cpp -c
Asteroide.o: Asteroide.cpp Asteroide.h
	g++ Asteroide.cpp -c
Poligonoirreg.o: Poligonoirreg.cpp Poligonoirreg.h
	g++ Poligonoirreg.cpp -c
clean:
	rm *.o