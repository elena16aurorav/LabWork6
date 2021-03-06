#pragma once
#include <ostream>
#include <fstream>

enum COLOR { RED, GREEN, BLUE, WHITE };

class Shape {
	protected:
		COLOR m_color;
public:
		double m_square;
	//public:
		Shape();
		Shape(COLOR color1);
		Shape(const Shape& other);
		Shape(Shape&& tmp);
		virtual ~Shape();

		virtual void WhereAmI() const=0;
		virtual void Inflate(int a)= 0;
		virtual void calculateSquare() = 0;
		virtual Shape* factoryMethod() const = 0;
		virtual bool operator==(const Shape& other) = 0;
		virtual Shape* operator= (const Shape& other) = 0;
		virtual Shape* operator= (Shape&& other) = 0;
		double getSquare() const;
		COLOR getColor() const;

		friend std::ostream& operator<<(std::ostream& os, const Shape& string);
		friend std::ofstream& operator<<(std::ofstream& ofs, const Shape& cir);
};