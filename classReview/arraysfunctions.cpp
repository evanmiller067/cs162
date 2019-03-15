#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int CAP = 100;
const int MAXCHAR = 101;

//function prototypes
void openFile(char [], ifstream &);
void initList(int [], int);
void readList(ifstream &, int [], int&);
void printList(const int [], const int);
int largest(const int [], const int);
void removeEven(int [], int &);

int main()
{
    int list[CAP] = {0}, size = 0;
    char fileName[MAXCHAR];
    ifstream inFile;
    cout << "Please enter filename:";
    cin.get(fileName, MAXCHAR);
    strcpy(fileName, "numbers.txt");
    cin.ignore(100, '\n');
    openFile(fileName, inFile);
    //inits the list
    initList(list, CAP);
    readList(inFile, list, size);
    printList(list, size);
    //cout << "Largest in your list is " << largest(list, size) << endl;
	removeEven(list, size);
	printList(list, size);
    inFile.close();
    return 0;
}

//open the file
void openFile(char fileName[], ifstream &inFile)
{
    inFile.open(fileName);
    if(!inFile)
    {
        cout << "File did not open!! Program exiting!!!" << endl;
        exit(0);
    }
}
    
    
//init the array
void initList(int list[], int cap)
{
    for(int i = 0; i < cap; i++)
    {
        list[i] = -1;
    }
}

//reads numbers from the user    
void readList(ifstream &inFile, int list[], int &size)
{
    int temp = 0, i = 0;
    while(inFile >> temp)
    {
        if(size == CAP)
        {
            cout << "Error!! List full!!" << endl;
            return;
        }
		else if(size == 0)
		{
        	list[size++] = temp;
		}
		else
		{
			for(i = 0; i < size; i++)
			{
				if(list[i] > temp)
					break;
			}
			for(int j = size; j > i; j--)
			{
				list[j] = list[j-1];
			}
			list[i] = temp;
			size++;
		}
    }
}

//prints the array
void printList(const int list[], const int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

//finds the largest number in the list 
int largest(const int list[], const int size)
{
    ///insert code here
}

//removes all even numbers in the list
void removeEven(int list[], int &size)
{
	if(!size)
	{
		return;
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			if(i == size)
			{
				return;
			}
			else if(!(list[i]%2))
			{
				for(int j = i; j < size-1; j++)
				{
					list[j] = list[j+1];
				}
				size--;
				i--;
			}
		}
	}
}






