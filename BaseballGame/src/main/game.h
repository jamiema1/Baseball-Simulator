#ifndef STATE_H
#define STATE_H
#include <string>
#include "batter.h"
#include "pitcher.h"
#include "team.h"
#include "timeDelay.h"

/*
struct Team {
	std::string teamName{};
	std::string teamInitials{};
	Batter batters[20];
	Batter battingLineup[9];
	Batter fieldingLineup[8];
	Batter currentBatter;
	Pitcher pitchers[20];
	Pitcher currentPitcher;
	int score[20]{};
	int wins{};
};
*/
/*
struct Division {
	std::string divisionName{};
	Team teams[5];
};

struct League {
	std::string leagueName{};
	Division divisions[3]{};
};

struct Organization {
	std::string organizationName{};
	League leagues[2]{};
};
*/

class Game {
private:
	Team* awayTeam;
	Team* homeTeam;

	int outs;
	int score;
	int inning;
	int half;

	/* 0 means at home
	 * 1 means 1st base
	 * 2 means 2nd base
	 * 3 means 3rd base
	 */
	Batter* bases[4];

	int teamSize = 9;
	Batter* field[9];
	Batter* batter[9];

	int score[2][20];
public:


	// returns the current batter and sets them to being at bat
	Batter* getCurrentBatter();

	// returns the current pitcher
	Pitcher* getCurrentPitcher();

	// updates the current batter / pitcher
	void nextBatter();
	void nextPitcher();



	int pitchResult(int stat);
	void pitchPrinter(int stat);
	void pitchResultPrinter(int pitchValue);
	void isOut();



	// returns the fielder at the given position
	Batter* hitPositionSelector(int position);

	// prints out the name of the player the ball is hit to
	void hitPositionPrinter(int position);


	// determines the result of making contact and returns the hit value
	int hitResult(int hitPosition, int stat);

	// prints out the result of the contact
	void hitResultPrinter(int hit);

	



	/* updates the game state when a hit occurs
	 * changes the runners, outs, inning, score
	 */
	int isHit(int value);

	// adds 1 to the hits for the hitting team
	void hitCounter();

	// scores a run for the hitting team
	void isScored();

	// prints out the box score
	void boxScore();


	void basesPrinter();
	void inningPrinter();
	void outsPrinter();

	void winsPrinter();

	void inningOverPrinter();
	bool isInningOver();

	// swaps the away and home teams
	void swapTeams();
	void resetGame();
	bool isGameOver();










	void game();
	//void fiveGameSeries(int team1, int team2);

	void start();
};









/*
int nameLength(int position);
int lengthAdjustor(int length);
int stringLength(std::string string);
std::string fielder1(int length1, int length2, int position);

void fieldPrinter();
*/



#endif