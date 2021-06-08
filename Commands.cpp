#include"Commands.h"
void Run::run() {

	std::cout << "File is closed. Type Open to open it. Type Exit to exit"<<'\n';

	char action[20];

	std::cin >> action;

	while (strcmp(action, "Exit")) {

		if (!myFile.is_open()) {

			while (!myFile.is_open()) {

				if (!strcmp(action, "Open")) {
					open("TicketSystem.txt");
				}
				else {
					std::cout << "File is closed. Type Open to open it. Type Exit to exit" << '\n';
					std::cin >> action;
				}
			}
		}
		else if (myFile.is_open())
		{
			if (!strcmp(action, "Close")) {
				close("TicketSystem.txt");
			}

			else if (!strcmp(action, "Save")) {
				Save("TicketSystem.txt");
			}

			else if (!strcmp(action, "AddEvent")) {

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
			else if (!strcmp(action, "Freeseats"))
			{
				char evn[20];
				Date evd;
				std::cout << "Enter Event Name: ";
				std::cin >> evn;
				std::cout << "Enter Event Date: ";
				evd.setDate();
				freeseats(evd, evn);

			}

			else if (!strcmp(action, "Book")) {

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
			else if (!strcmp(action, "Unbook")) {

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
			else if (!strcmp(action, "Buy")) {

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


			else if (!strcmp(action, "Bookings")) {

				char bookingsName[20];
				Date bookingsDate;

				std::cout << "Enter Event Name: ";
				std::cin >> bookingsName;
				std::cout << "Enter Event Date: ";
				bookingsDate.setDate();
				bookings(bookingsDate, bookingsName);

			}
			else if (!strcmp(action, "Report")) {

				Date fromDate;
				Date toDate;
				int num;

				std::cout << "From date: ";
				fromDate.setDate();
				std::cout << "To date: ";
				toDate.setDate();
				std::cout << "Enter hall: ";
				std::cin >> num;
				report(fromDate, toDate, num);

			}
		}

		else {
			std::cout << "Please enter a valid command!" << '\n';
		}

		if (myFile.is_open()) {
			std::cout << "Select action : AddEvent/Freeseats/Book/Unbook/Buy/Bookings/Report/Save/Close/Stop" << '\n';
		}
		else {
			std::cout << "File is closed. Type Open to open it. Type Exit to exit";
		}
		std::cin >> action;
	}

}

void Run::addEvent(Date d, char* n, int num) {
	if (d.isValid()) {
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
				std::cout << "There is already an event set on this date"<<'\n';
				flag = false;
			}

		}
		if (flag)
		{
			events[numOfEvents].setEvent(d, halls[whichHall], n);
			numOfEvents++;
		}
	}
	else {
		std::cout << "Invalid date"<<'\n';
	}
}
void Run::freeseats(Date evd, char* evn) {
	if (evd.isValid()) {

		bool flag = true;
		for (int i = 0; i < numOfEvents; i++) {
			if (!strcmp(evn, events[i].getEventName()) && evd == events[i].getDate()) {
				events[i].freeSeats();
				flag = false;
			}
		}
		if (flag) {
			std::cout << "The event does not exist"<<'\n';
		}
	}
	else {
		std::cout << "Invalid date"<<'\n';
	}

}
void Run::book(Date bd, char* bn, int br, int bl) {
	if(bd.isValid()){
	bool flag = true;

	for (int i = 0; i < numOfEvents; i++) {
		if (!strcmp(bn, events[i].getEventName()) && bd == events[i].getDate()) {
			events[i].booke(bl, br);
			flag = false;
		}
	}
	if (flag) {
		std::cout << "The event does not exist";
	}
}
	else {
		std::cout << "Invalid date"<<'\n';
	}
}

void Run::unbook(Date ubd, char* ubn, int ubl, int ubr) {
	if (ubd.isValid()) {
		bool flag = true;

		for (int i = 0; i < numOfEvents; i++) {
			if (!strcmp(ubn, events[i].getEventName()) && ubd == events[i].getDate()) {
				events[i].unbooke(ubl, ubr);
				flag = false;
			}
		}
		if (flag) {
			std::cout << "The event does not exist"<<'\n';
		}
	}
	else {
		std::cout << "Invalid date"<<'\n';
	}
}

void Run::buy(Date bd, char* bn, int bl, int br) {

	if (bd.isValid()) {
		bool flag = true;

		for (int i = 0; i < numOfEvents; i++) {
			if (!strcmp(bn, events[i].getEventName()) && bd == events[i].getDate()) {
				events[i].buyTicket(bl, br);
				flag = false;
			}
		}
		if (flag) {
			std::cout << "The event does not exist"<<'\n';
		}
	}
	else {
		std::cout << "Invalid date" << '\n';
	}
}


void Run::bookings(Date bod, char* bon) {

	if (bod.isValid()) {

		bool flag = true;

		for (int i = 0; i < numOfEvents; i++) {
			if (!strcmp(bon, events[i].getEventName()) && bod == events[i].getDate()) {
				events[i].retrunTiks();
				flag = false;
			}
		}
		if (flag) {
			std::cout << "The event does not exist"<<'\n';
		}
	}
	else {
		std::cout << "Invalid date!"<<'n';
	}
}


void Run::report(Date f, Date s, int dhn) {

	int whichHall = 0;

	if (f.isValid() && s.isValid() && s > f) {

		while (whichHall < 5) {
			if (dhn == halls[whichHall].getNum()) {
				break;
			}
			whichHall++;
		}

		bool flag = true;

		for (int i = 0; i < numOfEvents; i++) {

			if (events[i].getDate() > f && s > events[i].getDate() && events[i].getHallNumber() == dhn) {

				std::cout << "Tickets Sold for: " << events[i].getEventName() << " on ";
				events[i].getDate().showDate();
				std::cout << events[i].getSoldTickets() << '\n';
				flag = false;
			}

		}
		if (flag) {
			std::cout << "No shows have been presented during the selected time period"<<'\n';
		}
	}
	else {
		std::cout << "Invalid date"<<'\n';
	}
}
void Run::Save(const char* fileName) {

	std::ofstream output(fileName, std::fstream::app);

	if (output.is_open())
	{
		for (int i = 0; i < numOfEvents; i++)
		{
			output << events[i].getDate().getDay()<<" "<<events[i].getDate().getMonth()<<" "<<events[i].getDate().getYear()<<" "<<events[i].getEventName() <<" "<<events[i].getHallNumber()<<'\n';
		}
		output.close();
	}
	else
	{
		std::cout << "File " << fileName << " not opened" << std::endl;
	}
}

void Run::open(const char* fileName) {

	myFile.open(fileName);
	if (myFile.is_open()) {
		std::cout << "succesfully opened"<<'\n';
	}

}

void Run::close(const char* fileName) {


	if (myFile.is_open()) {
		myFile.close();
		std::cout << "succesfully closed" << '\n';
	}

}

