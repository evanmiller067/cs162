//This program demos reading from a file
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;
const int MAXCHAR = 101;

//function prototypes
void openFile(ifstream &inFile);
void echoData(ifstream &inFile);
void countVideo(ifstream &inFile);

int main()
{
	ifstream inFile;
	openFile(inFile);
	echoData(inFile);
	countVideo(inFile);
	return 0;
}

//openFile function
void openFile(ifstream &inFile)
{
	inFile.open("video.txt");
	if(!inFile)
	{
		cout << "File not found!! Program exiting!!" << endl;
		exit(0);
	}
}	

//reads from the file and echoes the data to the screen
void echoData(ifstream &inFile)
{
	char title[MAXCHAR], tempGenre[MAXCHAR];
	int qty = 0;
	inFile.get(title, MAXCHAR, ';');
	while(!inFile.eof())
	{
		inFile.ignore(5, ';');
		inFile >> qty;
		inFile.ignore(5, ';');
		inFile.get(tempGenre, MAXCHAR, '\n');
		inFile.ignore(5, '\n');
		cout << title << ';' << qty << ';' << tempGenre << endl;
		inFile.get(title, MAXCHAR, ';');
	}
	//needed to rewind the file
	inFile.clear();
	inFile.seekg(0);
}

//counts the number of videos based on genre	
void countVideo(ifstream &inFile)
{
	int countA = 0, countF = 0, countC = 0;
	char title[MAXCHAR], tempGenre[MAXCHAR];
    int qty = 0;
    inFile.get(title, MAXCHAR, ';');
    while(!inFile.eof())
    {
        inFile.ignore(5, ';');
        inFile >> qty;
        inFile.ignore(5, ';');
        inFile.get(tempGenre, MAXCHAR, '\n');
        if(strcmp(tempGenre, "ACTION") == 0)
        {
            countA++;
        }
		else if(strcmp(tempGenre, "FAMILY") == 0)
		{
			countF++;
		}
		else if(strcmp(tempGenre, "COMEDY") == 0)
        {
            countC++;
        }
		inFile.get(title, MAXCHAR, ';');
	}
	cout << "Action movies count = " << countA << endl;
	cout << "Family movies count = " << countF << endl;
	cout << "Comedy movies count = " << countC << endl;
}



				





