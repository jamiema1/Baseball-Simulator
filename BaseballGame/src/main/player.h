#include <iostream>
#pragma once

class Player {
protected:
	std::string firstName{};
	std::string lastName{};
	std::string position{};
	std::string bats{};
	std::string throws{};
	double stats[14];
	std::string statsString[14];

public:
	//enum class PlayerStat;

	// constructor
	Player(std::string firstName, std::string lastName, std::string position, std::string bats, std::string throws);

	// returns the value of a stat for a given batter
	std::string stringStatSelector(int stat);

	// returns a batters full name with a space inbetween
	std::string fullName();

	// returns the value of a stat
	double statSelector(int stat);

	// prints the value of the stat
	void statSelectorPrinter(int stat);
};