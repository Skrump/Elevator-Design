#include "Floor.h"

Floor::Floor()
{
	requests = 0;
	priority = 0;
	pending = false;
	number = 0;
}

Floor::Floor(int numReq, int prior, bool pend, int num)
{
	requests = numReq;
	priority = prior;
	pending = pend;
	number = num;
}

int Floor::getReq()
{
	return requests;
}

void Floor::addReq(int num)
{
	requests = num;
}

int Floor::getPriority()
{
	return priority;
}

void Floor::changePriority(int num)
{
	priority = num;
}

bool Floor::request()
{
	//should also act as a signal to create a node
	pending = true;
	requests++;

	return 1;
}

bool Floor::reached()
{
	//should also act as a signal to remove from the queue
	pending = false;

	return 1;
}

int Floor::getFloor()
{
	//this should help create nodes

	return number;
}

int Floor::getStatus()
{
	//this is to help the queue, if necessary

	return pending;
}


