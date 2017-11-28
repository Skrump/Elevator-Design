/*
 * ControlHub.cpp
 *
 *  Created on: Oct 19, 2017
 */

#include "ControlHub.h"

ControlHub::ControlHub() {

	numFloors = 2;
	elevators = 0;
	locked = new bool[numFloors];
	locked[1] = false;
	myFloorArr = new Floor [numFloors];
	topFloors.resize(floor(numFloors/3));
	inputs.resize(0);
	fileVec.resize(numFloors + 1);
	fileVec.back() = 0;
	
	for (int i = 0; i < topFloors.size(); i++)
	{
		topFloors[i] = i+1;
	}
}

ControlHub::ControlHub(int a) {

	numFloors = 2;
	elevators = a;
	locked = new bool [numFloors];
	locked[1] = false;
	myFloorArr = new Floor [numFloors];
	topFloors.resize(floor(numFloors/3));
	inputs.resize(0);
	fileVec.resize(numFloors + 1);
	fileVec.back() = 0;
	
	for (int i = 0; i < topFloors.size(); i++)
	{
		topFloors[i] = i+1;
	}
}

ControlHub::ControlHub(int a, int f)
{
	if (f < 2)
		numFloors = 2;
	else 
		numFloors = f; 
	elevators = a;
	locked = new bool [f];
	locked[1] = false;
	myFloorArr = new Floor [numFloors];
	topFloors.resize(floor(numFloors/3));
	inputs.resize(0);
	fileVec.resize(numFloors + 1);
	fileVec.back() = 0;
	
	for (int i = 0; i < topFloors.size(); i++)
	{
		topFloors[i] = i+1;
	}
	
	for(int i=0; i<f; i++) //sets Floor number info
	{
		myFloorArr[i].changeFloor(i+1);
	}
	for(int j=0; j<f; j++)//checks to see if it is named correctly.
	{
		cout << "Floor " << myFloorArr[j].getFloor() << endl;
	}
}

ControlHub::ControlHub(int a, int f, vector<Elevator> ele)
{
	if (f < 2)
		numFloors = 2;
	else
		numFloors = f;
	elevators = a;
	locked = new bool [f];
	locked[1] = false;
	myFloorArr = new Floor [numFloors];
	topFloors.resize(floor(numFloors/3));
	inputs.resize(0);
	fileVec.resize(numFloors + 1);
	fileVec.back() = 0;
	
	for (int i = 0; i < topFloors.size(); i++)
	{
		topFloors[i] = i+1;
	}
	
	for(int i=0; i<f; i++) //sets Floor number info
	{
		myFloorArr[i].changeFloor(i+1);
	}
	for(int j=0; j<f; j++)//checks to see if it is named correctly.
	{
		cout << "Floor " << myFloorArr[j].getFloor() << endl;
	}
	myElevator = ele;
}

ControlHub::~ControlHub()
{
	delete [] myFloorArr;
	delete [] locked;
}

void ControlHub::runMe()
{
	bool loopMe = true;
    char next;
    int inp;
    int i = 0;
	int j = 0;
    int n = 1;
    vector<int> inputs2;
    vector<int> inputs3;
    vector<int> weight2;
    vector<int> weight3;
    updateVectors(inputs2, inputs3, weight2, weight3);
    
    PriorityQueue queue2;
    PriorityQueue queue3;

    int a = 1;
    int call = 0;
    while(a != 0)
    {
    	cout << "Please choose an option: " << endl;
    	cout << "1. Call elevator" << endl;
    	cout << "2. Request a floor" << endl;
    	cout << "3. Proceed through queue" << endl;
    	cout << "0. End program" << endl;
    	cin >> a;

    	if(a == 1)
    	{
    		cout << "Call elevator to which floor?" << endl;
    		cin >> call;
    		inputs.push_back(call);
    	}

    	if(a == 2)
    	{
    		cout << "Please enter requested floor" << endl;
    		if(cin >> inp)
    			inputs.push_back(inp);
    	}
    	if(a == 3)
    	{
    	    getFromFile();

    	    sortVec(inputs); //sorts vector
    	    sortVec(inputs2);
    	    sortVec(inputs3);

    	    findMostReqFloor();	//updates priority vector

    	    for(int x = 0; x < inputs2.size(); x++)
    	    {
    	    	queue2.enqueue(inputs2[x]);
    	    	fileVec[inputs2[x]]++;
    	    }
    	    for(int x= 0; x < inputs3.size(); x++)
    	    {
    	    	queue3.enqueue(inputs2[x]);
    	    	fileVec[inputs3[x]]++;
    	    }

    		for (int x = 0; x<inputs.size(); x++)//queues inputs from vector
    		{
    			myQueue.enqueue(inputs[x]);
    			fileVec[inputs[x]]++;	//update file vector (adds a point to a requested floor)
    		}
    		writeToFile(1);
    		getFromFile();

    		moveThrough(myElevator[0], myQueue);//elevator begins moving through input queue.
    		myQueue.display();
    		moveThrough(myElevator[1], queue2, weight2);
    		queue2.display();
    		moveThrough(myElevator[2], queue3, weight3);
    		queue3.display();
    	}
    	if(a == 0)
    	{
    		break;
    	}
    }
}

