//array.cpp 

#include "array.h"

//put the implementations of your assigned functions here
int sumOfArray(int list[], int size){
	
	int total = 0;

	for (int i = 0; i <= size; i++){

		total = list[i+i+1];			
		}
return total;
}
int remove(int list[], int& size, int target){

	for (int i = 0; i <= size; i++){

		if (list[i] == target){
			
			list[i] = (list[i]-target);
		}
	}
return 0;	
}
