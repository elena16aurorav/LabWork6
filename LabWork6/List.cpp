#pragma once
#include "List.h"
#include "Node.h"
#include <string>
#include <iostream>
#include <fstream>
/*
List::List(){//используем дл€ создани€ пустого списка
	this->Head.pNext = &Tail;
	this->Tail.pPrev = &Head;
	this->m_size = 0;//!!!
	//ѕри этом, при создании Node конструктором, т.е.
	//Node::Node(){
	//this->pNext = nullptr;
	//this->pPrev = nullptr;
	//};
};

List::List(const List & other)
{
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
	m_size = 0;
	if (other.m_size != 0) {
		Node* tmp = other.Head.pNext;
		for (int i = 0; i < other.m_size; i++)
		{
			this->AddToTail(tmp->m_data);
			tmp = tmp->pNext;
		}
	}
}

List::List(List && other)
{
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
	m_size = 0;
	if (other.m_size != 0)
	{
		Head.pNext = other.Head.pNext;
		Head.pNext->pPrev = &Head;
		other.Head.pNext = &Tail;
		Tail.pPrev = other.Tail.pPrev;
		Tail.pPrev->pNext = &Tail;
		other.Tail.pPrev = &Head;
		m_size = other.m_size;
		other.m_size = 0;
	}
}



List::~List(){
	while (Head.pNext != &Tail){
		delete Head.pNext;
	};
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
	this->m_size = 0;
};

int List::size(){
	Node* pNode=Head.pNext;
	int n = 0;
	while (pNode != &Tail){
		n++;
		pNode = pNode->pNext;
	};
	return n;
};
void List::AddToHead(const Shape& shape){//добавл€ем элемент
	//в список сразу после Head, т.е. до первого элемента.
	new Node(&Head, shape);
	this->m_size++;
};
void List::AddToTail(const Shape& shape) {//добавл€ем элемент
	//в список сразу до Tail, т.е. после последнего элемента до Tail.
	new Node(Tail.pPrev, shape);
	this->m_size++;
};

bool List::RemoveOne(const Shape& shape){
	Node* pNode = Head.pNext;
	while (pNode != &Tail){
/*		if (pNode->m_data == shape){
			delete pNode;
			this->m_size--;
			return true;
		}
*/
		pNode = pNode->pNext;//переход на следующий элемент в списке
	}
	return false;
};

int List::Remove(const Shape& shape) {
	int n = 0;
	Node* pNode = Head.pNext;
	Node* pNodeNext = nullptr;
	while (pNode != &Tail) {
		pNodeNext = pNode->pNext;
/*		if (pNode->m_data == shape) {
			
			delete pNode;
			this->m_size--;
			n++;
		}
*/
		pNode = pNodeNext;
	}
//	delete pNodeNext;
	return n;
};

void List::Empty() {
	while (Head.pNext != &Tail) {
		delete Head.pNext;
	};
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
	this->m_size = 0;
};

void List::sort() {//пузырькова€ сортировка
	Node* p = Head.pNext;
	int j = m_size;
	while (p != &Tail)
	{
		Node* np = p;
		for (int i = 0; i <j - 1; i++)
		{
			if (np->m_data.calculateSquare() > np->pNext->m_data.calculateSquare())
			{
				Node* p1 = np->pNext;
				Node* p2 = np->pPrev;
				
				p2->pNext = p1;
				np->pNext->pNext->pPrev = np->pNext;
				
				np->pNext = np->pNext->pNext;
				
				p1->pPrev = p2;
				p1->pNext = np;
				
				np->pPrev = p1;
					
			}
			np = np->pNext;
		}
		p = p->pNext;
		j--;
	}

};

std::ostream& operator<<(std::ostream & os, const List& ls)
//классы ostream и ofstream св€заны наследованием (с.156)
{
	Node* p;
	p=ls.Head.pNext;
	while (p != &ls.Tail)
	{
		os << p->m_data;
		p = p->pNext;
	}
	return os;
};

std::ofstream& operator<<(std::ofstream& ofs, const List& ls)
{
	ofs << "" << ls.m_size << std::endl;
	Node* p = ls.Head.pNext;
	while (p != &ls.Tail)
	{
		ofs << p->m_data << std::endl;
		p = p->pNext;
	}
	return ofs;
};

std::ifstream& operator >> (std::ifstream& ifs, List& ls)
{
	int count=0;
	ifs >> count;
	
	int x;
	int y;
	int radius;
	for (int i = 0; i < count; i++)
	{
		ifs >> radius >> y >> x;
		Circle circle(radius, x, y);
		ls.AddToTail(circle);
	}
	return ifs;
};


List & List::operator=(const List & other)
{
	if (this != &other)
	{
		Node* pThis;
		Node* pOther;
		if (other.m_size == 0) //≈сли размер Other = 0
		{
			this->Empty();
			return *this;
		}
		
		int count = (this->m_size < other.m_size) ? this->m_size : other.m_size;
		pThis = Head.pNext;
		pOther = other.Head.pNext;
		for (int i = 0; i < count; i++)
		{
			pThis->m_data = pOther->m_data;
			pThis = pThis->pNext;
			pOther = pOther->pNext;
		}
		Node* pThisEnd = Tail.pPrev;
		for (int i = count; i< this->m_size; i++)
		{
			delete pThisEnd;
			pThisEnd = Tail.pPrev;
		}
		for (int i = count; i < other.m_size; i++)
		{
			this->AddToTail(pOther->m_data);
			pOther = pOther->pNext;
		}
		m_size = other.m_size;
	}
	return *this;
}

List & List::operator=(List && other)
{
	if (this != &other) {
		this->Empty();
		if (other.m_size != 0) {
			Head.pNext = other.Head.pNext;
			Head.pNext->pPrev = &Head;
			other.Head.pNext = &Tail;
			Tail.pPrev = other.Tail.pPrev;
			Tail.pPrev->pNext = &Tail;
			other.Tail.pPrev = &Head;
			m_size = other.m_size;
			other.m_size = 0;
		}
	}
	return *this;
}
*/
