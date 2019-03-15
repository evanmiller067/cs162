#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    cout << " number of evens: " << countEven(head) << endl;
    cout << " number of removed evens: " << removeEven(head) << endl; 
    return 0;
}
