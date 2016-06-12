#include "myShape.h"
#include <iostream>
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

