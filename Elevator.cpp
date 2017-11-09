#include "Elevator.h"
#include "Floor.h"

Elevator::Elevator()
{
	name = "Elevator 0";
	currWeight = 0;
	maxWeight = 0;
	status = true;
	time = 0;
	_doorOpen = false;
	currFloor = 1;
}

Elevator::Elevator(const Elevator& obj)
{
	name = obj.name;
	currWeight = obj.currWeight;
	maxWeight = obj.maxWeight;
	status = obj.status;
	time = obj.time;
	_doorOpen = obj._doorOpen;
	currFloor = obj.currFloor;
}

Elevator::Elevator(const char a[11], double max, double curr, int most, bool stat, bool door)
{
	name = a;
	currWeight = curr;
	maxWeight = max;
	status = stat;
	time = 0;
	_doorOpen = door;
	currFloor = 1;
}

Elevator::Elevator(string a, double max, double curr, int most, bool stat, double t, bool door)
{
	name = a;
	currWeight = curr;
	maxWeight = max;
	status = stat;
	time = t;
	_doorOpen = door;
	currFloor = 1;
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

double Elevator::getTime()
{
	return time;
}

void Elevator::changeTime(double t)
{
	time = t;
}

int Elevator::getCurrFloor() {
	
	return currFloor;
	
}	

void Elevator::goUp(int f)
{
	cout << "Going up" << endl;
	currFloor = f;
	cout << "Now at floor " << currFloor << endl;
	//floor++	
	//wip
}

void Elevator::goDown(int g)
{
	cout << "Going down" << endl;
	currFloor = g;
	cout << "Now at floor " << currFloor << endl;
	//floor--
	//wip
}

bool Elevator::openDoors()
{
	_doorOpen = true;
	cout << "Doors opened." << endl;
	return 1;
	//wip
}

bool Elevator::closeDoors()
{
	_doorOpen = false;
	double weight = 0;
	cout << "Please enter weight of the passenger(s) that left." << endl;
	cin >> weight;
	currWeight = currWeight - weight;
	cout << "Doors closed" << endl;
	updateStatus();
	return 1;
	//wip
}

void Elevator::updateStatus()
{
	status = ~status; //true (operational) -> false (error) OR false -> true
	if(currWeight >= maxWeight)
	{
		cout << "Current weight: " << currWeight << " exceeds maximum allotted weight of : " << maxWeight << endl;
		cout << "Please wait until the next elevator." << endl;
	}
	else
	{
		cout << "Current weight: " << currWeight << " out of maximum weight limit: " << maxWeight << endl;
	}
}
