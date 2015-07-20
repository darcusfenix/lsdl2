#ifndef ASTEROIDE_H_
#define ASTEROIDE_H_
#include "Poligonoirreg.h"
#include "Vector2D.h"
#include <vector>
#include <SDL2/SDL.h>
class Asteroide : public Poligonoirreg
{
	public:
		Asteroide(int);
		~Asteroide();
		SDL_Point* getPoints();
		void updatePosition(float, float);
		void erase();
		void addVertice(Vector2D, int);
		void setPoints(SDL_Point*);
		int getNumeroVertices();
		int getDiametro();
		int getTipoDireccion();
		int getMasa();
		bool estaDentro();
		void setDiametro(int);
		void setTipoDireccion(int);
		void setVelocidad(long double);
		void setMasa(int);
		void setDentro(bool);
		long double getVelocidad();
	private:
		std::vector <Vector2D> vertices;
		int numVertices;
		long double angle;
		SDL_Point* points;
		int diametro;
		int tipo_direccion;
		long double velocidad;
		int masa;
		bool dentro;
};
#endif