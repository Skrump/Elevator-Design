/*
 * ControlHub.cpp
 *
 *  Created on: Oct 19, 2017
 *      Author: daneg_000
 */

Hub::Hub() {

	elevators = 0;
	locked[0] = {false};
}

Hub::Hub(int a) {

	elevators = a;
	locked[a] = {false};
}

int Elevator::getMostReqFloor()
{
	return mostReqFloor;
}

void Elevator::addMostReqFloor(int num)
{
	mostReqFloor = num;
}

bool Hub::getStatus(int b) {

	return locked[b];
}

void Elevator::printDisplay()
{

	cout << "display" << endl; //wip
}

void Elevator::grantPriority()
{

	cout << name << " has priority" << endl; //wip
}
