/*
 * ControlHub.h
 *
 *  Created on: Oct 19, 2017
 *      Author: daneg_000
 */

#ifndef CONTROLHUB_H_
#define CONTROLHUB_H_

class Hub { //this class is for complex algorithms involving the floor priority,
			//determining which elevator moves upon a request, etc.

	int elevators; //# of elevators in the system
	bool locked[]; //this array is for determining which elevators are locked
				   //to the public

public: //wip class with some functions moved from Elevator

	Hub();
	Hub(int a);
	int getMostReqFloor();
	void addMostReqFloor(int num);
	bool getStatus(int b);
	void printDisplay();
	void grantPriority();
};



#endif /* CONTROLHUB_H_ */
