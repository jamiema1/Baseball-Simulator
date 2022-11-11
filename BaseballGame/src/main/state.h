#ifndef STATE_H
#define STATE_H
#include <string>
#include "batter.h"
#include "pitcher.h"

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

void resetSpeed();
void pause();
void stop();
void gameSpeed();
bool isLessThanMaxSpeed();
bool displayText();

void switchTeams();
void game();
//void fiveGameSeries(int team1, int team2);

void start();
void boxScore();

void lineups();
void batterLineup();
void pitcherLineup();

Batter currentBatter();
Pitcher currentPitcher();
void nextBatter();
void nextPitcher();
//void nextBatter2(Team team);

void pitchPrinter(Batter batter, Pitcher pitcher, int stat);
void pitchResultPrinter(int pitchValue);
int pitchResult(Batter batter, Pitcher pitcher, int stat);
int isContact(int value);
Batter hitPositionSelector(int position);
void hitPositionPrinter(int position);


void hitResultPrinter(int hit);
int hitResult(int hitPosition, Batter batter, int stat);
int isHit(Batter batter, int value);
void hitCounter();

void isScored();

/*
int nameLength(int position);
int lengthAdjustor(int length);
int stringLength(std::string string);
std::string fielder1(int length1, int length2, int position);

void fieldPrinter();
*/

void basesPrinter();
void scorePrinter();
void inningPrinter();
void outsPrinter();

void winsPrinter();

void inningOverPrinter();
bool isInningOver();

void resetGame();
bool isGameOver();

#endif