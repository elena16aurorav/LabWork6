#include "myRect.h"
#include "myShape.h"
#include <iostream>
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

Rect::Rect(const Rect& other):Shape(other){
	this->m_left = other.m_left;
	this->m_right = other.m_right;
	this->m_top = other.m_top;
	this->m_bottom = other.m_bottom;
}

Rect::Rect(int left, int right, int top, int bottom, COLOR color):Shape(color) {
	//Rect(left, right, top, bottom);
	this->m_left = left;
	this->m_right = right;
	this->m_top = top;
	this->m_bottom = bottom;
	normalize();
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

int Rect::getLeft() const{
	return this->m_left;
};
int Rect::getRight() const{
	return this->m_right;
};
int Rect::getTop() const{
	return this->m_top;
};
int Rect::getBottom() const{
	return this->m_bottom;
};

void Rect::calculateSquare(){
	int light = this->m_right - this->m_left;
	int hight = this->m_bottom - this->m_top;
	this->m_square = light*hight;
};