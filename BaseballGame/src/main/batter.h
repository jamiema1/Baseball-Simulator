/*
#ifndef BATTER_H
#define BATTER_H
#include <string>


struct Batter {
	std::string firstName{};
	std::string lastName{};
	std::string position{};
	std::string bats{};
	std::string throws{};
	int games{};
	int atbats{};
	int runs{};
	int hits{};
	int doubles{};
	int triples{};
	int homeruns{};
	int rbis{};
	int stolenbases{};
	int walks{};
	double slugging{};
	double ops{};
	double average{};
	double war{};
};


void batterSelectorScreen();
int batterStatSelectorScreen(int stat);
int batterSelectorInput();
int batterStatSelectorInput(int batter);
std::string batterFullName(int batter);
std::string batterStringStatSelector(int stat, int batter);
double batterStatSelector(int stat, int batter);
void batterStatSelectorPrinter(int stat, int batter);
#endif
*/

#include "player.h"
#pragma once

class Batter : public Player {

private:
	std::string firstName{};
	std::string lastName{};
	std::string position{};
	std::string bats{};
	std::string throws{};
	double stats[14];
	/*
	int games{};
	int atbats{};
	int runs{};
	int hits{};
	int doubles{};
	int triples{};
	int homeruns{};
	int rbis{};
	int stolenbases{};
	int walks{};
	double slugging{};
	double ops{};
	double average{};
	double war{};
	*/

public:

	enum class BatterStat;

	// constructor
	Batter(std::string firstName, std::string lastName, std::string position, std::string bats, std::string throws,
		int games, int atbats, int runs, int hits, int doubles, int triples, int homeruns, int rbis, int stolenbases,
		int walks, double slugging, double ops, double average, double war);


	// returns the value of a stat for a given batter
	double statSelector(int stat);

	// prints the stat for the specific batter
	void statSelectorPrinter(int stat);

	// returns the value of a stat for a given batter
	std::string stringStatSelector(int stat);

	// returns a batters full name with a space inbetween
	std::string fullName();

	bool operator==(Batter obj);

	bool operator!=(Batter obj);

	/*
	void selectorScreen();
	int statSelectorScreen(int stat);
	int selectorInput();
	std::string nameSelector(int name, Batter batter)
	int statSelectorInput(Batter batter);
	*/
};