/*
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
*/

#include "player.h"
#pragma once

class Pitcher : public Player {

private:
	std::string firstName{};
	std::string lastName{};
	std::string position{};
	std::string bats{};
	std::string throws{};
	double stats[13];

public:
	enum class PitcherStat;

	// constructor
	Pitcher(std::string firstName, std::string lastName, std::string position, std::string bats, std::string throws,
		int games, int wins, int loses, double inningspitched, int hits, int runs, int earnedruns, int walks,
		int strikeouts, int saves, double whip, double era, double war);

	
	// returns the value of a stat for a given batter
	double statSelector(int stat);

	// prints the stat for the specific batter
	void statSelectorPrinter(int stat);

	// returns the value of a stat for a given batter
	std::string stringStatSelector(int stat);

	// returns a batters full name with a space inbetween
	std::string fullName();
};