#ifndef _SHAPE_H_
#define _SHAPE_H_
#include<iostream>
class shape
{
private:
	float area_;
public:
	shape(){}
	~shape(){}
	virtual float Getarea() { return -1; };

};
class Circle :public shape {
private:
	float r;
public:
	Circle(float rr) :r(rr) {}
	~Circle() {}
	virtual float Getarea();
};
class Rectangle :public shape {
private:
	float a, b;
public:
	Rectangle(float aa, float bb) :a(aa), b(bb) {}
	~Rectangle() {}
	virtual float Getarea();

};
class Square :public Rectangle {
public:
	Square(float l) :a(l), Rectangle(l, l) {}
	~Square() {}
private:
	float a;
};

#endif