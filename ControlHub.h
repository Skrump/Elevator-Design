/*
 * ControlHub.h
 *
 *  Created on: Oct 19, 2017
 *      Author: daneg_000
 */

#pragma once
#include <iostream>
using namespace std;

class ControlHub { //this class is for complex algorithms involving the floor priority,
			//determining which elevator moves upon a request, etc.

	int elevators; //# of elevators in the system
	int mostReqFloor;
	bool *locked; //this array is for determining which elevators are locked
				   //to the public

public: //wip class with some functions moved from Elevator

	ControlHub();
	ControlHub(int a);
	int getMostReqFloor();
	void addMostReqFloor(int num);
	bool getStatus(int b);
	void printDisplay();
	void grantPriority();
};



/* CONTROLHUB_H_ */
