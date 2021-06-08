#pragma once
#include<cstring>
#include<iostream>
#include"Date.h"
#include"Hall.h"
#include"Ticket.h"

class Event {

	char nameOfEvent[20];
	Date dateOfEvent;
	Hall hallOfEvent;
	size_t current;
	Ticket tiks[200];
	int soldTickets;

public:
	Event() { current = 0; soldTickets = 0; }

	Event(char* name, Date date, Hall hall) 
	{
		strcpy_s(nameOfEvent, name);
		dateOfEvent = date;
		hallOfEvent = hall;
		current = 0;
		soldTickets = 0;
	}

	void setEvent(Date, Hall, char*);
	Date getDate();
	char* getEventName();
	size_t getHallNumber();
	void freeSeats();
	Hall getHall();
	int getSoldTickets();
	void booke(int, int);
	void unbooke(int, int);
	void buyTicket(int, int);
	void retrunTiks();
};
