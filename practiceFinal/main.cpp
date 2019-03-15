#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
	insert(head,3,7);
	sumOfList(head);

	cout << "list after insertion is: " << endl;

    display(head);
    destroy(head);
    
    return 0;
}
