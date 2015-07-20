#include "Vector2D.h"
#include <math.h>
const long double PI = acosl(-1.0); 
Vector2D::Vector2D(long double x, long double y): m_x(x), m_y(y)
{
}
Vector2D::Vector2D(){
	Vector2D* vector = 0;
}
long double Vector2D::getX(){
	return m_x;
}
long double Vector2D::getY(){
	return m_y;
}
void Vector2D::setX(long double x){
	m_x = x;
}
void Vector2D::setY(long double y){
	m_y = y;
}
long double Vector2D::length(Vector2D v2){
	return sqrt (pow (v2.m_x - m_x, 2) + pow (v2.m_y - m_y, 2));
}
void Vector2D::normaliza(){
	int modulo = sqrt (pow (m_x, 2) + pow(m_y, 2));
	setX(m_x / modulo);
	setY(m_y / modulo);
}