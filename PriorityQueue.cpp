#include "PriorityQueue.h"


PriorityQueue::PriorityQueue()
{
     head = NULL;
     tail = head;
     currPtr = head;
     secPtr = head;
}

PriorityQueue::~PriorityQueue() {

	while (size() != 0)
    {
     	dequeue();
    }
}

node *PriorityQueue::getHead()
{
	return head;
}

node *PriorityQueue::getTail()
{
	return tail;
}

node *PriorityQueue::getCurrPtr()
{
	return currPtr;
}

node *PriorityQueue::getSecPtr()
{
	return secPtr;
}

bool PriorityQueue::isEmpty() {

 	if (head == NULL) 
 	{
 		return true;
 	}

 	else  
 		return false;
}

int PriorityQueue::size() {

    int size = 0;
    currPtr = head;
 	while(currPtr != NULL) 
 	{
 		currPtr = currPtr->next;
 		size++;
 	}

 	return size;
}

int PriorityQueue::front() {

 	return head->data;
}

int PriorityQueue::rear() {

	return tail->data;
}

void PriorityQueue::enqueue(int f)
{

	node *newNode = new node;
 	newNode->data = f;
 	newNode->next = NULL;
 	if (isEmpty())
 	{
 		head = newNode;
 		tail = newNode;
 	}

 	else
 	{
		tail->next = newNode;
		tail = newNode;
	}
}

void PriorityQueue::dequeue() {

 	node *temp = head;
 	if (head != NULL)
 	{
 		head = head->next;
 	}

 	delete temp;
}

void PriorityQueue::emplace(int f)
{
	node *newNode = new node;
 	newNode->data = f;
 	newNode->next = NULL;
 	if (isEmpty())
 	{
 		head = newNode;
 		tail = newNode;
 	}
 	else
 	{
		newNode->next = head;
		head = newNode;
	}
	
}

void PriorityQueue::display()
{
	node *temp = new node;
	temp = head;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
	if(temp == NULL)
	{
		cout << "Queue is now empty" << endl;
	}
}
