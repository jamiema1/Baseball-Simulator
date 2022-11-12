#include "player.h"
#pragma once

class Pitcher : public Player {

private:
	//double stats[13];
	//std::string statsString[13];

public:
	//enum class PitcherStat;

	// constructor
	Pitcher(std::string firstName, std::string lastName, std::string position, std::string bats, std::string throws,
		int games, int wins, int loses, double inningspitched, int hits, int runs, int earnedruns, int walks,
		int strikeouts, int saves, double whip, double era, double war);

	
	// returns the value of a stat for a given batter
	//double statSelector(int stat);

	// prints the stat for the specific batter
	//void statSelectorPrinter(int stat);

};