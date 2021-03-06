#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>

#include "List.h"
#include "Node.h"
#include "myShape.h"
#include "myRect.h"
#include "myCircle.h"

List::List(){//���������� ��� �������� ������� ������
	this->Head.pNext = &Tail;
	this->Tail.pPrev = &Head;
	this->m_size = 0;//!!!
	//��� ����, ��� �������� Node �������������, �.�.
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
			this->AddToTail(*tmp->m_data);
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
void List::AddToHead(const Shape& shape){//��������� �������
	//� ������ ����� ����� Head, �.�. �� ������� ��������.
	new Node(&Head, shape);
	this->m_size++;
};

void List::AddToTail(const Shape& shape) {//��������� �������
	//� ������ ����� �� Tail, �.�. ����� ���������� �������� �� Tail.
	new Node(Tail.pPrev, shape);
	this->m_size++;
};

bool List::RemoveOne(const Shape& shape){
	Node* pNode = Head.pNext;
	while (pNode != &Tail){
		if (*pNode->m_data == shape){
			delete pNode;
			this->m_size--;
			return true;
		}
		pNode = pNode->pNext;//������� �� ��������� ������� � ������
	}
	return false;
};

int List::Remove(const Shape& shape) {
	int n = 0;
	Node* pNode = Head.pNext;
	Node* pNodeNext = nullptr;
	while (pNode != &Tail) {
		pNodeNext = pNode->pNext;
		if (*pNode->m_data == shape) {
			
			delete pNode;
			this->m_size--;
			n++;
		}
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

void List::sort() {//����������� ����������
	Node* p = Tail.pPrev;
	int j = m_size;
	while (p != &Head)
	{
		Node* np = Head.pNext;//p;
		for (int i = 0; i <j - 1; i++)
		{
			if (np->m_data->getSquare() > np->pNext->m_data->getSquare())
			{
				Node* p1 = np;
				Node* p2 = np->pNext;

				p1->pPrev->pNext = p2;//1
				p2->pNext->pPrev = p1;//2

				p2->pPrev = p1->pPrev;//3
				p1->pNext = p2->pNext;//4

				p2->pNext = p1;
				p1->pPrev = p2;

				np = p2;
			}
			np = np->pNext;
		}
		p = p->pPrev;
		j--;
	}

};
/*
std::ostream& operator<<(std::ostream & os, const List& ls)
//������ ostream � ofstream ������� ������������� (�.156)
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
		if (other.m_size == 0) //���� ������ Other = 0
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

std::ostream& operator<<(std::ostream& os, const List& string)
{
	Node* p = string.Head.pNext;
	while (p != &string.Tail)
	{
		if (const Rect* rec = dynamic_cast<const Rect*>(p->m_data))
		{
			os << *rec;
		}
		if (const Circle* cir = dynamic_cast<const Circle* >(p->m_data))
		{
			os << *cir;
		}
		p = p->pNext;
	}
	return os;
};

std::ofstream& operator<<(std::ofstream& ofs, const List& list)
{
	ofs << "" << list.m_size << std::endl;
	Node* p = list.Head.pNext;
	while (p != &list.Tail)
	{
		if (const Rect* rec = dynamic_cast<const Rect*>(p->m_data))
		{
			ofs << *rec;
		}
		if (const Circle* cir = dynamic_cast<const Circle* >(p->m_data))
		{
			ofs << *cir;
		}
		p = p->pNext;
	}
	return ofs;
};


std::ifstream& operator>>(std::ifstream& ifs, List& string)
{
	int count;
	ifs >> count;
	int obj;
	for (int i = 0; i < count; i++)
	{
		ifs >> obj;
		if (obj == 1)
		{
			int x;
			int y;
			double radius;
			ifs >> x >> y >> radius;
			Circle cir(x, y, radius, WHITE);
			string.AddToTail(cir);
		}
		else
		{
			int bot;
			int top;
			int left;
			int right;
			ifs >> bot >> top >> left >> right;
			Rect rec(left, right, top, bot);
			string.AddToTail(rec);
		}
	}
	return ifs;
};