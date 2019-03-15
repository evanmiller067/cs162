#include "carlist.h"
#include "tools.h"

//constructors
CarList::CarList()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

//constructor from file
CarList::CarList(char fileName[])
{
        head = NULL;
	tail = NULL;
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
                inFile.ignore(5, ';');
                inFile >> tempCylinders;
                inFile.ignore(5, ';');
                inFile >> tempDisplacement;
                inFile.ignore(5, ';');
                inFile >> tempHorsepower;
                inFile.ignore(5, ';');
                inFile >> tempWeight;
                inFile.ignore(5, ';');
                inFile >> tempAcceleration;
                inFile.ignore(5, ';');
                inFile >> tempModel;
                inFile.ignore(5, ';');
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
        Node *curr = head;
        while(curr)
        {
                head = curr->next;
                delete curr;
                curr = head;
        }
        tail = NULL;
}

//add a car to database
void CarList::addCar(Car &aCar)
{
	Node *newNode = NULL, *curr = NULL, *prev = NULL;
	char str1[MAXCHAR], str2[MAXCHAR], tempCarName[MAXCHAR];
	double tempMpg, tempDisplacement, tempHorsepower, tempWeight, tempAcceleration;
        int tempCylinders, tempModel;
        Origin tempOrigin;
	//populate newNode
	newNode = new Node;
	newNode->data = aCar;
	newNode->next = NULL;
	//check to see if list is empty
	if (!head)
	{
		head = newNode;
		tail = newNode;
	}
	//if list is not empty, then insert sorted by name
	else
	{
		curr = head;
		curr->data.getCarName(str1);
		newNode->data.getCarName(str2);
		while(curr && isLessThan(str1, str2))
		{
			prev = curr;
			curr = curr->next;
			if(curr)
			{
				curr->data.getCarName(str1);
			}
		}
		//check to see if we are at the end of our list
		if(!curr)
		{
			tail->next = newNode;
			tail = newNode;
		}
		//insert in between
		else if(prev)
		{
			newNode->next = curr;
			prev->next = newNode;
		}
		//insert at the beginning
		else
		{
			newNode->next = curr;
			head = newNode;
		}
	}
	size++;
}
//return the size of the list
int CarList::getSize()
{
	return size;
}
//search by name
void CarList::searchByCarName()
{
	char searchName[MAXCHAR];
	char tempCarName[MAXCHAR];
	bool flag = false;
	cout << "Enter a name to search for: ";
	cin.get(searchName, MAXCHAR);
	convertCase(searchName);

	for(Node *curr = head; curr; curr = curr->next)
	{
		curr->data.getCarName(tempCarName);
		convertCase(tempCarName);
		if(strstr(tempCarName, searchName) != NULL)
		{
			curr->data.printCar();
			flag = true;
		}
	}

	if(!flag)
	{
		cout << "No car with that name found. " << endl;
	}
}
//search by Origin
void CarList::searchByOrigin()
{
        char letter;
        Origin searchOrigin;
        Origin tempOrigin;
	bool flag = false;
        cout << "Please enter an Origin to search (J-Japan, U-US, E-Europe): ";
        cin >> letter;
        searchOrigin = readOrigin(letter);
        for(Node *curr = head; curr; curr = curr->next)
        {
                tempOrigin =curr->data.getOrigin();
                if(searchOrigin == tempOrigin)
                {
                        curr->data.printCar();
			flag = true;
                }
        }
	if(!flag)
	{
		cout << "Origin not Found. " << endl;
	}
}
//search by model
void CarList::searchByModel()
{
        int searchModel;
        int tempModel;
	bool flag = false;
        cout << "Please enter a model to search: ";
        cin >> searchModel;
        for(Node *curr = head; curr; curr = curr->next)
        {
		tempModel = curr->data.getModel();
                if(searchModel == tempModel)
                {
                        curr->data.printCar();
			flag = true;
                }
        }
	if(!flag)
	{
		cout << "No model number match found. " << endl;
	}
}

//writes the data to the file
void CarList::writeData(char fileName[])
{
        ofstream outFile;
        outFile.open(fileName);
        Node *curr;
        for(curr = head; curr; curr = curr->next)
        {
                curr->data.printCar(outFile);
        }
}
//displays the list
void CarList::showList()
{
        int count = 1;
        Node *curr;
        for(curr = head; curr; curr = curr->next)
        {
                cout << count << ".";
                curr->data.printCar();
                count++;
        }
        cout << endl;
}

//removes a car from the list
void CarList::removeCar()
{
        int count = 1;
        int toRemove = 0;
        if(!size){
                cout << "Nothing to remove! Terminating..." << endl;
                return;
        }
        toRemove = readInt("Select index of car to remove:");
        Node *curr = head, *prev = NULL;
        while(toRemove < 1 || toRemove > size){
                toRemove = readInt("Bad Index, please re-enter:");
        }
        while(curr && count < toRemove){
                prev = curr;
                curr = curr->next;
                count++;
        }
        if(!prev){
                head = curr->next;
        } else if(curr == tail){
                prev->next = curr->next;
                tail = prev;
        } else {
                prev->next = curr->next;
        }
        delete curr;
        curr = NULL;
        prev = NULL;
        size--;
}

//function to compare 2 strings
bool CarList::isLessThan(char str1[], char str2[])
{
        if(strcmp(str1, str2) < 0)
                return true;
        return false;
}
