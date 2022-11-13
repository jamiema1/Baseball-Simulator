#include "player.h"
#pragma once

class Batter : public Player {

private:
	//double stats[14];
	//std::string statsString[14];

public:

	//enum class BatterStat;

	// constructor
	Batter(std::string firstName, std::string lastName, std::string position, std::string bats, std::string throws,
		int games, int atbats, int runs, int hits, int doubles, int triples, int homeruns, int rbis, int stolenbases,
		int walks, double slugging, double ops, double average, double war);



	// returns the value of a stat for a given batter
	//double statSelector(int stat) override;

	// prints the stat for the specific batter
	//void statSelectorPrinter(int stat) override;

	//bool operator==(Batter obj);
	//bool operator!=(Batter obj);

	/*
	void selectorScreen();
	int statSelectorScreen(int stat);
	int selectorInput();
	std::string nameSelector(int name, Batter batter)
	int statSelectorInput(Batter batter);
	*/
};