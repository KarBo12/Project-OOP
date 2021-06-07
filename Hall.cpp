#include<iostream>
#include "Hall.h"

void Hall::setHall(size_t n, size_t l, size_t r) {

	num = n;
	lines = l;
	rows = r;
	for (int i = 0; i < lines; i++) {
		for (int k = 0; k < rows; k++) {
			seats[i][k] = true;
		}
	}
}

void Hall::reserveSeat(int x, int y) {
	x--;
	y--;

	if (!seats[x][y]) {
		std::cout << "Seat number " << y + 1 << " on line " << x + 1 << " is already taken" << std::endl;
	}

	else {

		seats[x][y] = false;
	}
}

void Hall::checkFree() {

	for (int i = 0; i < lines; i++) {

		std::cout << "Availabe seats on line " << i + 1 << ": ";

		for (int k = 0; k < rows; k++) {

			if (seats[i][k]) {
				std::cout << k + 1 << " ";
			}
		}

		std::cout << '\n';
	}
}
void Hall::unbook(int x, int y) {

	x--;
	y--;

	if (!seats[x][y]) {
		seats[x][y] = true;
	}
	else {
		std::cout << "This seat is not reseved" << std::endl;
	}

}

void Hall::showNumber() {

	std::cout << num;
}
size_t Hall::getNum() {
	return num;
}
