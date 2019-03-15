#ifndef TOOLS_H
#define TOOLS_H

#include "cars.h"
#include "carlist.h"

// prototypes
void displayMenu();
int readInt(char prompt[]);
char readOption();
void exeCmd(char option, CarList &);
void addCar(Car &);
void convertCase(char tempStr[]);

#endif


