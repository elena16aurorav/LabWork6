#pragma once

enum COLOR { RED, GREEN, BLUE, WHITE };

class Shape {
	protected:
		COLOR m_color;
		double m_square;
	public:
		Shape();
		Shape(COLOR color1);
		Shape(const Shape& other);
		Shape(Shape&& tmp);
		virtual ~Shape();

		virtual void WhereAmI() const=0;
		virtual void Inflate(int a)= 0;
		virtual void calculateSquare()=0;
};