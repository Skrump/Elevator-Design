/*
 * ControlHub.h
 *
 *  Created on: Oct 19, 2017
 *      Author: daneg_000
 */

#ifndef CONTROLHUB_H_
#define CONTROLHUB_H_

#include <iostream>
#include <string>
#include <ctime>
#include "PriorityQueue.h"
#include "Elevator.h"
#include "Floor.h"

using namespace std;

class ControlHub { //this WIP class is for complex algorithms involving the floor priority,
			//determining which elevator moves upon a request, etc.
	int numFloors;	//# of floors in the building
	int elevators; //# of elevators in the system
	int *topFloors; //most requested floors (left -> right is greatest -> least)
	bool *locked; //this array is for determining which elevators are locked to the public (*locked[])
	PriorityQueue myQueue;	//Queue Object
	Elevator myElevator;	//Elevator Object (must change to an array at a later point)
	Floor *myFloorArr;
				   

public: //includes some functions moved from Elevator class so far, help expand if necessary

	ControlHub();
	ControlHub(int a);
	ControlHub(int a, int f);	//constructor that takes the number of floors as well
	~ControlHub();
	void runMe();	//runs the program
	int getMostReqFloor();
	void addMostReqFloor(int num);
	bool getStatus(int b);
	void printDisplay();
};



#endif /* CONTROLHUB_H_ */
