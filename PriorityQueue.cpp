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

bool PriorityQueue::isEmpty() {

 	if (head == NULL) {

 		return true;
 	}

 	else  {

 		return false;
 	}
}

int PriorityQueue::size() {

    int size = 0;
    currPtr = head;
 	while(currPtr != NULL) {

 		currPtr = currPtr->next;
 		size++;
 	}

 	return size;
}

Floor PriorityQueue::front() {

 	return head->data;
}

Floor PriorityQueue::rear() {

	return tail->data;
}

void PriorityQueue::enqueue(Floor f)
{

	node *newNode = new node;
 	newNode->data = f;
 	newNode->next = NULL;
 	if (isEmpty()){

 		head = newNode;
 		tail = newNode;
 	}

 	else
 	{

		tail->next = newNode;
		tail = newNode;
	}

    //add to queue (signal from Floor::request() could be used here)
}

void PriorityQueue::dequeue() {

 	node *temp = head;
 	if (head != NULL) {

 		head = head->next;
 	}

 	delete temp; //delete from queue (signal from Floor::reached() could be used here)
}

