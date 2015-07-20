#include "Asteroide.h"
#include <cstdlib>
#include <iostream>
Asteroide::Asteroide(int cantidadVertices): numVertices(cantidadVertices)
{
	points = new SDL_Point[cantidadVertices + 1];
	dentro = true;
}
Asteroide::~Asteroide() {
    
}
void Asteroide::addVertice(Vector2D vector, int i)
{
	vertices.push_back(vector);
 	SDL_Point p;
	p.x = vector.getX();
	p.y = vector.getY();
	points[i] = p;
}
SDL_Point* Asteroide::getPoints(){
	return points;
}
int Asteroide::getNumeroVertices(){
	return numVertices;
}
void Asteroide::setPoints(SDL_Point* nuevosPuntos){
	points = nuevosPuntos;
}
int Asteroide::getDiametro(){
	return diametro;
}
void Asteroide::setDiametro(int valor){
	diametro = valor;
}
int Asteroide::getTipoDireccion(){
	return tipo_direccion;
}
void Asteroide::setTipoDireccion(int valor){
	tipo_direccion = valor;
}
long double Asteroide::getVelocidad(){
	return velocidad;
}
int Asteroide::getMasa(){
	return masa;
}
void Asteroide::setVelocidad(long double valor){
	velocidad = valor;
}
void Asteroide::setMasa(int valor){
	masa = valor;
}
bool Asteroide::estaDentro(){
	return dentro;
}
void Asteroide::setDentro(bool valor){
	dentro = valor;
}