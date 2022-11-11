#ifndef PITCHER_H
#define PITCHER_H
#include <string>

struct Pitcher {
	std::string firstName{};
	std::string lastName{};
	std::string position{};
	std::string bats{};
	std::string throws{};
	int games{};
	int wins{};
	int loses{};
	double inningspitched{};
	int hits{};
	int runs{};
	int earnedruns{};
	int walks{};
	int strikeouts{};
	int saves{};
	double whip{};
	double era{};
	double war{};
};


std::string pitcherFullName(int pitcher);
std::string pitcherStringStatSelector(int stat, int pitcher);
double pitcherStatSelector(int stat, int pitcher);
void pitcherStatSelectorPrinter(int stat, int pitcher);






#endif