#pragma once
#include "myShape.h"
#include "myRect.h"
#include "myCircle.h"

class Circle: public Shape {
	public:
		int m_centerX;
		int m_centerY;
		double m_radius;

		Circle();
		Circle(int centerX, int centerY, double radius, COLOR color1);
		Circle(const Circle& other);
		Circle(Circle&& tmp);

		~Circle();

		virtual void WhereAmI() const;
		virtual void Inflate(int a);
		virtual void calculateSquare();
		virtual Circle* factoryMethod() const;

		virtual bool operator==(const Shape& other) override;
		virtual Circle* operator = (const Shape& other) override;
		virtual Circle* operator = (Shape&& other) override;

		friend std::ostream & operator<<(std::ostream & os, const Circle & string);
		friend std::ofstream& operator<<(std::ofstream& ofs, const Circle& cir);
};