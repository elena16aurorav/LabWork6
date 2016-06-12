#pragma once
# include "myShape.h"

class Node{
	Shape* m_data;//данные, которые будут содержаться в каждом Node списка
	Node* pPrev;//указатель, которые содержит адрес предыдущего элемента списка (т.е. Node)
	Node* pNext;//указатель, которые содержит адрес следующего элемента списка (т.е. Node)

public:
	Node();
	Node(Node* p, const Shape& shape);
	~Node();

	friend class List;
	//friend std::ostream & operator<<(std::ostream & os, const List & ls);
	//friend std::ofstream& operator<<(std::ofstream& ofs, const List& ls);

};