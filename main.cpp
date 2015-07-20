#include "Game.h"
#include "Vector2D.h"
#include <iostream>
#include <iomanip>
#include <time.h> 


Game* g_game = 0;

int main(int argc, char* argv[])
{
	srand (time(NULL));
	g_game = new Game(atoi(argv[1]));
	g_game -> init("Proyecto 3 - JUAN CRISÓSTOMO VÁZQUEZ :)", 0, 0, 800, 600, SDL_WINDOW_SHOWN);
	
	int frames = 0;
	int start_time = SDL_GetTicks();
	int bandera = 1;
	while(g_game->running())
	{

		frames++;
		if(frames == 1000) {
			std::cout.precision(4);
		 	std::cout << "FPS: "<< std::setw(2) << (float)frames/(SDL_GetTicks()-start_time)*1000 << std::endl;
			frames = 0;
			start_time = SDL_GetTicks();
		 }
		
		g_game->handleEvents();
		
		g_game->update(bandera);	
		bandera++;

		g_game->render();

	}	
	g_game->clean();
	
	return 0;
}