void ControlHub::findMostReqFloor()
{
	bool restart = false;
	int counter, ele, num1, num2;
	counter = 0;
	
	for (int i = 1; i < fileVec.size(); i++)	//checks if there is data in the file
	{
		if (fileVec[i] < 1)
			counter++;
		if (counter == fileVec.size())
			restart = true;
	}
	
	if (restart)	//sets all priority to floor 1 if there is no data in the file
	{
		for (int i = 0; i < topFloors.size(); i++)
		{
			topFloors[i] = 1;
		}
	}
	else 
	{
		for (int i = 0; i < topFloors.size(); i++)
		{
			topFloors[i] = fileVec.size();
		}
		for (int i = 1; i < fileVec.size(); i++)
		{
			ele = topFloors.back();
 			if (fileVec[i] >= fileVec[ele])
				topFloors.back() = i;
				
			for (int j = topFloors.size() - 1; j >= 1 ; j--)
			{
				if (fileVec[topFloors[j]] > fileVec[topFloors[j-1]])
					swapVal(j, j-1);
			}
		}
	}
}

void ControlHub::addMostReqFloor(int num)
{

	//move floors down the array, then replace top spot


}

bool ControlHub::getStatus(int b) {

	return locked[b];
}

void ControlHub::printDisplay()
{
	//display elevator status
	/*	PLEASE EXPLAIN WHAT YOU'RE TRYING TO DO HERE
	if(myFloorArr.numFloors() == false) 
	{
		cout << "Elevator status: Online" << endl << endl;
	}
	else 
	{
		cout << "Elevator status: Offline" << endl << endl;
	} 
	*/
	//display priority floors
//	cout << "Floors " << topFloors[0] << ", " << topFloors[1] << ", & " << topFloors[2] << " have priority." << endl; 
}

void ControlHub::moveThrough(Elevator ele, PriorityQueue& queue)
{
	node *temp = new node;
	node *tempNext = new node;
	temp = queue.getHead();
	tempNext = temp;

	int weight = 0;
	int i = 0;

	while (temp != NULL)
	{
		cout << "Elevator " << ele.getName() << " arrived at Floor " << temp->data << endl;
		ele.openDoors();

		if(i == 0) //assumes this is an empty elevator.
		{
			cout << "Passenger(s) boarded: " << ele.getName() << endl;
			cout << "Please enter passenger(s)'s weight." << endl;
			cin >> weight;
			weight = ele.getCurrWeight() + weight;
			ele.addCurrWeight(weight);
			ele.updateStatus();
		}

		ele.closeDoors();
		temp = temp->next;

		if(temp == NULL)
		{
			break;
		}
		else if(tempNext->data < temp->data) //checks if elevator is going up
		{
			ele.goUp(temp->data);
			myFloorArr[temp->data].addReq();
		}
		else if(tempNext->data > temp->data)//checks if elevator is going down.
		{
			ele.goDown(temp->data);
			myFloorArr[temp->data].addReq();
		}
		tempNext = tempNext->next;
		queue.dequeue();
		i++;
	}
	queue.dequeue();
}

