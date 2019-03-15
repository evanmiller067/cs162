#include "list.h"
#include <iostream>
using namespace std;

bool insert(int position, int val, int intList[], int& size)
{
	intList[size] = val;

	for (int i = 0; i < size; i++)
	{
		if (val == intList[position])
		{
			return false;
		}
		else if (val < intList[position])
		{
			intList[i + 1] = intList[i];
			intList[i] = val;
		}
	}
	size++;

	return true;
}

bool remove(int position, int& val, int intList[], int& size)
{
	for (int i = 0; i < size + 1; i++)
	{
		if (val == intList[position])
		{
			intList[i] = intList[i + 1];
			size--;
			return true;
		}
	}
	return true;
}

void print(const int intList[], int size)
{
	cout << endl << "[ ";
	for(int i=0; i<size; i++)
	{
		cout << intList[i] << " ";
	}
	cout << "]" << endl;
}

