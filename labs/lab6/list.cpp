//put your implementation of LinkedList class here
#include "list.h"
#include <iostream>

using namespace std;
//gen
LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
}
/*
//dest
LinkedList::~LinkedList()
{
	Node * current = head;

	while(head != NULL)
	{
		current = head->next;
		delete head;
		head = current;
	}
}
*/
//add an item at the beginning of the linked list
bool LinkedList::addAtBeginning(int val)
{
	Node * current;
	Node * beforeCurrent; //pointer to just before current
	Node * newNode;
	bool found;

	newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		found = false;
		current = head;
		
		while(current != NULL && !found)
		{
			if (current->data >= val)
			{
				found = true;
			}
			else
			{
				beforeCurrent = current;
				current = current->next;
			}
		}
		if (current == head)
		{
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
		}
		else
		{
			if (current != NULL)
			{
				beforeCurrent->next = newNode;
				newNode->prev = beforeCurrent;
				newNode->next = current;
				current->prev = newNode;
			}
			else
			{
				beforeCurrent->next = newNode;
				newNode->prev = beforeCurrent;
				tail = newNode;
			}
		}
	}	
	return true;
}
//remove an item from list
bool LinkedList::remove(int val)
{
	Node * current; 
	Node * beforeCurrent;
	bool found;

	if (head == NULL)
	{
		cout << "Empty " << endl;

	}
	else if (head->data == val)
	{
		current = head;
		head = head->next;
		if (head != NULL)
		{
			head->prev = NULL;
		}
		else
		{
			tail = NULL;
			
		}
		delete current;
	}
	else
	{
		found = false;
		current = head;
		while (current != NULL && !found) //search list for item
		{
			if (current->data >= val)
			{
				found = true;
			}
			else
			{
				current = current->next;
			}
		}
		if (current == NULL)
		{
			cout << "That is not in the list... " << endl;
		}
		else if (current->data == val) 
		{
			beforeCurrent = current->prev;
			beforeCurrent->next = current->next;
			if (current->next != NULL)
			{
				current->next->prev = beforeCurrent;
			}
			if (current == tail)
			{
				tail = beforeCurrent;
			}
			delete current;
		}
		else
		{
			cout << "That is not in the list.." << endl;
		}
	}
	return true;
}
//print list forwards
void LinkedList::printForward() const
{
	Node * current;
	current = head;
	
	cout << "List print forwards " << endl;

	while(current != NULL)
	{
		cout << current->data << " ";
		current = current->next;
	}
}
//print list backwards
void LinkedList::printBackward() const
{
	Node * current;
	current = tail;
	
	cout << " List print backwards " << endl;

	while(current != NULL)
	{
		cout << current->data << " ";
		current = current->prev;
	}
}

