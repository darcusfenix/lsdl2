#include "Game.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

const long double PI = acosl(-1.0); 
Game::Game(int cantidad): numero_asteroides(cantidad)
{

}
void Game::init(const char* titulo, int xpos, int ypos, int alto, int ancho, int banderas){
	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow(titulo, xpos, ypos, alto, ancho, banderas);
	ren = SDL_CreateRenderer(win, -1, 0);
	frames = 0;
	setm_bRunning(1);
}
void Game::setm_bRunning(int mb)
{
	m_bRunning = mb;
}
void Game::setFrames(int f)
{
	frames = f;
}
int Game::getFrames()
{
	return frames;
}
int Game::getNumeroAsteroides()
{
	return numero_asteroides;
}
void Game::addAsteroide(){
	Asteroide* asteroide;
	long double x, y, angle;	

	int MAX_VERT = 5 + (rand() % (int)(20 - 5 + 1));
    int diametro = 1 + (rand() % (int)(100 - 1 + 1));

    asteroide = new Asteroide(MAX_VERT);

    int POSICION_X = rand()%800;
	int POSICION_Y = rand()%600;

	

	asteroide -> setDiametro(diametro);
	asteroide -> setTipoDireccion(rand()%7);
	asteroide -> setVelocidad(200 / diametro);

	for( int w = 0; w < asteroide -> getNumeroVertices(); w++)
    {
        angle = 360.0/asteroide -> getNumeroVertices();
        int variacion  = int(0.3 * ( asteroide -> getDiametro() + 1) );
        x = cosl(w * angle*PI/180.0) * (asteroide -> getDiametro()) + POSICION_X + rand()%variacion;
        y = sinl(w * angle*PI/180.0) * (asteroide -> getDiametro()) + POSICION_Y + rand()%variacion;
			        
        asteroide -> addVertice(Vector2D(x, y), w);
		if (w == 0)
			asteroide -> addVertice(Vector2D(x, y), asteroide -> getNumeroVertices());
    }
    asteroides.emplace_back(*asteroide);
}
void Game::preparar(){
	for (int i = 0; i < numero_asteroides; i++){
		addAsteroide();
	}
}
bool Game::hayCollision(){
	if(asteroides.size() >= 0){
		for (int i = 0; i < asteroides.size(); i++){
			SDL_Point* puntos_asteroide =  asteroides[i].getPoints();
			for(int j = 0; j < asteroides.size(); j++){
				if( i != j){
					SDL_Point* puntos_asteroide_temp =  asteroides[j].getPoints();
				}
			}
		}
	}
}
void Game::mover(){
	if(asteroides.size() <= 0)
	{
		return;
	}
	for (int i = 0; i < asteroides.size(); i++)
	{
	
		SDL_Point* points =  asteroides[i].getPoints();	
		
		for( int w = 0; w <= asteroides[i].getNumeroVertices(); w++)
	    {

			switch ( asteroides[i].getTipoDireccion() )
			{
				case 0:
					points[w].x += asteroides[i].getVelocidad();
	    			points[w].y -= asteroides[i].getVelocidad();
					break;
				case 1:
					points[w].x += asteroides[i].getVelocidad();
					break;
				case 2:
					points[w].x += asteroides[i].getVelocidad();
	    			points[w].y += asteroides[i].getVelocidad();
					break;
	    		case 3: 
	    			points[w].y += asteroides[i].getVelocidad();
					break;
	    		case 4:
	    			points[w].x -= asteroides[i].getVelocidad();
	    			points[w].y += asteroides[i].getVelocidad();
					break;
	    		case 5: 
	    			points[w].x -= asteroides[i].getVelocidad();
					break;
	    		case 6:
	    			points[w].x -= asteroides[i].getVelocidad();
	    			points[w].y -= asteroides[i].getVelocidad();
					break;
	    		case 7:
	    			points[w].y -= asteroides[i].getVelocidad();
					break;
				default:
					points[w].x += 0;
	    			points[w].y += 0;
					break;
			}
			
	    	if ( (points[w].y > 0  && points[w].y < 600) || (points[w].x > 0  && points[w].x < 800) )
	    		asteroides[i].setDentro(true);
	    	else
	    		asteroides[i].setDentro(false);

	    }
	    asteroides[i].setPoints(points);
	    SDL_Delay(3);
	}
}
void Game::render()
{

	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
	SDL_RenderClear(ren);
	SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
	
	SDL_SetRenderDrawColor(ren, rand()%255, rand()%255, rand()%255, rand()%255);

	if(asteroides.size() > 0)
		for (int i = 0; i < asteroides.size(); i++)
			SDL_RenderDrawLines(ren, asteroides[i].getPoints(), asteroides[i].getNumeroVertices() + 1);
		
	SDL_RenderPresent(ren);
	return;
	
}
void Game::update(int a)
{
	if (a == 1){
		preparar();
	}
	else{
		if(asteroides.size() >= 0){
			for (int i = 0; i < asteroides.size(); i++){
				if (!asteroides[i].estaDentro())
				{
					asteroides.erase(asteroides.begin() + i);	
					addAsteroide();
					addAsteroide();
				}
			}
		}
		hayCollision();
		mover();
	}

	
}
void Game::handleEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		if(event.type == SDL_WINDOWEVENT)
			if(event.window.event == SDL_WINDOWEVENT_CLOSE)
				setm_bRunning(0);
	}
}
void Game::clean()
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();		
}
bool Game::running()
{
	return m_bRunning;
}
