/*
 * ControlHub.cpp
 *
 *  Created on: Oct 19, 2017
 *      Author: daneg_000
 */

#include "ControlHub.h"

ControlHub::ControlHub() {

	elevators = 0;
	topFloors = {0};
	locked = new bool[1];
	locked = false;
}

ControlHub::ControlHub(int a) {

	elevators = a;
	topFloors = {0};
	locked = false;
}

int ControlHub::getMostReqFloor()
{

	int d;

	//run priority algorithm

	return d;
}

void ControlHub::addMostReqFloor(int num)
{

	//move floors down the array, then replace top spot

	topFloors[0] = num;
}

bool ControlHub::getStatus(int b) {

	return locked[b];
}

void ControlHub::printDisplay()
{

	cout << "Floors " << topFloors[0] << ", " << topFloors[1] << ", & " << topFloors[2] << " have priority." << endl;
}
