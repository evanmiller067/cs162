#include "cars.h"
#include "tools.h"

int main()
{
	//create a list of cars
	char fileName[MAXCHAR] = "cars.txt";
	CarList store(fileName);
	char option;
	
	do
	{
		displayMenu();
		option = readOption();
		exeCmd(option, store);
	}while(tolower(option != 'q'));
	store.writeData(fileName);
	
	return 0;
}
