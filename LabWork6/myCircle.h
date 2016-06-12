#pragma once
#include "myShape.h"
#include "myRect.h"

class Circle: public Shape {
	public:
		int m_centerX;
		int m_centerY;
		double m_radius;

		Circle();
		Circle(int centerX, int centerY, double radius, COLOR color1);
		Circle(const Rect& other);

		~Circle();

		virtual void WhereAmI() const;
		virtual void Inflate(int a);
		virtual void calculateSquare();
};