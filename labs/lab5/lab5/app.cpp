#include <iostream>
using namespace std;

int main()
{
	char ** names;

	//write code here to allocate memory for at most 10 names 
	
	names = new char*[10];

	//write code here to allocate memory and populate the first name as "charlie"

	names[0]= new char[8];

	//it has to be just big enough for "charlie" which is 8 chars including '\0'

	names[0][0] = 'c';
	names[0][1] = 'h';
	names[0][2] = 'a';
	names[0][3] = 'r';
	names[0][4] = 'l';
	names[0][5] = 'i';
	names[0][6] = 'e';
	names[0][7] = '\0';

	//write code here to allocate memory and populate the second name as "sarah"

	names[1] = new char[6];


	//it has to be just big enough for "sarah"

        names[1][0] = 's';
        names[1][1] = 'a';
        names[1][2] = 'r';
        names[1][3] = 'a';
        names[1][4] = 'h';
        names[1][5] = '\0';

	
	//write code here to print the names

	cout << names[0] << endl;
	cout << names[1] << endl;

	//write code here to deallocate memory for the names

	delete[] names[0];
	delete[] names[1];

	return 0;
}

