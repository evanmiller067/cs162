//This program demos how to create a menu driven program
#include <iostream>

using namespace std;

void displayMenu();
char readOption();
void exeCommand(char option);

int main()
{
	char option;
	do
	{
		displayMenu();
		option = readOption();
		exeCommand(option);
	}while(option != 'q');
	return 0;
}

//display menu
void displayMenu()
{
	cout << "a: Add" << endl;
	cout << "b: List" << endl;
	cout << "q: Quit" << endl;
}

char readOption()
{
	char option;
	cin >> option;
	cin.ignore(5, '\n');
	return option;
}

void exeCommand(char option)
{
	switch(option)
	{
		case 'a':
			cout << "You are adding something!" << endl;
			break;
		case 'b':
			cout << "You are listing something!" << endl;
			break;
		case 'q':
			break;
		default:
			cout << "Illegal input!" << endl;
	}
}



