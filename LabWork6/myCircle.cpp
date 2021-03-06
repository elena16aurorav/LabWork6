#include "myCircle.h"
#include "myShape.h"
#include <iostream>
#include <fstream>

using namespace std;

Circle::Circle() {
	this->m_centerX = 0;
	this->m_centerY = 0;
	this->m_radius = 0;
};
Circle::Circle(int centerX, int centerY, double radius, COLOR color1):Shape(color1),
m_centerX(centerX), m_centerY(centerY), m_radius(radius){
	this->calculateSquare();
};

Circle::Circle(const Circle& other): Shape(other.m_color),
m_centerX(other.m_centerX), m_centerY(other.m_centerY), m_radius(other.m_radius) {
	this->calculateSquare();
};

Circle::Circle(Circle&& tmp) {

};

Circle::~Circle() {
	cout << "Now I am in Circle's destructor!" << endl;
};

void Circle::WhereAmI() const{
	cout << "Now I am in class Circle" << endl;
};

void Circle::Inflate(int a){
	this->m_radius += a;
};

void Circle::calculateSquare(){
	this->m_square=2*3.14*this->m_radius*this->m_radius;
};

Circle* Circle::factoryMethod() const{
	return new Circle(*this);
};

bool Circle::operator==(const Shape& other)
{
	if (const Circle* cir = dynamic_cast<const Circle*>(&other))
	{
		if (m_centerX == cir->m_centerX && m_centerY == cir->m_centerY && 
			m_radius == cir->m_radius && m_color == other.getColor())
			return true;
	}
	return false;
};

Circle * Circle::operator=(const Shape & other)
{
	if (const Circle* cir = dynamic_cast<const Circle*>(&other))
	{
		m_radius = cir->m_radius;
		m_color = cir->getColor();
	}
	else
		throw "Error";
	return this;
};

Circle * Circle::operator=(Shape && other)
{
	if (const Circle* cir = dynamic_cast<const Circle*>(&other))
	{
		m_radius = cir->m_radius;
		m_color = cir->getColor();
	}
	return this;
};

std::ostream & operator<<(std::ostream & os, const Circle & string)
{
	//os << "Cicle: " <<"Center-" << string.m_x << " " << string.m_y << " Diametr-" << string.m_diametr <<std::endl;
	os << "" << string.m_centerX << " " << string.m_centerY << " " << string.m_radius <<
		" " << string.m_color << std::endl;
	return os;
};


std::ofstream& operator<<(std::ofstream& ofs, const Circle& cir)
{
	ofs << "" << cir.m_color << std::endl 
		<< cir.m_centerX << " " << cir.m_centerY << " " << cir.m_radius << std::endl;
	return ofs;
};
