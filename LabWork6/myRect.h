#pragma once
#include "myShape.h"

class Rect: public Shape{
public:
	int m_left, m_right, m_top, m_bottom;
public:
	Rect();
	Rect(int left, int right, int top, int bottom);
	Rect(const Rect& other);
	Rect(Rect&& tmp);
	Rect(int left, int right, int top, int bottom, COLOR color1);

	~Rect();
	
	void normalize();

	void InflateRect(int l, int r, int t, int b);
	
	//�������� �� ��������� �������� ������ � ��������� (.h ����)
	void InflateRect(int x = 1, int y = 1);

	void SetAll(int left, int right, int top, int bottom);
	void GetAll(int*, int*, int*, int*) const;

	virtual void WhereAmI() const;
	virtual void Inflate(int a);
	virtual void calculateSquare();
	virtual Rect* factoryMethod() const;

	virtual bool operator==(const Shape& other) override;
	virtual Rect* operator= (const Shape& other) override;
	virtual Rect* operator= (Shape&& other) override;

	friend std::ostream & operator<<(std::ostream & os, const Rect & string);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Rect& rec);
};

