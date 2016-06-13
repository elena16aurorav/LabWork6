#include "myRect.h"
#include "myShape.h"
#include <iostream>
#include <fstream>

using namespace std;

Rect::Rect(){
	this->m_left = 0;
	this->m_right = 0;
	this->m_top = 0;
	this->m_bottom = 0; 
};

Rect::Rect(int left, int right, int top, int bottom){
	this->m_left = left;
	this->m_right = right;
	this->m_top = top;
	this->m_bottom = bottom;
	normalize();
};

Rect::Rect(const Rect& other):Shape(other.m_color), 
m_left(other.m_left), m_right(other.m_right),
m_top(other.m_top), m_bottom(other.m_bottom){
	//normalize();
	this->calculateSquare();
};

Rect::Rect(Rect&& tmp) {
	
};

Rect::Rect(int left, int right, int top, int bottom, COLOR color):Shape(color),
m_left(left), m_right(right), m_top(top), m_bottom(bottom){
//	normalize();
	this->calculateSquare();
};

Rect::~Rect(){
	cout << "Now I am in Rect's destructor!" << endl;
};


void Rect::normalize(){
	int a;
	if (this->m_right < this->m_left){
		a = this->m_right;
		this->m_right = this->m_left;
		this->m_left = a;
	}
	if (this->m_top < this->m_bottom){
		a = this->m_top;
		this->m_top = this->m_bottom;
		this->m_bottom = a;
	}
};

void Rect::InflateRect(int l, int r, int t, int b){
	this->m_left -= l;
	this->m_right += r;
	this->m_top -= t;
	this->m_bottom += b;
	normalize();
};

void Rect::InflateRect(int x, int y){
//значения по умолчанию задаются только в заголовке (.h файл)
	this->m_left -= x;
	this->m_right += x;
	this->m_top -= y;
	this->m_bottom += y;
};

void Rect::SetAll(int left, int right, int top, int bottom){
	this->m_left = left;
	this->m_right = right;
	this->m_top = top;
	this->m_bottom = bottom;
};

void Rect::GetAll(int*, int*, int*, int*) const{
};

void Rect::WhereAmI() const{
	cout << "Now I am in class Rect" << endl;
};

void Rect::Inflate(int a) {
	this->m_left-= a;
	this->m_right += a;
	this->m_top -= a;
	this->m_bottom += a;
};

void Rect::calculateSquare(){
	int light = this->m_right - this->m_left;
	int hight = this->m_bottom - this->m_top;
	this->m_square = light*hight;
};

Rect* Rect::factoryMethod() const{
	return new Rect(*this);
};

bool Rect::operator==(const Shape& other)
{
	if (const Rect* rec = dynamic_cast<const Rect*>(&other))
	{
		if (m_bottom == rec->m_bottom && m_left == rec->m_left && 
			m_right == rec->m_right && m_top == rec->m_top &&
			m_color==other.getColor())
			return true;
	}
	return false;
};

Rect* Rect::operator=(const Shape& other)
{
	if (const Rect* rect = dynamic_cast<const Rect*>(&other))
	{
		m_color = rect->getColor();
		m_bottom = rect->m_bottom;
		m_top = rect->m_top;
		m_left = rect->m_left;
		m_right = rect->m_right;
	}
	return this;
};

Rect* Rect::operator=(Shape&& other)
{
	if (const Rect* rect = dynamic_cast<const Rect*>(&other))
	{
		m_color = rect->getColor();
		m_bottom = rect->m_bottom;
		m_top = rect->m_top;
		m_left = rect->m_left;
		m_right = rect->m_right;
	}
	return this;
};

std::ostream& operator<<(std::ostream& os, const Rect& string)
{
	//os << "Rectangle: " <<"Bottom-" << string.m_bottom << " Top-" << string.m_top << " Left-" << string.m_left << " Right-" << string.m_right << std::endl;
	os << string.m_bottom << " " << string.m_top << " " << string.m_left << " " << string.m_right <<
		" " << string.m_color << std::endl;
	return os;
};

std::ofstream & operator<<(std::ofstream & ofs, const Rect& rec)
{
	ofs << "" << rec.m_color << std::endl 
		<< rec.m_bottom << " " << rec.m_top << " " << rec.m_left << " " << rec.m_right << std::endl;
	return ofs;
};

