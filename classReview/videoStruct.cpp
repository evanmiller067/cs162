//This program demos structs
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//Video struct
struct VideoType
{
	char title[101];
	int qty;
	char genre[101];
};

void loadData(ifstream &inFile, VideoType list[], int &size);
void printData(VideoType list[], int size);

int main()
{
	VideoType list[10];
	int size = 0;
	ifstream inFile;
	inFile.open("video.txt");
	if(!inFile)
	{
		cout << "Error!" << endl;
		exit(0);
	}
	loadData(inFile, list, size);
	printData(list, size);

	inFile.close();
	return 0;
}

//load data function
void loadData(ifstream &inFile, VideoType list[], int &size)
{
	inFile.get(list[size].title, 101, ';');
    while(!inFile.eof())
    {
        inFile.ignore(5, ';');
        inFile >> list[size].qty;
        inFile.ignore(5, ';');
        inFile.get(list[size].genre, 101, '\n');
        inFile.ignore(5, '\n');
        size++;
        inFile.get(list[size].title, 101, ';');
    }
}
	
//function to print the data
void printData(VideoType list[], int size)
{
	//output the data to the screen
    for(int i = 0; i < size; i++)
    {
        cout << list[i].title << ';' << list[i].qty << ';' << list[i].genre << endl;
    }
}
