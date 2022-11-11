#include "dice.h"
#include <iostream>


// rolls a six sided die and returns the result
int roll1() {
	int x{ (std::rand() % 6) + 1 };
	return x;
}

// rolls two six sided die and returns their sum
int roll2() {
	int x{ (std::rand() % 6) + 1 };
	int y{ (std::rand() % 6) + 1 };
	return x + y;
}

// prints out the result of a dice roll
void rollPrinter(int roll) {
	std::cout << "You rolled a " << roll << '\n';
}