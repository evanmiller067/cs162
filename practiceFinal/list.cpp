#include "list.h"
#include <iostream>
using namespace std;

//put the implementation of your assigned functions here

int sumOfList(node * head)
{
//compute and return the sum of intergers in the liked list

	int sum = 0;

	node *runner = head;

	while(runner->next!=NULL)
	{
		sum+=runner->data;
		runner = runner->next;
	}
	return sum;
}
void insert(node *& head, int position, int newInt)
{
//insert newInt at index "position" where index starts at 0
int count = 0;
node *runner = head;
while(count!=position-1)
{
	runner = runner->next;
	count++;
}
node * newNode=(struct node*)malloc(sizeof(struct node));
newNode->data = newInt;
newNode->next = runner->next;
runner->next = newNode;
}
