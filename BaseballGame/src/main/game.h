#pragma once
#include <array>
#include <string>
#include "batter.h"
#include "pitcher.h"
#include "team.h"
#include "timeDelay.h"
#include "dice.h"

struct Division {
	std::string divisionName{};
	Team* teams[5];
};

struct League {
	std::string leagueName{};
	Division divisions[3]{};
};

struct Organization {
	std::string organizationName{};
	League leagues[2]{};
};


class Game {
private:
	Team* awayTeam;
	Team* homeTeam;

	int outs;
	int inning;
	int half;

	/* 0 means at home
	 * 1 means 1st base
	 * 2 means 2nd base
	 * 3 means 3rd base
	 */
	Batter* bases[4];

	static const int teamSize = 9;
	Batter* field[teamSize];
	Batter* batter[teamSize];

	std::array<std::array<int, 20>, 2> score;
	

public:

	// default constructor
	Game();

private:

	// returns the current batter and sets them to being at bat
	Batter* getCurrentBatter();

	// returns the current pitcher
	Pitcher* getCurrentPitcher();




	/* returns the result of the pitch
	 * 1  -> contact
	 * 0  -> out
	 * -1 -> nothing
	 */
	int pitchResult(int stat);

	// prints out the stats of the pitch
	void pitchPrinter(int stat);

	// prints out the result of the pitch
	void pitchResultPrinter(int pitchValue);

	// updates the outs and sets bases[0] to NULL
	void isOut();






	// returns the fielder at the given position
	Batter* hitPositionSelector(int position);

	// prints out the name of the player the ball is hit to
	// 2 = C, ... , 9 = RF, 10 = double, etc
	void hitPositionPrinter(int position);


	// determines the result of making contact and returns the hit value
	int hitResult(int hitPosition, int stat);

	// prints out the result of the contact
	void hitResultPrinter(int hitValue);

	



	// updates the game state when a hit occurs and changes the runners, outs, inning, score
	int isHit(int hitValue);

	// adds 1 to the hits for the hitting team
	void hitCounter();

	// scores a run for the hitting team
	void isScored();





	// updates the current batter / pitcher
	void nextBatter();
	void nextPitcher();


/*
 *	Game state printers
 */

	// prints the runners on base
	void basesPrinter();
	
	// prints out the current inning including top or bottom
	void inningPrinter();

	// prints out the current outs
	void outsPrinter();

	// prints out the box score
	void boxScorePrinter();

	// prints out how many wins each team has so far
	void winsPrinter();

	// prints out a message denoting the end of an inning
	void inningOverPrinter();





	// returns true if the inning is over
	bool isInningOver();

	// returns true if the game is over
	bool isGameOver();

	// swaps the away and home teams
	void swapTeams();


	// resets the game to the initial gamestate
	void resetGame();

	void start();
};









/*
int nameLength(int position);
int lengthAdjustor(int length);
int stringLength(std::string string);
std::string fielder1(int length1, int length2, int position);

void fieldPrinter();
*/

