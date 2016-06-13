#include <typeinfo>
#include "Node.h"
#include "myRect.h"
#include "myCircle.h"
#include "myShape.h"

Node::Node(){
	this->pNext = nullptr;
	this->pPrev = nullptr;
};

Node::Node(Node* p, const Shape& shape):m_data(shape.factoryMethod()){
	this->pPrev = p;
	this->pNext = p->pNext;
	p->pNext = this;
	this->pNext->pPrev = this;
};

Node::~Node(){
//Коррекция следующего
	if (pNext != 0)pNext->pPrev = pPrev;//проверяем, что это не Tail
//Коррекция предыдущего
	if (pPrev != 0)pPrev->pNext = pNext;//проверяем, что это не Head
};