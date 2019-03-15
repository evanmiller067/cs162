#include "tools.h"
#include "cars.h"

//Function implementations

//Display menu
void displayMenu()
{

        cout << "-----Welcome to the Car Database-----" << endl;
        cout << "What would you like to do? " << endl;
        cout << "[A-a]: Enter information for a new car " << endl;
        cout << "[D-d]: Display information for all cars in database with index for each car " << endl;
        cout << "[R-r]: Remove a car by index " << endl;
        cout << "[O-o]: Search for car by origin " << endl;
        cout << "[N-n]: Search for car by name " << endl;
        cout << "[M-m]: Search for car by model " << endl;
        cout << "[Q-q]: Quit " << endl;
}

//read option from user
char readOption()
{
        char input;
        cin >> input;
        cin.ignore(100, '\n');
        return input;
}

//execute user command
void exeCmd(char option, CarList &store)
{
        Car aCar;
        switch(tolower(option))
        {
        case 'a':
                addCar(aCar);
                store.addCar(aCar);
                break;
        case 'd':
                store.showList();
                break;
        case 'r':
                store.showList();
                store.removeCar();
                break;
        case 'o':
                store.searchByOrigin();
                break;
        case 'n':
                store.searchByCarName();
                break;
        case 'm':
                store.searchByModel();
                break;
        case 'q':
                break;
        default:
                cout << "Invalid input, please try again." << endl;
        }
}

int readInt(char prompt[])
{
        int temp = 0;
        cout << prompt;
        cin >> temp;

        while(!cin)
        {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid Input, please try again.";
                cin >> temp;
        }
        cin.ignore(100, '\n');

        return temp;
}

void addCar(Car &aCar)
{
        char letter;
        char tempCarName[MAXCHAR];
        int tempCylinders=0, tempModel=0;
        double tempMpg, tempDisplacement, tempHorsepower, tempWeight, tempAcceleration;
        Origin  tempOrigin;

        cout << "Enter a car name: ";
        cin.get(tempCarName, MAXCHAR, '\n');
        cin.ignore(100, '\n');
        cout << "MPG: ";
        cin >> tempMpg;
       // cout << "Cylinders(integer only): ";
       // cin >> tempCylinders;
        tempCylinders = readInt("cylinders: ");
        cout << "Displacement: ";
        cin >> tempDisplacement;
        cin.ignore(100, '\n');
        cout << "Horsepower: ";
        cin >> tempHorsepower;
        cin.ignore(100, '\n');
        cout << "Weight: ";
        cin >> tempWeight;
        cin.ignore(100, '\n');
        cout << "acceleration: ";
        cin >> tempAcceleration;
        cin.ignore(100, '\n');
        //cout << "Model(integer only): ";
        //cin >> tempModel;
        tempModel = readInt("Model: ");
        cout << "Enter Origin key: [U] for US, [J] for Japan, [E] for Europe ";
        cin >> letter;
        cin.ignore(100, '\n');
        tempOrigin = readOrigin(letter);

        aCar.setCarName(tempCarName);
        aCar.setMpg(tempMpg);
        aCar.setCylinders(tempCylinders);
        aCar.setDisplacement(tempDisplacement);
        aCar.setHorsepower(tempHorsepower);
        aCar.setWeight(tempWeight);
        aCar.setAcceleration(tempAcceleration);
        aCar.setModel(tempModel);
        aCar.setOrigin(tempOrigin);
}

void convertCase(char tempStr[])
{
        for (int i = 0; i < strlen(tempStr); i++)
        {
                tempStr[i] = toupper(tempStr[i]);
        }
}     
