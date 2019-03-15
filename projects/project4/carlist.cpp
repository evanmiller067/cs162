#include "carlist.h"
#include "tools.h"

//constructors
CarList::CarList()
{
        capacity = CAP;
	//allocate memory for an array of cars
	list = new Car[capacity];
	size = 0;
}

//constructor from file
CarList::CarList(char fileName[])
{
	capacity = CAP;
	//allocate memory for an array of cars
	list = new Car[capacity];
        size = 0;
        ifstream inFile;
        Car aCar;
        char tempCarName[MAXCHAR], originDesc[MAXCHAR];
        double tempMpg, tempDisplacement, tempHorsepower, tempWeight, tempAcceleration;
        int tempCylinders, tempModel;
        Origin tempOrigin;

        inFile.open(fileName);
        if(!inFile)
        {
                cout << "Cannot open File. Exiting..." << endl;
                exit(0);
        }

        inFile.getline(tempCarName, MAXCHAR, ';');
        while(!inFile.eof())
        {
                inFile >> tempMpg;
                inFile.ignore(50, ';');
                inFile >> tempCylinders;
                inFile.ignore(50, ';');
                inFile >> tempDisplacement;
                inFile.ignore(50, ';');
                inFile >> tempHorsepower;
                inFile.ignore(50, ';');
                inFile >> tempWeight;
                inFile.ignore(50, ';');
                inFile >> tempAcceleration;
                inFile.ignore(50, ';');
                inFile >> tempModel;
                inFile.ignore(50, ';');
                inFile.getline(originDesc, MAXCHAR, '\n');
                tempOrigin = readOrigin(originDesc[0]);
                //populate aCar
                aCar.setCarName(tempCarName);
                aCar.setMpg(tempMpg);
                aCar.setCylinders(tempCylinders);
                aCar.setDisplacement(tempDisplacement);
                aCar.setHorsepower(tempHorsepower);
                aCar.setWeight(tempWeight);
                aCar.setAcceleration(tempAcceleration);
                aCar.setModel(tempModel);
                aCar.setOrigin(tempOrigin);
                addCar(aCar);
                inFile.getline(tempCarName, MAXCHAR, ';');
        }
        inFile.close();
}

//destructor
CarList::~CarList()
{
	//delete list
	if(list)
	{
		delete [] list;
		list = NULL;
	}
}
//add a car to database
void CarList::addCar(Car aCar)
{

	//if size == cap grow array
	if(size == capacity)
	{
		growList();
	}
	//operator overloaded
	list[size++] = aCar;
}


//search by name
void CarList::searchByCarName()
{
        char searchName[MAXCHAR];
        char tempCarName[MAXCHAR];
        cout <<  "Please enter a name to search: ";
        cin.get(searchName, MAXCHAR);
        convertCase(searchName);
        for(int i = 0; i < size; i++)
        {
                list[i].getCarName(tempCarName);
                convertCase(tempCarName);
                if (strstr(tempCarName, searchName) != NULL)
                {
                        list[i].printCar();
                }
        }
}

//search by Origin
void CarList::searchByOrigin()
{
        char letter;
        Origin searchOrigin;
        Origin tempOrigin;
        cout << "Please enter an Origin to search (J-Japan, U-US, E-Europe): ";
        cin >> letter;
        searchOrigin = readOrigin(letter);
        for(int i = 0; i < size; i++)
        {
                tempOrigin = list[i].getOrigin();
                if(searchOrigin == tempOrigin)
                {
                        list[i].printCar();
                }
        }
}

//search by model
void CarList::searchByModel()
{
        int searchModel;
        int tempModel;
        cout << "Please enter a model to search: ";
        cin >> searchModel;
        for(int i = 0; i < size; i++)
        {
                if(searchModel == tempModel)
                {
                        list[i].printCar();
                }
        }
}

//write data to file
void CarList::writeData(char fileName[])
{
        ofstream outFile;
        outFile.open(fileName);
        for(int i = 0; i < size; i++)
        {
                list[i].printCar(outFile);
        }
}

//Display list of Cars
void CarList::showList()
{
        for(int i = 0; i < size; i++)
        {
                cout << i+1 << ") ";
                list[i].printCar();
        }
        cout << endl;
}

//remove a car from list
void CarList::removeCar()
{
        int delIndex = 0;
        delIndex = readInt("Please enter index of car to remove: ");
        if(delIndex < size)
        {
                for (int i = delIndex; i < size; i++)
                {
                        list[i-1] = list[i];
                }
        }
        size--;
}
//adds to capacity of list when full
void CarList::growList()
{
	capacity += GROWTH;
	char tempCarName[MAXCHAR];

	Car *tempList = new Car[capacity];
	for (int i = 0; i < size; i++)
	{
		//assignment operator overloaded
		tempList[i] = list[i];
	}
	
	delete[] list;
	list = tempList;
	tempList = NULL;
}    
