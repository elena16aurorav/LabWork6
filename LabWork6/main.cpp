#include <typeinfo>
#include "List.h"
#include "myCircle.h"
#include <fstream>
#include <iostream>

int main()
{
	Circle c1 = Circle(10, 10, 10, RED);
	Circle c2 = Circle(20, 20, 20, BLUE);
	Circle c3 = Circle(30, 30, 30, WHITE);
	
	Rect r1 = Rect(10, 20, 20, 40, RED);
	Rect r2 = Rect(15, 20, 25, 40, RED);
	Rect r3 = Rect(20, 35, 30, 40, BLUE);
		
	List list = List();
	list.size();//=0, �.�. ������ ������
	
	list.AddToHead(c1);
	list.AddToHead(r1);
	list.AddToHead(c2);
	list.AddToHead(r2);
	list.AddToHead(c3);
	list.AddToHead(r3);

	list.size();

	list.sort();
	list.size();

	//������ ���������� ������
	std::cout << list;

	//������ ����������� ������ � ����
	std::ofstream file("List.txt");
	file << list << std::endl;
	file.close();

	list.Empty();
	//������ �� ����� 
	std::ifstream fcin;
	fcin.open("List.txt");
	fcin >> list;
	fcin.close();
	std::cout << list << std::endl;
	
	return 0;
}