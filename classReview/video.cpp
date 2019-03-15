//This program demos reading from a file
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
enum GENRE {ACTION, FAMILY, COMEDY, HORROR, ILLEGAL};

const int MAXCHAR = 101;

//function prototypes
void openFile(ifstream &inFile);
void echoData(ifstream &inFile);
void writeGenre(GENRE genre, char genreDesc[]);

int main()
{
	ifstream inFile;
	openFile(inFile);
	echoData(inFile);
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
	GENRE genre;
	int qty = 0;
	inFile.get(title, MAXCHAR, ';');
	while(!inFile.eof())
	{
		inFile.ignore(5, ';');
		inFile >> qty;
		inFile.ignore(5, ';');
		//inFile >> genre;
		inFile.get(tempGenre, MAXCHAR, ';');
        if(strcmp(tempGenre, "ACTION") == 0)
        {
            genre = ACTION;
        }
        else if(strcmp(tempGenre, "FAMILY") == 0)
        {
            genre = FAMILY;
        }
        else if(strcmp(tempGenre, "COMEDY") == 0)
        {
            genre = COMEDY;
        }
        else if(strcmp(tempGenre, "HORROR") == 0)
        {
            genre = HORROR;
        }
        else
        {
            genre = ILLEGAL;
        }

		inFile.ignore(5, '\n');
		writeGenre(genre, tempGenre);
		cout << title << ';' << qty << ';' << tempGenre << endl;
		inFile.get(title, MAXCHAR, ';');
	}
}

//function to convert genre to a cstring
void writeGenre(GENRE genre, char genreDesc[])
{
	switch(genre)
	{
		case 0:
			strcpy(genreDesc, "ACTION");
			break;
		case 1:
			strcpy(genreDesc, "FAMILY");
			break;
		case 2:
			strcpy(genreDesc, "COMEDY");
			break;
		case 3:
			strcpy(genreDesc, "HORROR");
			break;
		default:
			strcpy(genreDesc, "ILLEGAL");
	}
}
				





