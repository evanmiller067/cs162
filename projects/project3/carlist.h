#ifndef CARLIST_H
#define CARLIST_H
//class object for a list of cars
#include "cars.h"

//constants
const int CAP = 101;

//define class CarList for array of cars and size

class CarList
{
        private:
                Car list[CAP];
		int size;
        public:
                //constructors
                CarList();
                CarList(char []);
                //destructor
                ~CarList();
                //database functions
                void addCar(Car);
                void searchByCarName();
                void searchByOrigin();
		void searchByModel();
                void showList();
                void removeCar();
                void writeData(char []);
};

#endif
