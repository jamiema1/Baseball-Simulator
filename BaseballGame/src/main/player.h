#include <iostream>
#pragma once

class Player {
protected:
	std::string firstName{};
	std::string lastName{};
	std::string position{};
	std::string bats{};
	std::string throws{};

public:
	enum class PlayerStat;

	// default constructor
	Player() {};

	// constructor
	Player(std::string firstName, std::string lastName, std::string position, std::string bats, std::string throws);

	// returns the value of a stat for a given batter
	std::string stringStatSelector(int stat);

	// returns a batters full name with a space inbetween
	std::string fullName();

	// returns the value of a stat
	virtual double statSelector(int stat) =0;

	// prints the value of the stat
	virtual void statSelectorPrinter(int stat) =0;
};