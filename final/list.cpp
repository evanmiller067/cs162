#include "list.h"

//put the implementation of your assigned functions here

int countEven(node * head)
{
	node * temp = head;
	int even = 0;

	while(temp != NULL)
	{	
		if(temp->data % 2 == 0)
		{
			even++;
			temp = temp->next;
			continue;
		}
		if(temp->data % 2)
		{
			temp = temp->next;
			continue;	
		}
	
	}
	
	return even;
}

int removeEven(node * &head)
{
	node **currentptr = &head;
	int remove = 0;

	while(*currentptr)
	{
		if((*currentptr)->data % 2)
		{
			currentptr = &(*currentptr)->next;
			continue;
		}
		node * p = *currentptr;
		*currentptr = p->next;
		delete p;
		remove++;
	}
	return remove;
}
