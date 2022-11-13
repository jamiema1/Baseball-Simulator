#include "batter.h"
#include "pitcher.h"
#include <vector>
#pragma once
class Team
{
private:
	std::string name;
	std::string initials;
	Batter* batters[20];
	Batter* battingLineup[9];
	Batter* fieldingLineup[9];
	Batter* currentBatter;
	Pitcher* pitchers[20];
	Pitcher* currentPitcher;
	int wins = 0;
	int loses = 0;

	struct integerLOP {
		int batters[20];
		int battingLineup[9];
		int fieldingLineup[9];
		int currentBatter;
		int pitchers[20];
		int currentPitcher;
	};

public:

	

	Team(std::string name, std::string initials, Batter* batters[20], Batter* battingLineup[9], Batter* fieldingLineup[9],
		Batter* currentBatter, Pitcher* pitchers[20], Pitcher* currentPitcher);

	Team(std::string name, std::string initials, integerLOP lop);



	// Getters
	std::string getName();
	std::string getInitials();
	Batter* getBatterInLineup(int index);
	Batter* getFielderInLineup(int index);
	Batter* getCurrentBatter();
	Pitcher* getCurrentPitcher();
	void setCurrentBatter(Batter* batter);
	int getWins();
	void setWins(int wins);


	// prints out the batting and pitching lineups
	void lineups(Team* homeTeam, Team* awayTeam);
	void pitcherLineupPrinter(int i);
	void batterLineupPrinter(int i);


	// updates the current batter
	void nextBatter();


	// prints out how many wins a team has so far
	void winsPrinter();
	

	Team* createTeam();
};

