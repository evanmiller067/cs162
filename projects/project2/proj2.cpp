#include <iostream>
#include <fstream>
#include <cstring>

#define MAX_CH 500

using namespace std;

void userFileIn(char*);//ask for file to open
int openUI(); //open file interaction  menu
void enterCar(int&, struct CarType*); // enter new car info
void dispAllCars(int&, struct CarType*); //display all cars in file with index for each car
void removeCar(int&, struct CarType*); //remove car by index
void carOriginSearch(int&, struct CarType*); // search by origin from list of enum choices - numbers
void carNameSearch(int&, struct CarType*); //search by car name
void carModelSearch(int&, struct CarType*); //search by car model
void saveFile(int&, struct CarType*);

struct CarType
{
	char carName[MAX_CH];
	double mpg, displacement, horsepower, weight, acceleration;
	int cylinders, model;
};
	
enum CAT
{
	origin[MAX_CH], japan_origin, us_origin, europe_origin
};

int main()
{
	
	char filePath[MAX_CH];
	bool runFile;
	fstream inFile;
	int i = 0;
	int menuChoice;
	CarType  carList[MAX_CH];
	int arrayCount  = 0;
	int x = 0;
	
	
	userFileIn(filePath);
	cout << " File: " << filePath << endl;
	inFile.open(filePath, fstream::in);

	inFile.getline(carList[i].carName, MAX_CH, ';');

	while (inFile.good())
	{
		inFile.getline(carList[i].mpg, MAX_CH, ';');
		inFile.getline(carList[i].cylinders, MAX_CH, ';');
		inFile.getline(carList[i].displacement, MAX_CH, ';');
		inFile.getline(carList[i].horsepower, MAX_CH, ';');
		inFile.getline(carList[i].weight, MAX_CH, ';');
		inFile.getline(carList[i].acceleration, MAX_CH, ';');
		inFile.getline(carList[i].model, MAX_CH, ';');	
		inFile.getline(origin[i], MAX_CH, '\n');	
		i++;
		inFile.getline(carList[i].carName, MAX_CH, ';');
	} 
	inFile.close();
	runFile = true;
	arrayCount = i;
		
	while (runFile == true)
	{
		menuChoice = openUI();

		if (menuChoice == 1)
		{
			enterCar(arryCount, carList);
		}
		else if (menuChoice == 2)
		{
			for (i = 0; i < arrayCount; i++)
			{
				cout << "Index: " << i;
				cout << "Name: " << carList[i].carName;
				cout << "Cylinders: " << carList[i].cylinders;
				cout << "Displacement: " << carList[i].displacement;
				cout << "Horsepower: " << carList[i].horsepower;
				cout << "Weight: " << carList[i].weight;
				cout << "Acceleration: " << carList[i].acceleration;
				cout << "Model: " << carList[i].model;
				cout << "Origin: " << CAT.origin << endl;
			}	
		}
		else if (menuChoice == 3)
		{
			removeCar(arrayCount, carList);
		}
		 else if (menuChoice == 4)
                {
			carOriginSearch(arrayCount, carList);
                }
                else if (menuChoice == 5)
                {
			carNameSearch(arrayCount, carList);
                }
                else if (menuChoice == 6)
                {
			carModelSearch(arrayCount, carList);
                }
                else if (menuChoice == 7)
                {
			updateFile(arrayCount, carList);
			cout << "File updated. \n Exiting...";
			runFile = false;
                }
                else
                {
			cout << "Unknown error. Exiting...";
			runFile = false;
                }
	}
	return 0;		
}

void userFileIn(char* userFileName)
{
	strcpy(userFileName, "cars.txt");
}

