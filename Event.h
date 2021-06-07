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
	Ticket tiks[20];

public:
	Event() { current = 0; }

	Event(char* name, Date date, Hall hall) 
	{
		strcpy_s(nameOfEvent, name);
		dateOfEvent = date;
		hallOfEvent = hall;
		current = 0;
	}

	void showAll();
	void setEvent(Date, Hall, char*);
	Date getDate();
	char* getEventName();
	size_t getHallNumber();
	void freeSeats();
	Hall getHall();
	void book(int, int);
	void unbook(int, int);
	void retrunTiks();
	void buyTicket(int, int);
};
