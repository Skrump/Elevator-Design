#pragma once

class floor {

	bool pending;
	int number;

public:

	bool request();
	bool reached();
	int get_floor();
	int get_status();
};
