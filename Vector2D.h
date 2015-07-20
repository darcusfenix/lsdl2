#ifndef VECTOR2D_H_
#define VECTOR2D_H_
#include <cmath>
class Vector2D
{
	public:

		Vector2D(long double, long double);
		Vector2D(void);
		long double getX();
		long double getY();
		void setX(long double x);
		void setY(long double y);
		long double length(Vector2D);
		void normaliza();

		//Sobrecarga para adición de 2 vectores
		Vector2D operator+(const Vector2D& v2) const {
			return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
		}

		friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2){
			v1.m_x += v2.m_x;
			v1.m_y += v2.m_y;
			return v1;
		}
		//Sobrecara para multiplicar un vector por un escalar
		Vector2D operator*(long double scalar){
			return Vector2D(m_x * scalar, m_y * scalar);
		} 
		Vector2D& operator*=(long double scalar){
			m_x *= scalar;
			m_y *= scalar;
			return *this;
		}
	private:
		long double m_x;
		long double m_y;
};
#endif