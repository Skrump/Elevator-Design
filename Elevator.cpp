#include "Elevator.h"
#include "Floor.h"

Elevator::Elevator()
{
	name = "Elevator 0";
	currWeight = 0;
	maxWeight = 0;
	mostReqFloor = 0;
	status = true;
	//numFloors();
}

Elevator::Elevator(string a, double max, double curr, int most, bool stat)
{
	name = a;
	currWeight = curr;
	maxWeight = max;
	mostReqFloor = most;
	status = stat;
	//numFloors();
}

string Elevator::getName()
{
	return name;
}

void Elevator::changeName(string a)
{
	name = a;
}

double Elevator::getCurrWeight()
{
	return currWeight;
}

void Elevator::addCurrWeight(double num)
{
	currWeight = num;
}

double Elevator::getMaxWeight()
{
	return maxWeight;
}

void Elevator::addMaxWeight(double num)
{
	maxWeight = num;
}

bool Elevator::goUp()
{
	//wip
}

bool Elevator::goDown()
{
	//wip
}

bool Elevator::openDoors()
{
	//wip
}

bool Elevator::closeDoors()
{
	//wip
}

void Elevator::updateStatus()
{
	status = ~status; //true (operational) -> false (error) OR false -> true
}
