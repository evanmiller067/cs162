#include "array.h"
using namespace std;

const int CAP = 100;
int main()
{
	int list[CAP];
	int size = 10;
    build(list, size);
    display(list, size);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
	int target = 0;
	int sum = 0;
	
	sum = sumOfArray(list, size);
    
	cout << "The sum of the array is: " << sum << endl;
	
	display(list, size);
	
	target = 63;
	
	remove(list, size, target);

	cout << "modified array: ";
	display(list, size);

    return 0;
}
