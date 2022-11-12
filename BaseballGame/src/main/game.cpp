
#include "game.h"

#include <iostream>
#include <conio.h>
#include <string>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

/*
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
*

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
*/



Batter* b = new Batter("Maikel", "Franco", "3B", "R", "R", 104, 377, 31, 79, 22, 0, 11, 47, 0, 20, 0.355, 0.609, 0.21, -1.6);
Batter* c = new Batter("Kelvin","Gutierrez","3B","R","R",85,272,23,63,8,3,3,20,0,19,0.316,0.608,0.232,-0.1);
Pitcher* p = new Pitcher("Keegan", "Akin", "P", "R", "L", 24, 2, 10, 95, 110, 70, 70, 40, 82, 0, 1.579, 6.63, -0.3);

Batter* arr1[20] = { b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b};
Batter* arr2[9] = { b, b, b, b, b, b, b, b, b };
Batter* arr3[8] = { b, b, b, b, b, b, b, b };
Pitcher* arr4[20] = { p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p };
Batter* arr5[20] = { c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c };
Batter* arr6[20] = { c, c, c, c, c, c, c, c, c };
Batter* arr7[20] = { c, c, c, c, c, c, c, c };

Team Orioles {
	"Balimore Orioles",
	"BAL",
	arr1,
	arr2,
	arr3,
	b,
	arr4,
	p
};
Team RedSox {
	"Boston Red Sox",
	"BOS",
	arr5,
	arr6,
	arr7, 
	c,
	arr4,
	p
};


/*
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
*/

