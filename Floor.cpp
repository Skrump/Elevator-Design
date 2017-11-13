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

void Floor::changeReq(int num)
{
	requests = num;
}

void Floor::addReq()
{
	requests = requests + 1;
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
	//should also signal to create a node
	pending = true;

	return pending;
}

bool Floor::reached()
{
	//should also signal to remove from queue
	cout << "Floor reached!" << endl;
	pending = false;

	return 1;
}

int Floor::getFloor()
{
	//this should help create nodes

	return number;
}

void Floor::changeFloor(int num)
{
	number = num;
}

bool Floor::getStatus()
{
	//this is to help the queue, if necessary

	return pending;
}


