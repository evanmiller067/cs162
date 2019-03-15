#include <iostream>
#include "point.h"
using namespace std;

Point operator+ (const Point& point1, const Point& point2);

int main()
{
    Point p1 (3,12);
	cout << "P1:  " << p1;
	//p1.print();
	cout << endl;
	Point p2 (3,4);
	cout << "P2:  " << p2;
	//p2.print();
	cout << endl;
	Point p3 = p1 + p2;
	cout << "P3: " << p3;
	//p3.print();
	cout << endl;
	Point p4 = p3;
	cout << "P4: " << p4 << endl;
	//int size = aList.getSize();
	if(p3 == p4) cout << "Equal" << endl;
	else
		cout << "Not equal" << endl;


}	

Point operator+(const Point& point1, const Point& point2)
{
    return Point(point1.getX()+point2.getX(), point1.getY()+point2.getY());
}

