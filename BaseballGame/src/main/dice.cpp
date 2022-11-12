#include "dice.h"


int roll1() {
	int x{ (std::rand() % 6) + 1 };
	return x;
}

int roll2() {
	int x{ (std::rand() % 6) + 1 };
	int y{ (std::rand() % 6) + 1 };
	return x + y;
}

void rollPrinter(int roll) {
	std::cout << "You rolled a " << roll << '\n';
}