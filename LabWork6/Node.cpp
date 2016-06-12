#include <typeinfo>
#include "Node.h"
#include "myRect.h"
#include "myCircle.h"

Node::Node(){
	this->pNext = nullptr;
	this->pPrev = nullptr;
};

Node::Node(Node* p, const Shape& shape){//:m_data(circle){
	this->pPrev = p;
	this->pNext = p->pNext;
	p->pNext = this;
	this->pNext->pPrev = this;

	if (typeid(shape) == typeid(Rect)){
		this->m_data = new Rect();
	}
	if (typeid(shape) == typeid(Circle)){
		this->m_data = new Circle();
	}
	
};

Node::~Node(){
//Коррекция следующего
	if (pNext != 0)pNext->pPrev = pPrev;//проверяем, что это не Tail
//Коррекция предыдущего
	if (pPrev != 0)pPrev->pNext = pNext;//проверяем, что это не Head
};