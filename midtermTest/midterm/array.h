#ifndef ARRAY_H
#define ARRY_H

//array.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

/* These functions are already written and can be called to test out your code */
void build(int list[], int size);  //supplied
void display(int list[], int size);  //supplied

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:

int sumOfArray(int list[], int size);
int remove(int list[], int& size, int target);

#endif
