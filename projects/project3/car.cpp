//implementation for cars.h
#include "cars.h"

//default constructor
Car::Car()
{
	strcpy(carName, "No name");
	mpg = 0;
	cylinders = 0;
	displacement = 0;
	horsepower = 0;
	weight = 0;
	acceleration = 0;
	model = 0;
	origin = ILLEGAL; 
}

//construc w/parameters

Car::Car(char tempCarName[], double tempMpg, int tempCylinders, double tempDisplacement, double tempHorsepower, double tempWeight, double tempAcceleration, int tempModel, Origin tempOrigin)
{
	strcpy(carName, tempCarName);
	mpg = tempMpg;
	cylinders = tempCylinders;
        displacement = tempDisplacement;
        horsepower = tempHorsepower;
        weight = tempWeight;
        acceleration = tempAcceleration;
        model = tempModel;
        origin = tempOrigin;
}

//destuctor
Car::~Car()
{
//nothing to do now
}

//mutators
void Car::setCarName(char newCarName[])
{
	strcpy(carName, newCarName);
}

void Car::setMpg(double newMpg)
{
	mpg = newMpg;
}

void Car::setCylinders(int newCylinders)
{
	cylinders = newCylinders;
}

void Car::setDisplacement(double newDisplacement)
{
	displacement = newDisplacement;
}

void Car::setHorsepower(double newHorsepower)
{
	horsepower = newHorsepower;
}

void Car::setWeight(double newWeight)
{
	weight = newWeight;
}

void Car::setAcceleration(double newAcceleration)
{
	acceleration = newAcceleration;
}

void Car::setModel(int newModel)
{
	model = newModel;
}

void Car::setOrigin(Origin newOrigin)
{
	origin = newOrigin;
}

//accessor functions

void Car::getCarName(char returnCarName[]) const
{
	strcpy(returnCarName, carName);
}

double Car::getMpg() const
{
	return mpg;
}

int Car::getCylinders() const
{
        return cylinders;
}

double Car::getDisplacement() const
{
        return displacement;
}

double Car::getHorsepower() const
{
        return horsepower;
}

double Car::getWeight() const
{
        return weight;
}

double Car::getAcceleration() const
{
        return acceleration;
}

int Car::getModel() const
{
        return model;
}

Origin Car::getOrigin() const
{
	return origin;
}

//print to console
void Car::printCar()
{
	char originDesc[MAXCHAR];
	printOrigin(this->origin, originDesc);
	cout << carName << ';' << mpg << ';' << cylinders << ';' << displacement << ';' << horsepower << ';' << weight << ';' << acceleration << ';' << model << ';' << originDesc << endl;
}

//print to file
void Car::printCar(ofstream &outFile)
{
        char originDesc[MAXCHAR];
        printOrigin(this->origin, originDesc);
        cout << carName << ';' << mpg << ';' << cylinders << ';' << displacement << ';' << horsepower << ';' << weight << ';' << acceleration << ';' << model << ';' << originDesc << endl;
}

//assign origin based off of letter and return origin
Origin readOrigin(char letter)
{
	Origin tempOrigin;
	switch(tolower(letter))
	{
		case 'u':
			tempOrigin = static_cast<Origin>(0);
			break;
		case 'j':
			tempOrigin = static_cast<Origin>(1);
			break;
		case 'e':
			tempOrigin = static_cast<Origin>(2);
			break;
		default:
			tempOrigin = static_cast<Origin>(3);
	}
	return tempOrigin;
}

//populate originDesc based on origin
void printOrigin(Origin tempOrigin, char originDesc[])
{
	switch(tempOrigin)
	{
		case 0:
			strcpy(originDesc, "US");
			break;
		case 1:
			strcpy(originDesc, "Japan");
			break;
		case 2:
			strcpy(originDesc, "Europe");
			break;
		case 3:
			strcpy(originDesc, "ILLEGAL");
			break;
	}
	return;
}

