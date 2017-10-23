#include "Elevator.h"
#include "Floor.h"

Elevator::Elevator()
{
	name = "Elevator 0";
	currWeight = 0;
	maxWeight = 0;
	status = true;
	//numFloors();
}

Elevator::Elevator(string a, double max, double curr, int most, bool stat)
{
	name = a;
	currWeight = curr;
	maxWeight = max;
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
	if(_doorOpen = false) 
	{
		//floor++
	}
	else
	{
		return true;//currentfloor
	}
	//wip
}

bool Elevator::goDown()
{
	if(_doorOpen = false) 
	{
		//floor--
	}
	else 
	{
		return true;//currentfloor
	}
	//wip
}

bool Elevator::openDoors()
{
	_doorOpen = true;
	return 1; 
	//wip
}

bool Elevator::closeDoors()
{
	_doorOpen = false;
	return 1;
	//wip
}

void Elevator::updateStatus()
{
	status = ~status; //true (operational) -> false (error) OR false -> true
}
