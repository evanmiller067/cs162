/*
	Evan Miller
	CS 162
	Project 1

	Assignment Info:

	Read data from the given text file, cars.txt

	You must have a function to open the text file.  You don't need to store the data anywhere for this project.

	Once the file is open, you must have another function to give me the total cars in each category. 
	Notice the last column is the category and there are 3 of them - US, Europe, and Japan.  
	Your function must output the number of cars for each category.
	
	Write another function to count the cars based on their weight.  Tell me how many cars there are between these weights:
	Between 1000 and 2000
	Between 2000 and 3000
	Between 3000 and 4000
	>4000
*/


#include <iostream>
#include <fstream>
using namespace std;
char openfile(); // Opens File
float carCatTotals(char); // Outputs total number of cars sorted by car origin into three categories( US, Japan, Europe)
float carCatWeight(char); // Outputs car count sorted by weight into four categories(1000 - 2000, 2000 - 3000, 3000 - 4000, 4000+)

// File path name: "C://Users/evanm/Desktop/cars.txt"

int main()
{	
	char chStream[1000];
	openfile() >> chStream;
	carCatTotals(chStream);
	carCatWeight(chStream);
	return 0;
}

char openfile() 
{
	ifstream myfile;
	myfile.open("cars.txt");
	char ch;
	while (!myfile.eof())
	{
		myfile.get(ch);
		return ch;
	}
}
float carCatTotals(char ch)
{	
	int usCarCount = 0;
	int jpCarCount = 0;
	int epCarCount = 0;
	int count = 0;
	while (ch < count)
	{
		if (ch == 'U')
		{
			usCarCount++;
		}
		else if (ch == 'J')
		{
			jpCarCount++;
		}
		else if (ch == 'E')
		{
			epCarCount++;
		}
		else
		{
			count++;
		}
	}
	cout << "The number of US made cars: " << usCarCount << endl;
	cout << "The number of Japan made cars: " << jpCarCount << endl;
	cout << "The number of Europe made cars: " << epCarCount << endl;
	return 0;
}

float carCatWeight(char ch)
{
	int oneThou = 0;
	int twoThou = 0;
	int threeThou = 0;
	int fourthouPlus = 0;
	int count = 0;
	while (ch < count)
	{
		if (ch < 2000)
		{
			oneThou++;
		}
		else if (ch >= 2000 && ch < 3000)
		{
			twoThou++;
		}
		else if (ch >= 3000 && ch < 4000)
		{
			threeThou++;
		}
		else if (ch > 4000)
		{
			fourthouPlus++;
		}
		else
		{
			count++;
		}
	}
	cout << "The number of 1000 - 1999 pound cars: " << oneThou << endl;
	cout << "The number of 2000 - 2999 pound cars: " << twoThou<< endl;
	cout << "The number of 3000 - 3999 pound cars: " << threeThou << endl;
	cout << "The number of cars over 4000 pounds: " << fourthouPlus << endl;
	return 0;
}

