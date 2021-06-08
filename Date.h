#pragma once
class Date {

	size_t day;
	size_t month;
	size_t year;

public:
	Date(){}

	Date(size_t x, size_t y, size_t z) {
		day = x;
		month = y;
		year = z;
	}
	void setDate();
	bool isValid();
	void showDate();
	int getDay();
	int getMonth();
	int getYear();
	bool operator==(const Date&);
	bool operator > (const Date&);
};
