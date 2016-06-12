#pragma once
# include "myShape.h"

class Node{
	Shape* m_data;//������, ������� ����� ����������� � ������ Node ������
	Node* pPrev;//���������, ������� �������� ����� ����������� �������� ������ (�.�. Node)
	Node* pNext;//���������, ������� �������� ����� ���������� �������� ������ (�.�. Node)

public:
	Node();
	Node(Node* p, const Shape& shape);
	~Node();

	friend class List;
	//friend std::ostream & operator<<(std::ostream & os, const List & ls);
	//friend std::ofstream& operator<<(std::ofstream& ofs, const List& ls);

};