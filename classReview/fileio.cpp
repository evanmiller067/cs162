#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream inFile;
	char name[101];
	double pay, tax, total;
	inFile.open("sample.txt");
	inFile >> name >> pay >> tax;
	while(!inFile.eof())
	{
		total = pay + pay * tax;
		cout << name << "   " << total << endl;
		inFile >> name >> pay >> tax;
	}
	inFile.close();
	return 0;
}
	
