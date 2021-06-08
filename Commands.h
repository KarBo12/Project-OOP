#pragma once
#include<iostream>
#include<cstring>
#include"Event.h"
#include"Ticket.h"
#include"Hall.h"
#include"Date.h"
#include<fstream>

class Run {

	Event events[30];
	Hall halls[5];
	int numOfEvents;
	std::ifstream myFile;

public:

	Run() {}
	Run(Event* x, Hall* y) {

		for (int i=0; i < 30; i++) {

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
	void report(Date, Date, int);
	void Save(const char*);
	void open(const char*);
	void close(const char*);

};
