#include "batter.h"
#include "pitcher.h"
#include "dice.h"
#include "state.h"
#include "timeDelay.h"

#include <iostream>
#include <conio.h>
#include <string>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

Team Orioles{
	"Balimore Orioles",
	"BAL",
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 },
	{ 10, 9, 3, 4, 12, 2, 11, 6, 14 },
	{ 4, 12, 9, 6, 2, 14, 3, 10, 11 },
	10, 
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
	6
};
Team RedSox{
	"Boston Red Sox",
	"BOS",
	{ 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
	{ 28, 22, 20, 17, 31, 26, 25, 19, 16 },
	{ 24, 30, 28, 16, 20, 17, 31, 22, 26},
	28,
	{ 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 },
	17
};
Team Yankees{
	"New York Yankees",
	"NYY",
	{ 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161 },
	{ 155, 151, 157, 147, 158, 152, 148, 159, 156 },
	{ 157, 156, 155, 152, 159, 158, 147, 148, 151 },
	155,
	{ 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 134, 136, 137 },
	125
};
Team Rays{
	"Tampa Bay Rays",
	"TBR",
	{ 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209 },
	{ 194, 199, 201, 197, 208, 198, 203, 209, 200 },
	{ 197, 198, 201, 208, 199, 194, 200, 203 },
	194,
	{ 162, 163, 164, 165, 167, 168, 169, 170, 171, 172, 173, 174 },
	168
};
Team BlueJays{
	"Toronto Blue Jays",
	"TOR",
	{ 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241 },
	{ 241, 240, 233, 227, 235, 234, 231, 236, 232 },
	{ 232, 236, 233, 240, 231, 227, 234, 241, 235 },
	241,
	{ 186, 187, 188, 189, 190, 191, 192, 193, 194, 195 },
	190
};
Team RedJays{
	"Milton Red Jays",
	"MIT",
	{ 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241 },
	{ 241, 240, 233, 227, 235, 234, 231, 236, 232 },
	{ 232, 236, 233, 240, 231, 227, 234, 241, 235 },
	241,
	{ 186, 187, 188, 189, 190, 191, 192, 193, 194, 195 },
	186
};

Team Guardians{
	"Cleveland Guardians",
	"CLE",
	{ 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66 },
	{ 65, 64, 60, 62, 66, 55, 50, 54, 52},
	{ 62, 54, 50, 52, 60, 64, 55, 65, 66 },
	65,
	{ 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55},
	52
};
Team Royals{
	"Kansas City Royals",
	"KCR",
	{ 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 },
	{ 103, 102, 107, 99, 108, 100, 98, 109, 105 },
	{ 105, 107, 108, 103, 98, 102, 99, 109, 100 },
	103,
	{ 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98 },
	93
};
Team Tigers{
	"Detroit Tigers",
	"DET",
	{ 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82 },
	{ 67, 74, 81, 68, 70, 75, 73, 69, 72 },
	{ 68, 75, 81, 72, 70, 73, 74, 67, 69 },
	67,
	{ 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68 },
	64
};
Team Twins{
	"Minesota Twins",
	"MIN",
	{ 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143 },
	{ 127, 129, 139, 131, 137, 142, 143, 133, 138 },
	{ 131, 133, 142, 139, 127, 143, 138, 129, 136 },
	127,
	{ 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123 },
	120
};
Team WhiteSox{
	"Chicago White Sox",
	"CHW",
	{ 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 49 },
	{ 33, 46, 32, 38, 41, 45, 36, 42, 40 },
	{ 42, 38, 32, 36, 45, 33, 41, 46, 40 },
	33,
	{ 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40 },
	38
};

Team Angels{
	"Los Angeles Angels",
	"LAA",
	{ 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126 },
	{ 115, 117, 113, 121, 116, 125, 114, 119, 112 },
	{ 117, 121, 125, 112, 116, 119, 113, 115, 114 },
	115,
	{ 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110 },
	107
};
Team Astros{
	"Houston Astros",
	"HOU",
	{ 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97 },
	{ 83, 85, 86, 84, 92, 88, 97, 96, 94},
	{ 84, 94, 92, 83, 86, 88, 85, 96, 97},
	83,
	{ 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83 },
	75
};
Team Athletics{
	"Oakland Athletics",
	"OAK",
	{ 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176 },
	{ 168, 171, 174, 163, 164, 165, 167, 173, 162 },
	{ 167, 173, 174, 168, 165, 162, 164, 171, 163 },
	168,
	{ 141, 142, 143, 144, 145, 146, 147, 148 },
	144
};
Team Mariners{
	"Seattle Mariners",
	"SEA",
	{ 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193 },
	{ 178, 180, 181, 189, 190, 191, 183, 187, 179},
	{ 191, 187, 180, 190, 189, 178, 179, 183, 181 },
	178,
	{ 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161 },
	153
};
Team Rangers{
	"Texas Rangers",
	"TEX",
	{ 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226 },
	{ 210, 219, 214, 220, 218, 222, 223, 225, 211 },
	{ 218, 225, 220, 223, 211, 219, 210, 214, 222 },
	210,
	{ 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185 },
	179
};
/*
Team Rangers{
	"r",
	{},
	{},
	{},
	0,
	{},
	0
};
*/

Team Diamondbacks{
	"Arizona Diamondbacks",
	"ARI",
	{ 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253 },
	{ 242, 243, 244, 245, 246, 248, 247, 249, 252},
	{ 252, 244, 249, 248, 243, 242, 246, 245, 247 },
	242,
	{ 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207 },
	201
};
Team Braves{
	"Atlanta Braves",
	"ATL",
	{ 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270 },
	{ 256, 265, 261, 254, 266, 269, 260, 268, 270},
	{ 254, 270, 261, 256, 265, 269, 266, 268, 260 },
	256,
	{ 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220 },
	214
};
Team Marlins{
	"Miami Marlins",
	"MIA",
	{ 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343 },
	{ 333, 335, 328, 330, 341, 334, 332, 331, 329 },
	{ 331, 329, 328, 333, 330, 341, 332, 335, 334 },
	333,
	{ 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272},
	262
};
Team Mets{
	"New York Mets",
	"NYM",
	{ 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378},
	{ 361, 369, 360, 365, 367, 373, 362, 366, 372},
	{ 365, 366, 360, 367, 373, 361, 372, 369, 362 },
	361,
	{ 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296 },
	295
};
Team Phillies{
	"Philadelphia Phillies",
	"PHI",
	{ 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388 },
	{ 386, 377, 385, 379, 383, 374, 378, 384, 376 },
	{ 384, 385, 379, 386, 374, 376, 383, 378, 377 },
	386,
	{ 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308 },
	308
};

Division ALeast{
	"AL East",
	{ Orioles, RedSox, Yankees, Rays, BlueJays }
};
Division ALcentral{
	"AL Central",
	{ Guardians, Royals, Tigers, Twins, WhiteSox }
};
Division ALwest{
	"AL West",
	{ Angels, Astros, Athletics, Mariners, Rangers }
};

Division NLeast{
	"NL East",
	{ Diamondbacks, Braves, Marlins, Mets, Phillies }
};
Division NLcentral{
	"NL Central",
	{}
}; 
Division NLwest{
	"NL West",
	{}
};

League AmericanLeague{
	"American League",
	{ ALeast, ALcentral, ALwest }
};
League NationalLeague{
	"National League",
	{ NLeast, NLcentral, NLwest}
};

Organization MLB{
	"MLB",
	{AmericanLeague, NationalLeague}
};

Team awayTeam{};
Team homeTeam{};

int outs{};
int score{};
int inning{};
int half{};

int bases[4]{};
/* 0 means at home
 * 1 means 1st base
 * 2 means 2nd base
 * 3 means 3rd base
 */
int teamSize = 9;
int field[9]{};
int batter[9]{};

void fiveGameSeries(int team1, int team2) {
	int team1Wins{ 0 };
	int team2Wins{ 0 };
	awayTeam = { ALeast.teams[team1] };
	homeTeam = { ALeast.teams[team2] };
	game();
	team1Wins = { awayTeam.wins };
	team2Wins = { homeTeam.wins };
	std::cout << ALeast.teams[team1].teamName << ": " << team1Wins << '\n';
	std::cout << ALeast.teams[team2].teamName << ": " << team2Wins << '\n';
	stop();
	game();
	team1Wins = { awayTeam.wins };
	team2Wins = { homeTeam.wins };
	std::cout << ALeast.teams[team1].teamName << ": " << team1Wins << '\n';
	std::cout << ALeast.teams[team2].teamName << ": " << team2Wins << '\n';
	stop();
	awayTeam = { ALeast.teams[team2] };
	homeTeam = { ALeast.teams[team1] };
	game();
	team1Wins += homeTeam.wins;
	team2Wins += awayTeam.wins;
	std::cout << ALeast.teams[team1].teamName << ": " << team1Wins << '\n';
	std::cout << ALeast.teams[team2].teamName << ": " << team2Wins << '\n';
	stop();
	if (team1Wins == 3) {
		std::cout << ALeast.teams[team1].teamName << " wins!";
	}
	else if (team2Wins == 3) {
		std::cout << ALeast.teams[team2].teamName << " wins!";
	}
	else {
		team1Wins -= homeTeam.wins;
		team2Wins -= awayTeam.wins;
		game();
		team1Wins += homeTeam.wins;
		team2Wins += awayTeam.wins;
		std::cout << ALeast.teams[team1].teamName << ": " << team1Wins << '\n';
		std::cout << ALeast.teams[team2].teamName << ": " << team2Wins << '\n';
		stop();
		if (team1Wins == 3) {
			std::cout << ALeast.teams[team1].teamName << " wins!";
		}
		else if (team2Wins == 3) {
			std::cout << ALeast.teams[team2].teamName << " wins!";
		}
		else {
			awayTeam = { ALeast.teams[team1] };
			homeTeam = { ALeast.teams[team2] };
			game();
			team1Wins += awayTeam.wins;
			team2Wins += homeTeam.wins;
			std::cout << ALeast.teams[team1].teamName << ": " << team1Wins << '\n';
			std::cout << ALeast.teams[team2].teamName << ": " << team2Wins << '\n';
			stop();
			if (team1Wins == 3) {
				std::cout << ALeast.teams[team1].teamName << " wins!";
			}
			else {
				std::cout << ALeast.teams[team2].teamName << " wins!";
			}
		}
	}
}

void game() {
	bool b3{ true };
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	while (b3) {
		start();
		resetGame();
		bool b1{ true };
		bool b2{ true };
		while (b2) {
			while (b1) {
				if (displayText()) {
					lineups();
					pause();
					gameSpeed();
				}

				// engine of the game
				int batter{ currentBatter() };
				int pitcher{ currentPitcher() };
				nextBatter();
				nextPitcher();
				int stat1{};
				int pitchValue{ -1 };
				while (pitchValue == -1) {
					stat1 = { roll1() };
					pitchValue = { pitchResult(batter, pitcher, stat1) };
					if (displayText()) {
						rollPrinter(stat1);
						pitchPrinter(batter, pitcher, stat1);
						pause();
						gameSpeed();
						pitchResultPrinter(pitchValue);
						pause();
						gameSpeed();
					}
				}

				if (pitchValue == 1) {
					int hitPosition{ roll2() };
					if (displayText()) {
						rollPrinter(hitPosition);
						hitPositionPrinter(hitPosition);
						pause();
						gameSpeed();
					}
					int stat2{};
					int hitValue{ -1 };
					while (hitValue == -1) {
						stat2 = { roll1() };
						hitValue = { hitResult(hitPosition, batter, stat2) };
						if (displayText()) {
							if (hitPosition < 10) {
								rollPrinter(stat2);
								batterStatSelectorPrinter(stat2, batter);
								batterStatSelectorPrinter(stat2, hitPositionSelector((hitPosition - 1)));
								std::cout << '\n';
								pause();
								gameSpeed();
							}
							hitResultPrinter(hitValue);
							pause();
							gameSpeed();
						}
					}
				}

				if (displayText()) {
					basesPrinter();
					inningPrinter();
					outsPrinter();
					std::cout << '\n';
				}
				if (isGameOver()) {
					boxScore();
					resetGame();
					b1 = false;
					break;
				}
				if (isInningOver()) {
					if (displayText()) {
						inningOverPrinter();
					}
				}
				if (isLessThanMaxSpeed()) {
					boxScore();
					pause();
					pause();
					gameSpeed();
					system("CLS");
				}
			}
			winsPrinter();
			std::cout << "To exit press 0, to play again press 1, to change the speed press 2, "
				"to switch the home/away teams press 3.\n";
			int x{};
			x = _getch();
			if (x == '0') {
				b2 = false;
			}
			else if (x == '1') {
				Sleep(1);
				b1 = true;
			}
			else if (x == '2') {
				for (int i = 0; i < 100; i++) {
					Sleep(1);
					gameSpeed();
				}
				b1 = true;
			}
			else if (x == '3') {
				switchTeams();
				resetGame();
				Sleep(1);
				b1 = true;
			}
		}
		system("CLS");
	}
}

void switchTeams() {
	Team team1{ awayTeam };
	awayTeam = { homeTeam };
	homeTeam = { team1 };
}

void start() {
	// prints out the teams
	std::cout << "Teams:\n";
	for (int i = 0; i < 30; i++) {
		if (i % 5 == 0) {
			std::cout << '\n';
			std::cout << MLB.leagues[i / 15].divisions[(i % 15) / 5].divisionName << '\n';
		}
		std::cout << i + 1 << ". " << MLB.leagues[i / 15].divisions[(i % 15) / 5].teams[i % 5].teamName << '\n';
	}
	std::cout << '\n';

	// asks for the away team to be selected
	int x{};
	while (true) {
		std::cout << "Pick the away team: ";
		std::cin >> x;
		if (x > 0 && x <= 30) {
			awayTeam = { MLB.leagues[(x - 1) / 15].divisions[((x - 1) % 15) / 5].teams[(x - 1) % 5] };
			break;
		}
	}

	// asks for the home team to be selected
	int y{};
	while (true) {
		std::cout << "Pick the home team: ";
		std::cin >> y;
		if (y > 0 && y <= 30) {
			homeTeam = { MLB.leagues[(y - 1) / 15].divisions[((y - 1) % 15) / 5].teams[(y - 1) % 5] };
			break;
		}
	}
	system("CLS");
}

// prints out the lineups for the home and away teams
void lineups() {
	std::cout << "Away: " << awayTeam.teamName;
	for (int i = 0; i < (6 - ((static_cast<int>(awayTeam.teamName.length()) + 6) / 8)); i++) {
		std::cout << '\t';
	}
	std::cout << "Home: " << homeTeam.teamName << "\n\n";

	pitcherLineup();
	batterLineup();
}

// !!! use abstraction later
// prints out the batting lineup
void batterLineup() {
	for (int i = 0; i < 9; i++) {

		// away team
		std::cout << i + 1 << ". " << batterFullName(awayTeam.battingLineup[i]);
		for (int j = 0; j < (4 - (static_cast<int>(batterFullName(awayTeam.battingLineup[i]).length()) + 3) / 8); j++) {
			std::cout << '\t';
		}
		std::cout << batterStringStatSelector(2, awayTeam.battingLineup[i]) << "\t\t";

		// home team
		std::cout << i + 1 << ". " << batterFullName(homeTeam.battingLineup[i]);
		for (int j = 0; j < (4 - (static_cast<int>(batterFullName(homeTeam.battingLineup[i]).length()) + 3) / 8); j++) {
			std::cout << '\t';
		}
		std::cout << batterStringStatSelector(2, homeTeam.battingLineup[i]) << '\n';
	}
	std::cout << '\n';
}

// prints out the pitching lineup
void pitcherLineup() {
	for (int i = 0; i < 1; i++) {

		// away team
		std::cout << i + 1 << ". " << pitcherFullName(awayTeam.currentPitcher);
		for (int j = 0; j < (4 - (static_cast<int>(pitcherFullName(awayTeam.currentPitcher).length()) + 3) / 8); j++) {
			std::cout << '\t';
		}
		std::cout << pitcherStringStatSelector(2, awayTeam.currentPitcher) << "\t\t";

		// home team
		std::cout << i + 1 << ". " << pitcherFullName(homeTeam.currentPitcher);
		for (int j = 0; j < (4 - (static_cast<int>(pitcherFullName(homeTeam.currentPitcher).length()) + 3) / 8); j++) {
			std::cout << '\t';
		}
		std::cout << pitcherStringStatSelector(2, homeTeam.currentPitcher) << '\n';
	}
	std::cout << '\n';
}

// returns the current batter and sets them to being at bat
int currentBatter() {
	if (half == 0) {
		bases[0] = awayTeam.currentBatter;
		return awayTeam.currentBatter;
	}
	else {
		bases[0] = homeTeam.currentBatter;
		return homeTeam.currentBatter;
	}
}
int currentPitcher() {
	if (half == 0) {
		return homeTeam.currentPitcher;
	}
	else {
		return awayTeam.currentPitcher;
	}
}

// updates the current batter
void nextBatter() {
	if (half == 0) {
		for (int i = 0; i < 9; i++) {
			if (awayTeam.currentBatter == awayTeam.battingLineup[i]) {
				if (i == 8) {
					awayTeam.currentBatter = awayTeam.battingLineup[0];
				}
				else {
					awayTeam.currentBatter = awayTeam.battingLineup[i + 1];
				}
				break;
			}
		}
		//nextBatter2(awayTeam);
	}
	else {
		for (int i = 0; i < 9; i++) {
			if (homeTeam.currentBatter == homeTeam.battingLineup[i]) {
				if (i == 8) {
					homeTeam.currentBatter = homeTeam.battingLineup[0];
				}
				else {
					homeTeam.currentBatter = homeTeam.battingLineup[i + 1];
				}
				break;
			}
		}
		//nextBatter2(homeTeam);
	}
}
// ***does nothing for now***
void nextPitcher() {
}

// abstract function for nextBatter()
void nextBatter2(Team team) {
	for (int i = 0; i < 9; i++) {
		if (team.currentBatter == team.battingLineup[i]) {
			if (i == 8) {
				team.currentBatter = team.battingLineup[0];
			}
			else {
				team.currentBatter = team.battingLineup[i + 1];
			}
			break;
		}
	}
	std::cout << team.currentBatter << '\n';
}




/* returns the result of the pitch
 * 1 -> contact
 * 0 -> out
 */
int batterPitcherStats[4][6]{
	{ 0, 6, 3, 7, 13, 3}, // batter stat
	{ 0, 1, 3, 8, 12, 4 }, // pitcher stat
	{ 1, 1, 2, 2, 1, 1 }, // batter multiplier
	{ 3, 2, 1, 1, 1, 1 } // pitcher multiplier
};
int pitchResult(int batter, int pitcher, int stat) {
	if (stat == 6) {
		if (batterStringStatSelector(batterPitcherStats[0][stat - 1], batter) == "S") {
			return isContact(1);
		}
		else if (batterStringStatSelector(batterPitcherStats[0][stat - 1], batter) == "L" &&
			pitcherStringStatSelector(batterPitcherStats[1][stat - 1], pitcher) == "R") {
			return isContact(1);
		}
		else if (batterStringStatSelector(batterPitcherStats[0][stat - 1], batter) == "R" &&
			pitcherStringStatSelector(batterPitcherStats[1][stat - 1], pitcher) == "L") {
			return isContact(1);
		}
		else {
			return isContact(0);
		}
	}
	else {
		if (batterPitcherStats[2][stat - 1] * batterStatSelector(batterPitcherStats[0][stat - 1], batter) >
			batterPitcherStats[3][stat - 1] * pitcherStatSelector(batterPitcherStats[1][stat - 1], pitcher)) {
			return isContact(1);
		}
		else if (batterPitcherStats[2][stat - 1] * batterStatSelector(batterPitcherStats[0][stat - 1], batter) ==
			batterPitcherStats[3][stat - 1] * pitcherStatSelector(batterPitcherStats[1][stat - 1], pitcher)) {
			return -1;
		}
		else {
			return isContact(0);
		}
	}
}

// prints out the stats of the pitch
void pitchPrinter(int batter, int pitcher, int stat) {
	if (stat == 6) {
		std::cout << batterFullName(batter) << " bats: " << 
			batterStringStatSelector(batterPitcherStats[0][stat-1], batter) << '\n';
		std::cout << pitcherFullName(pitcher) << " throws: " << 
			pitcherStringStatSelector(batterPitcherStats[1][stat - 1], pitcher) << '\n';
	}
	else {
		batterStatSelectorPrinter(batterPitcherStats[0][stat - 1], batter);
		pitcherStatSelectorPrinter(batterPitcherStats[1][stat - 1], pitcher);
	}
	std::cout << '\n';
}

// prints out the result of the pitch
void pitchResultPrinter(int pitchValue) {
	if (pitchValue == 1) {
		std::cout << "The ball is put into play!" << '\n';
	}
	else if (pitchValue == 0) {
		std::cout << "Out!" << '\n';
	}
	std::cout << '\n';
}



// returns 1 if contact was made, returns 1 and updates the outs if not
int isContact(int value) {
	if (value == 0) {
		outs++;
		bases[0] = 0;
		return 0;
	}
	else {
		return 1;
	}
}


// returns the fielder at the given position
int hitPositionSelector(int position) {
	return field[position];
}


// quotes for every hit position
std::string hitPositionQuotes[11]{
	"It's hit to the catcher: ",
	"It's hit to the first baseman: ", 
	"It's hit to the second baseman: ",
	"It's hit to the third baseman: ",
	"It's hit to the shortstop: ",
	"It's hit to the left fielder: ", 
	"It's hit to the center fielder: ",
	"It's hit to the right fielder: ",
	"It's a double!",
	"It's a triple!", 
	"It's a homerun!"
};
// prints out the name of the player the ball is hit to
void hitPositionPrinter(int position) {
	if (position < 10) {
		std::cout << hitPositionQuotes[position - 2] << batterStringStatSelector(0, field[position - 1]) <<
			" " << batterStringStatSelector(1, field[position - 1]) << "\n\n";
	}
	else {
		std::cout << hitPositionQuotes[position - 2] << "\n\n";
	}
}

// prints out the result of the contact
void hitResultPrinter(int hitValue) {
	switch (hitValue) {
	case 0:
		std::cout << "Out!" << '\n';
		break;
	case 1:
		std::cout << "Single!" << '\n';
		break;
	case 2:
		std::cout << "Double!" << '\n';
		break;
	case 3:
		std::cout << "Triple!" << '\n';
		break;
	case 4:
		std::cout << "Homerun!" << '\n';
		break;
	default:
		break;
	}
	std::cout << '\n';
}

// determines the result of making contact and returns the hit value
int hitResult(int hitPosition, int batter, int stat) {
	switch (hitPosition) {
	case 10:
		return isHit(batter, 2);
		break;
	case 11:
		return isHit(batter, 3);
		break;
	case 12:
		return isHit(batter, 4);
		break;
	default:
		if (batterStatSelector(stat, batter) > batterStatSelector(stat,
			hitPositionSelector((hitPosition - 1)))) {
			if (hitPosition == 7 || hitPosition == 8 || hitPosition == 9) {
				return isHit(batter, 2);
			}
			else {
				return isHit(batter, 1);
			}
		}
		else if (batterStatSelector(stat, batter) == batterStatSelector(stat,
			hitPositionSelector((hitPosition - 1)))) {
			return -1;
		}
		else {
			return isHit(batter, 0);
		}
		break;
	}
}


/* updates the game state when a hit occurs
 * changes the runners, outs, inning, score
 */
int isHit(int batter, int value) {
	switch (value) {
	case 0:
		outs++;
		bases[0] = 0;
		break;
	case 1:
		for (int i = 3; i >= 3; i--) {
			if (bases[i] != 0) {
				isScored();
			}
		}
		hitCounter();

		bases[3] = bases[2];
		bases[2] = bases[1];
		bases[1] = batter;
		bases[0] = 0;
		break;
	case 2:
		for (int i = 3; i >= 2; i--) {
			if (bases[i] != 0) {
				isScored();
			}
		}
		hitCounter();

		bases[3] = bases[1];
		bases[2] = batter;
		bases[1] = 0;
		bases[0] = 0;
		break;
	case 3:
		for (int i = 3; i >= 1; i--) {
			if (bases[i] != 0) {
				isScored();
			}
		}
		hitCounter();

		bases[3] = batter;
		bases[2] = 0;
		bases[1] = 0;
		bases[0] = 0;
		break;
	case 4:
		for (int i = 3; i >= 0; i--) {
			if (bases[i] != 0) {
				isScored();
			}
		}
		hitCounter();

		bases[3] = 0;
		bases[2] = 0;
		bases[1] = 0;
		bases[0] = 0;
	default:
		break;
	}
	return value;
}

// adds 1 to the hits for the hitting team
void hitCounter() {
	if (half == 0) {
		awayTeam.score[19]++;
	}
	else {
		homeTeam.score[19]++;
	}
}

// scores a run for the hitting team
void isScored() {
	if (half == 0) {
		awayTeam.score[inning - 1]++;
		awayTeam.score[18]++;
	}
	else {
		homeTeam.score[inning - 1]++;
		homeTeam.score[18]++;
	}
}

// prints out the current outs
void outsPrinter() {
	std::cout << "Outs: " << outs << '\n';
}

// prints out the current inning including top or bottom
void inningPrinter() {
	if (half == 0) {
		std::cout << "Inning: Top " << inning << '\n';
	}
	else {
		std::cout << "Inning: Bottom " << inning << '\n';
	}
}

// prints out the boxscore
void boxScore() {
	if (inning <= 9) {
		std::cout << "    | 1| 2| 3| 4| 5| 6| 7| 8| 9| R| H" << '\n';
	}
	else {
		std::cout << "    |10|11|12|13|14|15|16|17|18| R| H" << '\n';
	}
	std::cout << "____|__|__|__|__|__|__|__|__|__|__|__" << '\n';
	std::cout << awayTeam.teamInitials << " ";
	for (int i = (((inning - 1) / 9) * 9); i < (((inning + 8) / 9) * 9); i++) {
		if (i + 1 <= inning) {
			if (awayTeam.score[i] < 10) {
				std::cout << "| " << awayTeam.score[i];
			}
			else {
				std::cout << "|" << awayTeam.score[i];
			}
		}
		else {
			std::cout << "|  ";
		}
	}
	for (int i = 18; i < 20; i++) {
		if (awayTeam.score[i] < 10) {
			std::cout << "| " << awayTeam.score[i];
		}
		else {
			std::cout << "|" << awayTeam.score[i];
		}
	}
	std::cout << '\n';
	std::cout << "____|__|__|__|__|__|__|__|__|__|__|__" << '\n';
	std::cout << homeTeam.teamInitials << " ";
	for (int i = (((inning - 1) / 9) * 9); i < (((inning + 8) / 9) * 9); i++) {
		if (i + 1 < inning || (i + 1 == inning && half == 1)) {
			if (homeTeam.score[i] < 10) {
				std::cout << "| " << homeTeam.score[i];
			}
			else {
				std::cout << "|" << homeTeam.score[i];
			}
		}
		else {
			std::cout << "|  ";
		}
	}
	for (int i = 18; i < 20; i++) {
		if (homeTeam.score[i] < 10) {
			std::cout << "| " << homeTeam.score[i];
		}
		else {
			std::cout << "|" << homeTeam.score[i];
		}
	}
	std::cout << "\n\n";
}

// prints the runners on base
void basesPrinter() {
	std::cout << "At bat: " << batterStringStatSelector(0, bases[0]) << " "
		<< batterStringStatSelector(1, bases[0]) << '\n';
	std::cout << "On first: " << batterStringStatSelector(0, bases[1]) << " "
		<< batterStringStatSelector(1, bases[1]) << '\n';
	std::cout << "On second: " << batterStringStatSelector(0, bases[2]) << " "
		<< batterStringStatSelector(1, bases[2]) << '\n';
	std::cout << "On third: " << batterStringStatSelector(0, bases[3]) << " "
		<< batterStringStatSelector(1, bases[3]) << '\n';
	std::cout << '\n';
}

// prints out how many wins each team has so far
void winsPrinter() {
	std::cout << awayTeam.teamInitials << ": " << awayTeam.wins << '\n';
	std::cout << homeTeam.teamInitials << ": " << homeTeam.wins << "\n\n";
}

void inningOverPrinter() {
	std::cout << "The inning is over.\n";
}

// returns true if the inning is over
bool isInningOver() {
	if (outs == 3) {
		outs = 0;
		if (half == 0) {
			for (int i = 0; i < teamSize; i++) {
				field[i] = awayTeam.fieldingLineup[i];
			}
			half = 1;
		}
		else {
			for (int i = 0; i < teamSize; i++) {
				field[i] = homeTeam.fieldingLineup[i];
			}
			half = 0;
			inning++;
		}
		// !!!
		if (inning > 9) {
			bases[3] = 0;
			bases[2] = awayTeam.currentBatter;
			bases[1] = 0;
			bases[0] = 0;
		}
		else {
			bases[3] = 0;
			bases[2] = 0;
			bases[1] = 0;
			bases[0] = 0;
		}
		return true;
	}
	else {
		return false;
	}
}

// returns true if the game is over
bool isGameOver() {
	if (inning == 9 && half == 0 && outs == 3 && homeTeam.score[18] > awayTeam.score[18]) {
		std::cout << homeTeam.teamName << " wins!" << "\n\n";
		homeTeam.wins++;
		return true;
	}
	else if (inning >= 9 && half == 1 && homeTeam.score[18] > awayTeam.score[18]) {
		std::cout << homeTeam.teamName << " wins!" << "\n\n";
		homeTeam.wins++;
		return true;
	}
	else if (inning >= 9 && half == 1 && outs == 3 && homeTeam.score[18] < awayTeam.score[18]) {
		std::cout << awayTeam.teamName << " wins!" << "\n\n";
		awayTeam.wins++;
		return true;
	}
	else if (inning == 19) {
		std::cout << "It's a tie!" << "\n\n";
		return true;
	}
	else {
		return false;
	}
}

// resets the game to the initial gamestate
void resetGame() {
	awayTeam.currentBatter = awayTeam.battingLineup[0];
	homeTeam.currentBatter = homeTeam.battingLineup[0];
	for (int i = 0; i < 20; i++) {
		awayTeam.score[i] = {};
		homeTeam.score[i] = {};
	}
	for (int i = 0; i < 9; i++) {
		field[i] = { homeTeam.fieldingLineup[i] };
	}
	for (int i = 0; i < 4; i++){
		bases[i] = { 0 };
	}
	//resetSpeed();
	inning = { 1 };
	outs = { 0 };
	half = { 0 };
}