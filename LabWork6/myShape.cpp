#include "myShape.h"
#include <iostream>
#include <fstream>

using namespace std;

Shape::Shape() {
	this->m_color = WHITE;
};
Shape::Shape(COLOR color1) {
	this->m_color = color1;
};

//Конструкторы копирования
Shape::Shape(const Shape& other) {
	this->m_color = other.m_color;
};

Shape::Shape(Shape&& tmp) {
	this->m_color = tmp.m_color;
};
/////////////////////////////////////

Shape::~Shape() {
	cout << "Now I am in Shape's destructor!" << endl;
};

double Shape::getSquare() const {
	return this->m_square;
};

COLOR Shape::getColor() const {
	return this->m_color;
};

std::ostream& operator<<(std::ostream& os, const Shape& string)
{
	os << string.m_color;
	return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const Shape& shape)
{
	switch (shape.getColor())
	{
	case RED:
		ofs << 0;
		break;
	case GREEN:
		ofs << 1;
		break;
	case BLUE:
		ofs << 2;
		break;
	case WHITE:
		ofs << 3;
		break;
	}
	return ofs;
}