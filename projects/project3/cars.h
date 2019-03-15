#ifndef CARS_H
#define CARS_H

//Class objects for Car has carName, mpg, cylinders, displacement, horsepower, weight, acceleration, model, and origin

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//constants
const int MAXCHAR = 100;

//enumerated data type for Origin
enum Origin {US, Japan, Europe, ILLEGAL};

//data type for Car
class Car
{
	private:
		char carName[MAXCHAR];
		double  mpg;
		int cylinders;
		double displacement;
		double horsepower;
		double weight;
		double acceleration;
		int model;
		Origin origin;
	public:
		//constructors
		//default constructors
		Car();
		//w/parameters
		Car(char [], double, int, double, double, double, double, int, Origin);
		//destructor
		~Car();
		//mutators
		void setCarName(char []);
		void setMpg(double);
		void setCylinders(int);
		void setDisplacement(double);
		void setHorsepower(double);
		void setWeight(double);
		void setAcceleration(double);
		void setModel(int);
		void setOrigin(Origin);
		//accessor
		void getCarName(char []) const;
		double getMpg() const;
		int getCylinders() const;
		double getDisplacement() const;
		double getHorsepower() const;
		double getWeight() const;
		double getAcceleration() const;
		int getModel() const;
		Origin getOrigin()  const;
		//print
		void printCar();
		void printCar(ofstream &);
};
Origin readOrigin(char);
void printOrigin(Origin, char []);

#endif

