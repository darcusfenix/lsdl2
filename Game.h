#include "Asteroide.h"
#include <SDL2/SDL.h>
#include <vector>
#ifndef __Game__
#define __Game__
class Game
{
	public:
		Game(int);
		~Game();
		void init(const char*, int, int, int, int, int);
		void render();
		void update(int);
		void handleEvents();
		void clean();
		bool running();
		void setm_bRunning(int);
		void setFrames(int);
		int getFrames();
		int getNumeroAsteroides();
		void preparar();	
		void mover();
		int rdtsc();
		void addAsteroide();
		bool hayCollision();
	private:
		bool m_bRunning;
		int frames;
		int numero_asteroides;
		SDL_Window *win;
		SDL_Renderer *ren;
		std::vector <Asteroide> asteroides;
};
#endif