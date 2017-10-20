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
    
	while(currPtr != NULL) {

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
    //add to queue (signal from Floor::request() could be used here)
}

void PriorityQueue::dequeue()
{
    //delete from queue (signal from Floor::reached() could be used here)
}

void PriorityQueue::deleteEnd()
{
    
}
