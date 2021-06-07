#include<iostream>
#include<cstring>
#include "Hall.h"
#include "Date.h"
#include "Event.h"
#include "Ticket.h"
#include "Commands.h"


int main() {

	Hall halls[5];
	Event events[20];

	std::cout << "Hi";

	halls[0].setHall(1, 10, 10);
	halls[1].setHall(2, 10, 10);
	halls[2].setHall(25, 10, 10);
	halls[3].setHall(56, 10, 10);
	halls[4].setHall(4, 10, 10);

	Run runi(events, halls);
	runi.run();
	


	return 0;
}
