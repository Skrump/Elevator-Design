/*
 * ControlHub.cpp
 *
 *  Created on: Oct 19, 2017
 *      Author: daneg_000
 */
#include "ControlHub.h"

ControlHub::ControlHub() {

	elevators = 0;
	mostReqFloor = 0;
	locked = new bool[1];
	locked[0] = false;
}

ControlHub::ControlHub(int a) {

	elevators = a;
	locked[a] = false;
}

int ControlHub::getMostReqFloor()
{
	return mostReqFloor;
}

void ControlHub::addMostReqFloor(int num)
{
	mostReqFloor = num;
}

bool ControlHub::getStatus(int b) {

	return locked[b];
}

void ControlHub::printDisplay()
{

	cout << "display" << endl; //wip
}

void ControlHub::grantPriority()
{

	//cout << name << " has priority" << endl; //wip
	cout << mostReqFloor << " has priority" << endl;
}
