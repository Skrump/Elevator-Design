#include "PriorityQueue.h"


PriorityQueue::PriorityQueue()
{
    root = new node;
    root->next = 0;
    root->x = 5;
    currPtr = new node;
	currPtr = NULL;
}

PriorityQueue::~PriorityQueue()
{
    delete root;
}

void PriorityQueue::linkedList()
{
    
}

bool PriorityQueue::empty()
{
    
	if (size() == 0) {

		return 1;
	}

	else {

		return 0;
	}
}

int PriorityQueue::size()
{
    int size = 0;
    
	while(currPtr != NULL) { //this is merely a placeholder condition to attempt to state the idea that this loop will go until the next node in the list is a null node

		size++;
	}

	return size;
}

node PriorityQueue::front()
{
    
	return *currPtr; 
}

void PriorityQueue::enqueue()
{
    
}

void PriorityQueue::dequeue()
{
    
}

void PriorityQueue::deleteEnd()
{
    
}
