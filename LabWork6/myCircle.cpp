#include "myCircle.h"
#include "myShape.h"
#include <iostream>
using namespace std;

Circle::Circle() {
	this->m_centerX = 0;
	this->m_centerY = 0;
	this->m_radius = 0;
};
Circle::Circle(int centerX, int centerY, double radius, COLOR color1):Shape(color1){
	this->m_centerX = centerX;
	this->m_centerY = centerY;
	this->m_radius = radius;
};

Circle::Circle(const Rect& other):Shape(other) {
	int left=other.getLeft(), 
		right=other.getRight(), 
		top=other.getTop(), 
		bottom=other.getBottom();
	
	this->m_centerX = left+(right-left)/2;
	this->m_centerY = top+(bottom-top)/2;
	if ((right - left) > (bottom - top)){
		this->m_radius = (bottom - top) / 2;
	}
	else{
		this->m_radius = (right - left) / 2;
	}
};

void Circle::WhereAmI() const{
	cout << "Now I am in class Circle" << endl;
};

Circle::~Circle() {
	cout << "Now I am in Circle's destructor!" << endl;
};

void Circle::Inflate(int a){
	this->m_radius += a;
};

void Circle::calculateSquare(){
	this->m_square=2*3.14*this->m_radius*this->m_radius;
};