int openUI()
{
	bool validInFile;
	int menuChoice;

	validInFile = true;

	while (validInFile == true)
	{
		cout << " 1. Enter Info for new car " << endl;
		cout << " 2. Display info for all cars in database " << endl;
		cout << " 3. Remove a car by index " << endl;
		cout << " 4. Search cars by Origin " << endl;
		case 6: cout << " you chose option 6 " << endl;
			return menuChoice;
			break;
		case 7: cout << " Goodbye. " << endl;
			validInFile = false;
			break;
		case 8: cout << " Not a valid choice, please choose again. " << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	return 0;
}
void enterCar(int &arrayCount, struct CarType *carList)
{
	arrayCount++;

	cout << "Please enter a car name: ";
	cin.get(carList[arrayCount - 1].carName, MAX_CH, ';');
	cin.clear();
	cin.ignore(100, '\n');

	cout << "Please enter MPG: ";
	cin.get(carList[arrayCount - 1].mpg, MAX_CH, ';');
	cin.clear();
	cin.ignore(100, '\n');

	cout << "Please enter Cylinders: ";
	cin.get(carList[arrayCount - 1].cylinders, MAX_CH, ';');
	cin.clear();
	cin.ignore(100, '\n');

	cout << "Please enter Displacement: ";
	cin.get(carList[arrayCount - 1].displacement, MAX_CH, ';');
	cin.clear();
	cin.ignore(100, '\n');

	cout << "Please enter Horsepower: ";
	cin.get(carList[arrayCount - 1].horsepower, MAX_CH, ';');
	cin.clear();
	cin.ignore(100, '\n');

	cout << "Please enter Weight: ";
	cin.get(carList[arrayCount - 1].weight, MAX_CH, ';');
	cin.clear();
	cin.ignore(100, '\n');

	cout << "Please enter Acceleration: ";
	cin.get(carList[arrayCount - 1].acceleration, MAX_CH, ';');
	cin.clear();
	cin.ignore(100, '\n');

	cout << "Please enter car Model: ";
	cin.get(carList[arrayCount - 1].model, MAX_CH, ';');
	cin.clear();
	cin.ignore(100, '\n');

	cout << "Please enter the country of origin: ";
	cin.get(carList[arrayCount - 1].origin, MAX_CH, '\n');
	cin.clear();
	cin.ignore(100, '\n');
}
void dispAllCars(int &arrayCount, CarType *carList)
{
	for (int i = 0; i < arrayCount; i++)
	{
		cout << "Index: " << i;
		cout << "Name: " << carList[i].carName;
		cout << "Cylinders: " << carList[i].cylinders;
		cout << "Displacement: " << carList[i].displacement;
		cout << "Horsepower: " << carList[i].horsepower;
		cout << "Weight: " << carList[i].weight;
		cout << "Acceleration: " << carList[i].acceleration;
		cout << "Model: " << carList[i].model;
		cout << "Origin: " << carList[i].origin << endl;
	}
}
void removeCar(int &arrayCount, struct CarType *carList)
{
	bool inCheck = false;
	int numIndex;

	while (inCheck == false)
	{
		cout << "Please enter car index number to remove: ";
		cin >> numIndex;
		cin.clear();
		cin.ignore(100, '\n');

		if (numIndex < 0 || numIndex >(arrayCount - 1))
		{
			cout << "Input out of bounds. Number must be between 0 and " << (arrayCount - 1);
		}
		else
		{
			inCheck = true;
		}
	}

	for (int i = 0; i < arrayCount; i++)
	{
		if (i == numIndex)
		{
			for (int r = i; r < arrayCount - 1; r++)
			{
				strcpy(carList[r].carName, carList[r + 1].carName);
				strcpy(carList[r].mpg, carList[r + 1].mpg);
				strcpy(carList[r].cylinders, carList[r + 1].cylinders);
				strcpy(carList[r].displacement, carList[r + 1].displacement);
				strcpy(carList[r].horsepower, carList[r + 1].horsepower);
				strcpy(carList[r].weight, carList[r + 1].weight);
				strcpy(carList[r].acceleration, carList[r + 1].acceleration);
				strcpy(carList[r].model, carList[r + 1].model);
				strcpy(carList[r].origin, carList[r + 1].origin);
				arrayCount--;

			}
		}

	}
}
void carOriginSearch(int &arrayCount, struct CarType *carList)
{
	char findOrigin[MAX_CH];
	int  found = 0;

	cout << "Enter Car Origin: ";
	cin.get(findOrigin, MAX_CH, '\n');
	cin.clear();
	cin.ignore(100, '\n');

	for (int i = 0; i <= arrayCount; i++)
	{
		if (strcmp(carList[i].origin, findOrigin) == 0)
		{
			cout << carList[i].origin << ";" << endl;
			cout << carList[i].carName << ";";
			cout << carList[i].mpg << ";";
			cout << carList[i].cylinders << ";";
			cout << carList[i].displacement << ";";
			cout << carList[i].horsepower << ";";
			cout << carList[i].weight << ";";
			cout << carList[i].acceleration << ";";
			cout << carList[i].model << ";" << endl;
			found++;
		}
		else if (i == arrayCount)
		{
			cout << found << " cars found originating from " << findOrigin << endl;
		}
	}
}
void carNameSearch(int &arrayCount, struct CarType *carList)
{
	char findName[MAX_CH];
	int  found = 0;

	cout << "Enter Car Name: ";
	cin.get(findName, MAX_CH, ';');
	cin.clear();
	cin.ignore(100, '\n');

	for (int i = 0; i <= arrayCount; i++)
	{
		if (strcmp(carList[i].carName, findName) == 0)
		{
			cout << carList[i].carName << ";";
			cout << carList[i].mpg << ";";
			cout << carList[i].cylinders << ";";
			cout << carList[i].displacement << ";";
			cout << carList[i].horsepower << ";";
			cout << carList[i].weight << ";";
			cout << carList[i].acceleration << ";";
			cout << carList[i].model << ";";
			cout << carList[i].origin << ";" << endl;
			found++;
		}
		else if (i == arrayCount)
		{
			cout << found << " Cars found with the name  " << findName << endl;
		}
	}
}
void carModelSearch(int &arrayCount, struct CarType *carList)
{
	char findModel[MAX_CH];
	int  found = 0;

	cout << "Enter Car Model: ";
	cin.get(findModel, MAX_CH, ';');
	cin.clear();
	cin.ignore(100, '\n');

	for (int i = 0; i <= arrayCount; i++)
	{
		if (strcmp(carList[i].model, findModel) == 0)
		{
			cout << carList[i].model << ";";
			cout << carList[i].carName << ";";
			cout << carList[i].mpg << ";";
			cout << carList[i].cylinders << ";";
			cout << carList[i].displacement << ";";
			cout << carList[i].horsepower << ";";
			cout << carList[i].weight << ";";
			cout << carList[i].acceleration << ";";
			cout << carList[i].origin << ";" << endl;
			found++;
		}
		else if (i == arrayCount)
		{
			cout << found << " Cars found with the model  " << findModel << endl;
		}
	}
}
void saveFile(int &arrayCount, struct CarType *carList)
{
	fstream outFile;
	char deli[2] = ";";

	outFile.open("cars.txt", fstream::out | fstream::trunc);
	for (int i = 0; i < arrayCount; i++)
	{
		if (i != (arrayCount - 1))
		{
			strcat(carList[i].carName, deli);
			strcat(carList[i].mpg, deli);
			strcat(carList[i].cylinders, deli);
			strcat(carList[i].displacement, deli);
			strcat(carList[i].horsepower, deli);
			strcat(carList[i].weight, deli);
			strcat(carList[i].acceleration, deli);
			strcat(carList[i].model, deli);
			strcat(carList[i].origin, '\n');
			outFile << carList[i].carName << carList[i].mpg << carList[i].cylinders << carList[i].displacement << carList[i].horsepower << carList[i].weight << carList[i].acceleration << carList[i].model << carList[i].origin;

			strcat(carList[i].mpg, deli);
			strcat(carList[i].cylinders, deli);
			strcat(carList[i].displacement, deli);
			strcat(carList[i].horsepower, deli);
			strcat(carList[i].weight, deli);
			strcat(carList[i].acceleration, deli);
			strcat(carList[i].model, deli);
			strcat(CAT[i].origin, '\n');
			outFile << carList[i].carName << carList[i].mpg << carList[i].cylinders << carList[i].displacement << carList[i].horsepower << carList[i].weight << carList[i].acceleration << carList[i].model << CAT[i].origin;
   
		}
		 else if (i == (arrayCount - 1))
                {
                        strcat(carList[i].carName, deli);
                        strcat(carList[i].mpg, deli);
                        strcat(carList[i].cylinders, deli);
                        strcat(carList[i].displacement, deli);
                        strcat(carList[i].horsepower, deli);
                        strcat(carList[i].weight, deli);
                        strcat(carList[i].acceleration, deli);
                        strcat(carList[i].model, deli);
                        strcat(CAT[i].origin, '\n');
                        outFile << carList[i].carName << carList[i].mpg << carList[i].cylinders << carList[i].displacement << carList[i].horsepower << carList[i].weight << carList[i].acceleration << carList[i].model << CAT[i].origin; 
                
		}
	}
	outFile.close();
}


