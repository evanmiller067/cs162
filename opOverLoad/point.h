#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;

class Point
{
	friend ostream& operator<< (ostream& out, const Point &);
public:
    Point();
	Point(int x, int y);
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	Point operator+ (Point& aPoint);
	void print();
	const Point operator= (const Point& aPoint);	//overloading assignment operator
	
private:
	int xValue, yValue;
};

bool operator< (const Point& p1, const Point& p2);
bool operator== (const Point& p1, const Point& p2);


#endif

