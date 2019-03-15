#include "point.h"
#include <iostream>
#include <iomanip>

using namespace std;

Point::Point()
{
	xValue = 0;
	yValue = 0;
}

Point::Point(int x, int y)
{
	xValue = x;
	yValue = y;
}

int Point::getX() const
{
	return xValue;
}

int Point::getY()const
{
	return yValue;
}

void Point::setX(int x)
{
	xValue = x;
}

void Point::setY(int y)
{
	yValue = y;
}


void Point::print()
{
	cout << "x = " << xValue << endl;
	cout << "y = " << yValue << endl;
}

ostream& operator<< (ostream& out, const Point& aPoint)
{
	out << setw(20) << aPoint.xValue << setw(15) << aPoint.yValue;
	return out;
}

Point Point::operator+ (Point& aPoint)
{
	Point temp;
	temp.xValue = this->xValue + aPoint.xValue;
	temp.yValue = this->yValue + aPoint.yValue;
	return temp;
}

//assignment operator overloaded
const Point Point::operator= (const Point& aPoint)
{
	//if it is a self copy, don't do anything
	if(this == &aPoint)
		return *this;
	//make current object *this a copy of the passed in student
	else
	{
		this->setX(aPoint.xValue);
		setY(aPoint.yValue);
		return *this;
	}
}

bool operator< (const Point& p1, const Point& p2)
{
	int x1, x2, y1, y2;
	x1 = p1.getX();
	x2 = p2.getX();

	y1 = p1.getY();
	y2 = p2.getY();

	if(x1 < x2 && y1 < y2)
		return true;
	else
		return false;
}

bool operator== (const Point& p1, const Point& p2)
{
	int x1, x2, y1, y2;
	x1 = p1.getX();
	x2 = p2.getX();

	y1 = p1.getY();
	y2 = p2.getY();

	if(x1 == x2 && y1 == y2)
		return true;
	else
		return false;
}
