#ifndef STATE_H
#define STATE_H
#include <string>

struct Team {
	std::string teamName{};
	std::string teamInitials{};
	int batters[20]{};
	int battingLineup[9]{};
	int fieldingLineup[9]{};
	int currentBatter{};
	int pitchers[20]{};
	int currentPitcher{};
	int score[20]{};
	int wins{};
};

struct Division {
	std::string divisionName{};
	Team teams[5]{};
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
void fiveGameSeries(int team1, int team2);

void start();
void boxScore();

void lineups();
void batterLineup();
void pitcherLineup();

int currentBatter();
int currentPitcher();
void nextBatter();
void nextPitcher();
void nextBatter2(Team team);

void pitchPrinter(int batter, int pitcher, int stat);
void pitchResultPrinter(int pitchValue);
int pitchResult(int batter, int pitcher, int stat);
int isContact(int value);
int hitPositionSelector(int position);
void hitPositionPrinter(int position);


void hitResultPrinter(int hit);
int hitResult(int hitPosition, int batter, int stat);
int isHit(int batter, int value);
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