void ControlHub::moveThrough(Elevator ele, PriorityQueue& queue, vector<int> vec)
{
	node *temp = new node;
	node *tempNext = new node;
	temp = queue.getHead();
	tempNext = temp;

	int weight = 0;
	int i = 0;

	while (temp != NULL)
	{
		cout << "Elevator " << ele.getName() << " arrived at Floor " << temp->data << endl;
		ele.openDoors();

		if(i == 0) //assumes this is an empty elevator.
		{
			cout << "Passenger(s) boarded: " << ele.getName() << endl;
			cout << "Please enter passenger(s)'s weight." << endl;
			weight = vec[i];
			weight = ele.getCurrWeight() + weight;
			cout << weight << endl;
			ele.addCurrWeight(weight);
			ele.updateStatus();
			ele.closeDoors(0);
		}
		else
		{
			ele.closeDoors(vec[i]);
		}
		temp = temp->next;

		if(temp == NULL)
		{
			break;
		}
		else if(tempNext->data < temp->data) //checks if elevator is going up
		{
			ele.goUp(temp->data);
			myFloorArr[temp->data].addReq();
		}
		else if(tempNext->data > temp->data)//checks if elevator is going down.
		{
			ele.goDown(temp->data);
			myFloorArr[temp->data].addReq();
		}
		tempNext = tempNext->next;
		queue.dequeue();
		i++;
	}
	queue.dequeue();
}

void ControlHub::sortVec(vector<int>& vec)
{
	int temp;
	for (int i = 1; i < vec.size(); i++)
	{
		for(int j = 0; j < (vec.size() - i); j++)
		{
			if(vec[j] > vec[j+1])
			{
				temp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = temp;
			}
		}
	}
}

void ControlHub::getFromFile()	//gets information from data file and inserts them into a vector
{
	ifstream fin;
	fin.open("data.dat");
	if (fin.fail())
	{
		cout << "\nError 404: File not found. . . Creating a new File\n\n";
		writeToFile(0);
		fin.open("data.dat");
		if (fin.fail())
		{
			cout << "Error: File failed to open\n";
			exit(1);
		}
	}
	
	int next, i =0;
	
	fin >> next;
	
	if (next != numFloors)
	{
		cout << "\nError 405: The number of floors has changed . . . Creating a new File\n\n";
		fin.close();
		writeToFile(0);
		fin.open("data.dat");
		if (fin.fail())
		{
			cout << "Error: File failed to open\n";
			exit(1);
		}
		fin >> next;
	}
	while (!fin.eof())
	{
		fileVec[i] = next;
		i++;
		fin >> next;
	}
	fin.close();
}

void ControlHub::writeToFile(int num)	//writes vector to the file
{
	ofstream fout;
	fout.open("data.dat");
	if (fout.fail())
	{
		cout << "Error: File failed to open\n";
		exit(1);
	}
	
	if (num == 0)
	{
		fout << numFloors << endl;
		for (int i = 0; i < numFloors; i++)
		{
			fout << 0 << endl;
		}
	}
	else if (num == 1)
	{
		for (int i = 0; i < fileVec.size(); i++)
		{
			fout << fileVec[i] << endl;
		}
	}
	
	fout.close();
}

void ControlHub::swapVal(int f, int s)
{
	int temp;
	temp = topFloors[f];
	topFloors[f] = topFloors[s];
	topFloors[s] = temp;
}

void ControlHub::updateVectors(vector<int> &v1, vector<int> &v2, vector<int> &v3, vector<int> &v4)
{
	v1.push_back(1);
	v1.push_back(5);
	v1.push_back(9);
	v1.push_back(3);
	v1.push_back(2);
	
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);
	v2.push_back(3);
	
	v3.push_back(900);
	v3.push_back(430);
	v3.push_back(220);
	v3.push_back(120);
	v3.push_back(130);
	
	v4.push_back(870);
	v4.push_back(360);
	v4.push_back(175);
	v4.push_back(150);
	v4.push_back(185);
}