Game::Game() {

	std::srand((int) (std::time(0)));
	start();
	resetGame();
	bool b1 = true;
	bool b2 = true;
	while (b2) {
		while (b1) {
			if (displayText()) {
				homeTeam->lineups(homeTeam, awayTeam);
				pause();
				gameSpeed();
			}

			// engine of the game

			int pitchValue = -1;

			while (pitchValue == -1) {
				int stat1 = roll1();
				pitchValue = pitchResult(stat1);
				
				if (displayText()) {
					rollPrinter(stat1);
					pitchPrinter(stat1);
					pause();
					gameSpeed();
					pitchResultPrinter(pitchValue);
					pause();
					gameSpeed();
				}
			}

			if (pitchValue == 1) {
				int hitPosition = roll2();
				if (displayText()) {
					rollPrinter(hitPosition);
					hitPositionPrinter(hitPosition);
					pause();
					gameSpeed();
				}
				int hitValue = -1;
				while (hitValue == -1) {
					int stat2 = roll1();
					hitValue = hitResult(hitPosition, stat2);
					if (displayText()) {
						if (hitPosition < 10) {
							rollPrinter(stat2);
							getCurrentBatter()->statSelectorPrinter(stat2);
							hitPositionSelector(hitPosition)->statSelectorPrinter(stat2);
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

			nextBatter();
			nextPitcher();

			if (displayText()) {
				basesPrinter();
				inningPrinter();
				outsPrinter();
				std::cout << '\n';
			}
			if (isGameOver()) {
				boxScorePrinter();
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
				boxScorePrinter();
				pause();
				pause();
				gameSpeed();
				system("CLS");
			}
		}
		winsPrinter();

		std::cout << "To exit press 0, to play again press 1, to change the speed press 2, "
			"to switch the home/away teams press 3.\n";

		int x = _getch();

		switch (x) {
		case '0':
			b2 = false;
			break;
		case '1':
			Sleep(1);
			b1 = true;
			break;
		case '2':
			for (int i = 0; i < 100; i++) {
				Sleep(1);
				gameSpeed();
			}
			b1 = true;
			break;
		case '3':
			swapTeams();
			resetGame();
			Sleep(1);
			b1 = true;
			break;
		default:
			break;
		}
	}
	system("CLS");
}


void Game::swapTeams() {
	Team* team1 = awayTeam;
	awayTeam = homeTeam;
	homeTeam = team1;
}


void Game::start() {
	// prints out the teams
	/*
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
	*/
	awayTeam = &Orioles;
	homeTeam = &RedSox;
}

Batter* Game::getCurrentBatter() {
	if (half == 0) {
		bases[0] = awayTeam->getCurrentBatter();
		return awayTeam->getCurrentBatter();
	}
	else {
		bases[0] = homeTeam->getCurrentBatter();
		return homeTeam->getCurrentBatter();
	}
}

Pitcher* Game::getCurrentPitcher() {
	if (half == 0) {
		return homeTeam->getCurrentPitcher();
	}
	else {
		return awayTeam->getCurrentPitcher();
	}
}




int batterPitcherStats[4][6]{
	{ 0, 6, 3, 7, 13, 3}, // batter stat
	{ 0, 1, 3, 8, 12, 4 }, // pitcher stat
	{ 1, 1, 2, 2, 1, 1 }, // batter multiplier
	{ 3, 2, 1, 1, 1, 1 } // pitcher multiplier
};

void Game::pitchPrinter(int stat) {
	if (stat == 6) {
		std::cout << getCurrentBatter()->fullName() << " bats: " <<
			getCurrentBatter()->stringStatSelector(batterPitcherStats[0][stat - 1]) << '\n';
		std::cout << getCurrentPitcher()->fullName() << " throws: " <<
			getCurrentPitcher()->stringStatSelector(batterPitcherStats[1][stat - 1]) << '\n';
	}
	else {
		getCurrentBatter()->statSelectorPrinter(batterPitcherStats[0][stat - 1]);
		getCurrentPitcher()->statSelectorPrinter(batterPitcherStats[1][stat - 1]);
	}
	std::cout << '\n';
}

int Game::pitchResult(int stat) {
	if (stat == 6) {
		std::string b = getCurrentBatter()->stringStatSelector(batterPitcherStats[0][stat - 1]);
		std::string p = getCurrentPitcher()->stringStatSelector(batterPitcherStats[1][stat - 1]);

		if (b == "S") {
			return 1;
		}
		else if (b == "L" && p == "R") {
			return 1;
		}
		else if (b == "R" && p == "L") {
			return 1;
		}
		else {
			isOut();
			return 0;
		}
	}
	else {
		int bScalar = batterPitcherStats[2][stat - 1];
		double bStat = getCurrentBatter()->statSelector(batterPitcherStats[0][stat - 1]);
		int pScalar = batterPitcherStats[3][stat - 1];
		double pStat = getCurrentPitcher()->statSelector(batterPitcherStats[1][stat - 1]);
		
		if (bScalar * bStat > pScalar * pStat) {
			return 1;
		}
		else if (bScalar * bStat == pScalar * pStat) {
			return -1;
		}
		else {
			isOut();
			return 0;
		}
		
	}
}

void Game::pitchResultPrinter(int pitchValue) {
	if (pitchValue == 1) {
		std::cout << "The ball is put into play!" << '\n';
	}
	else if (pitchValue == 0) {
		std::cout << "Out!" << '\n';
	}
	std::cout << '\n';
}





Batter* Game::hitPositionSelector(int position) {
	return field[position - 2];
}

void Game::hitPositionPrinter(int position) {

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

	std::cout << hitPositionQuotes[position - 2];
	if (position < 10) {
		std::cout << hitPositionSelector(position)->fullName();
	}
	std::cout << std::endl << std::endl;
}

int Game::hitResult(int hitPosition, int stat) {
	switch (hitPosition) {
	case 10:
		return isHit(2);
		break;
	case 11:
		return isHit(3);
		break;
	case 12:
		return isHit(4);
		break;
	default:
		if (getCurrentBatter()->statSelector(stat) > hitPositionSelector(hitPosition)->statSelector(stat)) {
			if (hitPosition == 7 || hitPosition == 8 || hitPosition == 9) {
				return isHit(2);
			}
			else {
				return isHit(1);
			}
		}
		else if (getCurrentBatter()->statSelector(stat) == hitPositionSelector(hitPosition)->statSelector(stat)) {
			return -1;
		}
		else {
			return isHit(0);
		}
		break;
	}
}

void Game::hitResultPrinter(int hitValue) {
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

int Game::isHit(int hitValue) {
	if (hitValue == 0) {
		isOut();
	}
	else {
		for (int i = 3; i > 3 - hitValue; i--) {
			if (bases[i] != NULL) {
				isScored();
			}
		}
		hitCounter();

		switch (hitValue) {
		case 1:
			bases[3] = bases[2];
			bases[2] = bases[1];
			bases[1] = getCurrentBatter();
			bases[0] = NULL;
			break;
		case 2:
			bases[3] = bases[1];
			bases[2] = getCurrentBatter();
			bases[1] = NULL;
			bases[0] = NULL;
			break;
		case 3:
			bases[3] = getCurrentBatter();
			bases[2] = NULL;
			bases[1] = NULL;
			bases[0] = NULL;
			break;
		case 4:
			bases[3] = NULL;
			bases[2] = NULL;
			bases[1] = NULL;
			bases[0] = NULL;
		default:
			break;
		}
	}
	return hitValue;
}

void Game::hitCounter() {
	if (half == 0) {
		score[0][19]++;
	}
	else {
		score[1][19]++;
	}
}

void Game::isScored() {
	if (half == 0) {
		score[0][inning - 1]++;
		score[0][18]++;
	}
	else {
		score[1][inning - 1]++;
		score[1][18]++;
	}
}

void Game::isOut() {
	outs++;
	bases[0] = NULL;
}



void Game::nextBatter() {
	if (half == 0) {
		awayTeam->nextBatter();
	}
	else {
		homeTeam->nextBatter();
	}
}

void Game::nextPitcher() {
}



/*
 * Printers
 */

void Game::basesPrinter() {
	std::cout << "At bat: ";
	if (bases[0] != NULL) {
		std::cout << bases[0]->fullName();
	}
	std::cout << std::endl;

	std::cout << "On first: ";
	if (bases[1] != NULL) {
		std::cout << bases[1]->fullName();
	}
	std::cout << std::endl;

	std::cout << "On second: ";
	if (bases[2] != NULL) {
		std::cout << bases[2]->fullName();
	}
	std::cout << std::endl;

	std::cout << "On third: ";
	if (bases[3] != NULL) {
		std::cout << bases[3]->fullName();
	}
	std::cout << std::endl << std::endl;
}

void Game::inningPrinter() {
	if (half == 0) {
		std::cout << "Inning: Top " << inning << '\n';
	}
	else {
		std::cout << "Inning: Bottom " << inning << '\n';
	}
}

void Game::outsPrinter() {
	std::cout << "Outs: " << outs << '\n';
}

void Game::boxScorePrinter() {
	if (inning <= 9) {
		std::cout << "    | 1| 2| 3| 4| 5| 6| 7| 8| 9| R| H" << '\n';
	}
	else {
		std::cout << "    |10|11|12|13|14|15|16|17|18| R| H" << '\n';
	}
	std::cout << "____|__|__|__|__|__|__|__|__|__|__|__" << '\n';
	std::cout << awayTeam->getInitials() << " ";
	for (int i = (((inning - 1) / 9) * 9); i < (((inning + 8) / 9) * 9); i++) {
		if (i + 1 <= inning) {
			if (score[0][i] < 10) {
				std::cout << "| " << score[0][i];
			}
			else {
				std::cout << "|" << score[0][i];
			}
		}
		else {
			std::cout << "|  ";
		}
	}
	for (int i = 18; i < 20; i++) {
		if (score[0][i] < 10) {
			std::cout << "| " << score[0][i];
		}
		else {
			std::cout << "|" << score[0][i];
		}
	}
	std::cout << '\n';
	std::cout << "____|__|__|__|__|__|__|__|__|__|__|__" << '\n';
	std::cout << homeTeam->getInitials() << " ";
	for (int i = (((inning - 1) / 9) * 9); i < (((inning + 8) / 9) * 9); i++) {
		if (i + 1 < inning || (i + 1 == inning && half == 1)) {
			if (score[1][i] < 10) {
				std::cout << "| " << score[1][i];
			}
			else {
				std::cout << "|" << score[1][i];
			}
		}
		else {
			std::cout << "|  ";
		}
	}
	for (int i = 18; i < 20; i++) {
		if (score[1][i] < 10) {
			std::cout << "| " << score[1][i];
		}
		else {
			std::cout << "|" << score[1][i];
		}
	}
	std::cout << "\n\n";
}

void Game::winsPrinter() {
	awayTeam->winsPrinter();
	homeTeam->winsPrinter();
	std::cout << std::endl;
}

void Game::inningOverPrinter() {
	std::cout << "The inning is over.\n";
}





bool Game::isInningOver() {
	if (outs == 3) {
		outs = 0;
		if (half == 0) {
			for (int i = 0; i < teamSize - 1; i++) {
				field[i] = awayTeam->getFielderInLineup(i);
			}
			half = 1;
		}
		else {
			for (int i = 0; i < teamSize - 1; i++) {
				field[i] = homeTeam->getFielderInLineup(i);
			}
			half = 0;
			inning++;
		}
		if (inning > 9) {
			bases[3] = NULL;
			bases[2] = awayTeam->getCurrentBatter();
			bases[1] = NULL;
			bases[0] = NULL;
		}
		else {
			bases[3] = NULL;
			bases[2] = NULL;
			bases[1] = NULL;
			bases[0] = NULL;
		}
		return true;
	}
	else {
		return false;
	}
}

bool Game::isGameOver() {
	if (inning == 9 && half == 0 && outs == 3 && score[1][18] > score[0][18]) {
		std::cout << homeTeam->getName() << " wins!" << "\n\n";
		int wins = homeTeam->getWins();
		homeTeam->setWins(++wins);
		return true;
	}
	else if (inning >= 9 && half == 1 && score[1][18] > score[0][18]) {
		std::cout << homeTeam->getName() << " wins!" << "\n\n";
		int wins = homeTeam->getWins();
		homeTeam->setWins(++wins);
		return true;
	}
	else if (inning >= 9 && half == 1 && outs == 3 && score[1][18] < score[0][18]) {
		std::cout << awayTeam->getName() << " wins!" << "\n\n";
		int wins = awayTeam->getWins();
		awayTeam->setWins(++wins);
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

void Game::resetGame() {
	awayTeam->setCurrentBatter(awayTeam->getBatterInLineup(0));
	homeTeam->setCurrentBatter(homeTeam->getBatterInLineup(0));
	for (int i = 0; i < 20; i++) {
		score[0][i] = {};
		score[1][i] = {};
	}
	for (int i = 0; i < teamSize - 1; i++) {
		field[i] = homeTeam->getFielderInLineup(i);
	}
	for (int i = 0; i < 4; i++) {
		bases[i] = NULL;
	}
	//resetSpeed();
	inning = 1;
	outs = 0;
	half = 0;
}