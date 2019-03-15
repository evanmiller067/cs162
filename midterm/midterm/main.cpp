#include "array.h"
using namespace std;

const int CAP = 100;
int main()
{
	int list[CAP];
	int size = 10;
	build(list, size);
	display(list, size);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
	int newInt;
	int position;
	int even;	
	even = numOfEven(list, size);
	cout << "Amount of even numbers in array: " << even << endl;	
	cout << "Number to insert into array: ";
	cin >> newInt;
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Choose index location(0 - " << (size) << "): " << endl;
	cin >> position;
	cin.clear();
	cin.ignore(100, '\n');

	insert(list, size, newInt, position);

	cout << "Modified list: " << endl;
	display(list, size); 

	return 0;
}
