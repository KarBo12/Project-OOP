#include<iostream>
#include<cstring>
#include "Hall.h"
#include "Date.h"
#include "Event.h"
#include "Ticket.h"
#include "Commands.h"


int main() {

	Hall halls[5];
	Event events[30];

	halls[0].setHall(1, 10, 10);
	halls[1].setHall(2, 11, 11);
	halls[2].setHall(3, 12, 12);
	halls[3].setHall(4, 13, 13);
	halls[4].setHall(5, 14, 14);

	Run theatre(events, halls);
	theatre.run();

	return 0;
}
