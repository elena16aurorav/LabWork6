#include <typeinfo>
#include "List.h"
#include "myCircle.h"
#include <fstream>

int main()
{
	Circle c1 = Circle(10, 10, 10, RED);
	Circle c2 = Circle(20, 20, 20, BLUE);
	Circle c3 = Circle(30, 30, 30, WHITE);
	Circle c4 = Circle(5, 10, 10, GREEN);
	Circle c5 = Circle(6, 10, 10, BLUE);
	Circle c6 = Circle(c1);
	//Circle c7 = c2;

	Rect r1 = Rect(10, 10, 10, 10, RED);
	Rect r2 = Rect(5, 15, 5, 15, RED);
	Rect r3 = Rect(10, 100, 10, 100, BLUE);
	Rect r4 = Rect(50, 50, 50, 50, GREEN);
	Rect r5 = Rect(10, 35, 10, 35, WHITE);
	Rect r6 = Rect(r1);
	//Rect r7 = r2;



	///List list = List();
	///list.size();//=0, т.к. список пустой
	/*Circle circle = Circle(15, 10, 10);
	Circle circle2 = Circle(155, 105, 105);
	list.AddToHead(circle);
	list.size();//=1
	list.AddToTail(circle);
	list.size();//=2

	list.Empty();
	list.size();

	list.AddToHead(circle);
	list.size();//=1
	list.AddToTail(circle2);
	list.size();//=2
	list.AddToTail(circle);
	list.size();//=3
	//list.RemoveOne(circle);
	//list.Remove(circle);
	list.size();

	list.sort();
	list.size();

	//только распечатка списка
	std::cout << list;

	list.Empty();
	Circle c1 = Circle(10, 10, 10);
	Circle c2 = Circle(20, 20, 20);
	Circle c3 = Circle(30, 30, 30);
	Circle c4 = Circle(5, 10, 10);
	Circle c5 = Circle(6, 10, 10);
	list.AddToHead(c1);
	list.AddToHead(c2);
	list.AddToHead(c3);
	list.AddToHead(c4);
	list.AddToHead(c5);
	
	//запись содержимого списка в файл
	std::ofstream file("List.txt");
	file << list << std::endl;
	file.close();

	list.Empty();
	//чтение из файла 
	std::ifstream fcin;
	fcin.open("List.txt");
	fcin >> list;
	fcin.close();
	std::cout << list;
	*/

	return 0;
}