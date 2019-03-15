//This program demos data validation
#include <iostream>
using namespace std;

int main()
{
	int num1 = 0, num2 = 0;
	cout << "Enter 2 whole numbers:";
	cin >> num1;
	while(!cin)
	{
		cout << "Illegal input! Please try again!" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> num1;
	}
	cin  >> num2;
	cout << "Num1 = " << num1 << " and Num2 = " << num2 << endl;

	return 0;
}
