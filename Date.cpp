#include<iostream>
#include"Date.h"

bool Date::isValid() {

    bool isLeap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    if (month < 1 || month > 12)
    {
        return false;
    }

    if (day < 1 || day > 31)
    {
        return false;
    }
    if (month == 2)
    {
        if (isLeap)
        {
            return (day <= 29);
        }
        else 
        {
            return (day <= 28);
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return (day <= 30);
    }

    return true;
}
void Date::showDate() {
    std::cout << day <<" "<< month<<" " << year;
}

void Date::setDate() {
    int d, m, y;
    std::cin >> d >> m >> y;
    day = d;
    month = m;
    year = y;
}

bool Date::operator==(const Date& other) {
    if (day == other.day && month == other.month && year == other.year) {
        return 1;
    }
    else {
        return 0;
    }
}
bool Date::operator>(const Date& other) {

    if (year > other.year) {
        return true;
    }
    else if (year == other.year) {

        if (month > other.month) {
            return true;
        }
        else if (month == other.month) {

            if (day > other.day) {
                return true;
            }
            else {
                return false;
            }

        }
        else {
            return false;
        }


    }
    else {
        return false;
    }

}
int Date::getDay() {
    return day;
}
int Date::getMonth() {
    return month;
}
int Date::getYear() {
    return year;
}
