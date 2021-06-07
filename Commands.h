#pragma once
#include<iostream>
#include<cstring>
#include"Event.h"
#include"Ticket.h"
#include"Hall.h"
#include"Date.h"

class Run {

	Event events[20];
	Hall halls[5];
	int numOfEvents;

public:

	Run() {}
	Run(Event* x, Hall* y) {

		for (int i=0; i < 20; i++) {

			events[i] = x[i];
		}
		for (int p=0; p < 5; p++) {

			halls[p] = y[p];
		}

		numOfEvents = 0;

	};
	void run();
	void addEvent(Date, char*, int);
	void freeseats(Date, char*);
    void book(Date, char*, int, int);
	void unbook(Date, char*, int, int);
	void buy(Date, char*, int, int);
	void bookings(Date, char*);



};
