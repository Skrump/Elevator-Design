#include "Floor.h"

floor::floor() {

	pending = false;
	number = 0;
}

bool floor::request() { //should also signal to create a node

	pending = true;

	return pending;
}

bool floor::reached() { //should also signal to remove from the queue

	pending = false;

	return 1;
}

int floor::get_floor() { //this should help create nodes

	return number;
}

int floor::get_status() { //this is to help the queue, if necessary

	return pending;
}
