//This program demos arrays
#include <iostream>
using namespace std;

const int CAP = 10;

//largest function
int largest(int list[], int size);
int readData(int list[]);
void readData1(int list[], int &size);

int main()
{
    int list[CAP] = {0}, max = 0, size = 0;
    //size = readData(list);
	readData1(list, size);
	//output the whole array
    for(int i = 0; i < CAP; i++)
    {
        cout << list[i] << " ";
    }
	//find the largest in the list
    max = largest(list, size);
	cout << endl; 
    cout << max << endl;
	cout << list << endl;
    cout << endl;

    return 0;
}

//read data from the user
int readData(int list[])
{
	int size = 0;
	cout << "How many numbers would you like to enter?(CAP=10):";
	cin >> size;
	if(size >= CAP)
	{
		cout << "Too large!" << endl;
		exit(0);
	} 
	cout << "Please enter your numbers:";
	for(int i = 0; i < size; i++)
	{
		cin >> list[i];
	}
	return size;
}

//largest function
int largest(int list[], int size)
{
	int max = 0;
	//find the largest in the list
    max = list[0];
    for(int i = 1; i < size; i++)
    {
        if(list[i] > max)
            max = list[i];
    }
	return max;
}

//read data using a while loop
void readData1(int list[], int &size)
{
	cout << "Enter whole numbers ('q' to quit):";
	cin >> list[size++];
	while(cin)
	{
		cin >> list[size++];
	}
	//fix cin and stop reading
	cin.clear();
	cin.ignore(5, '\n');
}




		
	
