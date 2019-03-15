#ifndef CARLIST_H
#define CARLIST_H
//class object for a list of cars
#include "cars.h"

//define class CarList for array of cars and size

class CarList
{
        private:
		//struct for each node
		struct Node
		{
			Car data;
			Node *next;
		};
                Node *head;
		Node *tail;
                int size;

        public:
                //constructors
                CarList();
                CarList(char []);
                //destructor
                ~CarList();
                //database functions
                void addCar(Car &);
                void searchByCarName();
                void searchByOrigin();
                void searchByModel();
                void showList();
		int getSize();
                void removeCar();
                void writeData(char []);
		bool isLessThan(char [], char[]);
};

#endif
