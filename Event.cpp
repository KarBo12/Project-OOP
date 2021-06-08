#include"Event.h"

void Event::setEvent(Date d, Hall h, char* n) {

    strcpy_s(nameOfEvent, n);
	dateOfEvent = d;
	hallOfEvent = h;

}
Date Event::getDate() {

	return dateOfEvent;
}
char* Event::getEventName() {

	return nameOfEvent;
}
size_t Event::getHallNumber() {

  return hallOfEvent.getNum();
}
int Event::getSoldTickets() {
	for (int i = 0; i < current; i++) {
		if (tiks[i].checkBought()) {
			soldTickets++;
		}
	}
	return soldTickets;
}
void Event::freeSeats() {
	std::cout << "Available seats for Event " << nameOfEvent << " on ";
	dateOfEvent.showDate();
	std::cout << " in hall ";
	std::cout<<hallOfEvent.getNum();
	std::cout << ":" << '\n';
	hallOfEvent.checkFree();
}
Hall Event::getHall() {
	return hallOfEvent;
}
void Event::booke(int x, int y) {

	hallOfEvent.reserveSeat(x, y);
	tiks[current].reserveTicket(x, y);
	current++;

}
void Event::unbooke(int x, int y) {
	hallOfEvent.unbookh(x, y);
}
void Event::retrunTiks() {
	int i = 0;
	while (i < current) {
		if (tiks[i].checkBought() == false) {
			tiks[i].showInfo();
			
		}
		i++;
	}
}
void Event::buyTicket(int x, int y) {

	int o = 0;
	bool flag = false;
	while (o < current) {
		if (tiks[o].getLine() == x && tiks[o].getRow() == y && tiks[o].checkBought()==false) {
			tiks[o].bookedToBought();
			flag = true;

		}
		else if (tiks[o].getLine() == x && tiks[o].getRow() == y && tiks[o].checkBought() == true) {
			std::cout << "Already bought";
			flag = true;
		}
		o++;
	}

	if (!flag) {
		hallOfEvent.reserveSeat(x, y);
		tiks[current].reserveTicket(x, y);
		tiks[current].bookedToBought();
		current++;
	}

}
