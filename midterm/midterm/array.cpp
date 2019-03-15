//array.cpp 

#include "array.h"

//put the implementations of your assigned functions here

int numOfEven(int list[], int size){

	int even = 0;

	for (int i = 0; i < size; i++){

		if ((list[i]%2) == 0){
		even++;
		}
	}
return even;
}

void insert(int list[], int& size, int newInt, int position){

	for (int i = size; i > position; i--){
	
	list[i] = list[i-1];
	}
	list[position] = newInt;
	size++;
}
