//This program demos char arrays and inserting alphabetically
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

//constants
const int MAX = 101;
const int CAP = 15;

//function prototypes
void readData(ifstream &inFile, char fruits[][MAX], int &size);
bool isLessThan(char fruit1[], char fruit2[]);
void printData(char fruits[][MAX], int size);

//main function
int main()
{
	ifstream inFile;
	char fruits[CAP][MAX];
	int size = 0;
	inFile.open("fruits.txt");
	if(!inFile)
	{
		cout << "File not found! Program exiting!!";
		exit(0);
	}

	readData(inFile, fruits, size);
	printData(fruits, size);
	return 0;
}

//readData
void readData(ifstream &inFile, char fruits[][MAX], int &size)
{
	char tempFruit[MAX];
	int i = 0;
	while(!inFile.eof())
	{
		inFile.get(tempFruit, MAX);
		inFile.ignore(5, '\n');
		if(size == CAP)
		{
			cout << "Array full!" << endl;
			return;
		}
		if(!size)
		{
			strcpy(fruits[size], tempFruit);
		}
		else
		{
			for(i = 0; i < size; i++)
			{
				if(!(isLessThan(fruits[i], tempFruit)))
				{
					break;
				}
			}
			for(int j = size; j > i; j--)
			{
				strcpy(fruits[j], fruits[j-1]);
			}
			//insert
			strcpy(fruits[i], tempFruit);
		}
		size++;
	}
}

//compares 2 fruits and returns true or false
bool isLessThan(char fruit1[MAX], char fruit2[MAX])
{
	if(strcmp(fruit1, fruit2) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
			
//prints the data
void printData(char fruits[][MAX], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << fruits[i] << endl;
	}
}











