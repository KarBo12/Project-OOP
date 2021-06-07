#include"Commands.h"


void Run::run() {

		std::cout << "Select action : AddEvent/FreeSeats/Book/Unbook/Buy/Bookings/Stop";

		char action[20];

		std::cin >> action;

		while (strcmp(action, "Stop")) {

			if (!strcmp(action, "AddEvent")) {

				Date d;
				char n[20];
				int num;
				std::cout << "Select Event Date: ";
				d.setDate();
				std::cout << "Select Event Name: ";
				std::cin >> n;
				std::cout << "Select Event Hall: ";
				std::cin >> num;

				addEvent(d, n, num);

			}
			if (!strcmp(action, "Freeseats")) 
			{
				char evn[20];
				Date evd;
				std::cout << "Enter Event Name: ";
				std::cin >> evn;
				std::cout << "Enter Event Date: ";
				evd.setDate();

				freeseats(evd, evn);

			}

			if (!strcmp(action, "Book")) {

				char bookName[20];
				Date bookDate;
				int bookLine;
				int bookRow;
				std::cout << "Enter Event Name: ";
				std::cin >> bookName;
				std::cout << "Enter Event Date: ";
				bookDate.setDate();
				std::cout << "Enter line and row: ";
				std::cin >> bookLine;
				std::cin >> bookRow;
				book(bookDate, bookName, bookLine, bookRow);
			}
			if (!strcmp(action, "Unbook")) {

				char unbookName[20];
				Date unbookDate;
				int unbookLine;
				int unbookRow;
				std::cout << "Enter Event Name: ";
				std::cin >> unbookName;
				std::cout << "Enter Event Date: ";
				unbookDate.setDate();
				std::cout << "Enter line and row: ";
				std::cin >> unbookLine;
				std::cin >> unbookRow;
				unbook(unbookDate, unbookName, unbookLine, unbookRow);
			}
			if (!strcmp(action, "Buy")) {

				char buyName[20];
				Date buyDate;
				int buyLine;
				int buyRow;
				std::cout << "Enter Event Name: ";
				std::cin >> buyName;
				std::cout << "Enter Event Date: ";
				buyDate.setDate();
				std::cout << "Enter line and row: ";
				std::cin >> buyLine;
				std::cin >> buyRow;
				buy(buyDate, buyName, buyLine, buyRow);
			}


			if (!strcmp(action, "Bookings")) {

				char bookingsName[20];
				Date bookingsDate;
				
				std::cout << "Enter Event Name: ";
				std::cin >> bookingsName;
				std::cout << "Enter Event Date: ";
				bookingsDate.setDate();
				bookings(bookingsDate, bookingsName);

			}

			std::cout << "Select action : AddEvent/Freeseats/Book/Unbook/Buy/Bookings/Stop"<<'\n';
			std::cin >> action;
		}
}

void Run::addEvent(Date d, char* n, int num) {
	int whichHall = 0;

	while (whichHall < 5) {
		if (num == halls[whichHall].getNum()) {
			break;
		}
		whichHall++;
	}

	bool flag = true;

	for (int i = numOfEvents - 1; i >= 0; i--) {

		if (events[i].getDate() == d && events[i].getHallNumber() == num) {
			std::cout << "There is already an event set on this date";
			flag = false;
		}

	}
	if (flag)
	{
		events[numOfEvents].setEvent(d, halls[whichHall], n);
		numOfEvents++;
	}
}
void Run::freeseats(Date evd, char* evn) {

	bool flag = true;
	for (int i = 0; i < numOfEvents; i++) {
		if (!strcmp(evn, events[i].getEventName()) && evd == events[i].getDate()) {
			events[i].freeSeats();
			flag = false;
		}
	}
	if (flag) {
		std::cout << "The event does not exist";
	}

}
void Run::book(Date bd, char* bn, int br, int bl) {
	bool flag = true;

	for (int i = 0; i < numOfEvents; i++) {
		if (!strcmp(bn, events[i].getEventName()) && bd == events[i].getDate()) {
			events[i].book(bl, br);
			flag = false;
		}
	}
	if (flag) {
		std::cout << "The event does not exist";
	}
}

void Run::unbook(Date ubd, char* ubn, int ubl, int ubr) {
    bool flag = true;

    for (int i = 0; i < numOfEvents; i++){
	    if (!strcmp(ubn, events[i].getEventName()) && ubd == events[i].getDate()) {
		    events[i].unbook(ubl, ubr);
		    flag = false;
	    }
    }
    if (flag) {
	    std::cout << "The event does not exist";
    }
}

void Run::buy(Date bd, char* bn, int bl, int br) {
	bool flag = true;

	for (int i = 0; i < numOfEvents; i++) {
		if (!strcmp(bn, events[i].getEventName()) && bd == events[i].getDate()) {
			events[i].buyTicket(bl, br);
			flag = false;
		}
	}
	if (flag) {
		std::cout << "The event does not exist";
	}
}

void Run::bookings(Date bod, char* bon) {
	bool flag = true;

	for (int i = 0; i < numOfEvents; i++) {
		if (!strcmp(bon, events[i].getEventName()) && bod == events[i].getDate()) {
			events[i].retrunTiks();
			flag = false;
		}
	}
	if (flag) {
		std::cout << "The event does not exist";
	}
}