#include "batter.h"
#include <iostream>
#include <string>







/*
Batter batters[37]{
	{"","","","","",0,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0},
	{"Reese","McGuire","C","R","R",78,198,22,50,15,0,1,10,0,15,0.343,0.654,0.253,0.3},
	{"Vladimir","Guerrero Jr.","1B","R","R",161,604,123,188,29,1,48,111,4,86,0.601,1.002,0.311,6.8},
	{"Marcus","Semien","2B","R","R",162,652,115,173,39,2,45,102,15,66,0.538,0.873,0.265,7.3},
	{"Bo","Bichette","SS","R","R",159,640,121,191,30,1,29,102,25,40,0.484,0.828,0.298,5.9},
	{"Santiago","Espinal","3B","R","R",92,222,32,69,13,1,2,17,6,22,0.405,0.781,0.311,2.5},
	{"Lourdes","Gurriel Jr.","LF","R","R",141,500,62,138,28,2,21,84,1,32,0.466,0.785,0.276,2.7},
	{"Randal","Grichuk","CF","R","R",149,511,59,123,25,1,22,81,0,27,0.423,0.703,0.241,0.8},
	{"Teoscar","Hernandez","RF","R","R",143,550,92,163,29,0,32,116,12,36,0.524,0.87,0.296,3.9},
	{"George","Springer","DH","R","R",78,299,59,79,19,1,22,50,4,37,0.555,0.907,0.264,2.4},
	{"Mike","Zunino","C","R","R",109,333,64,72,11,2,33,62,0,34,0.559,0.86,0.216,3.8},
	{"Yandy","Diaz","1B","R","R",134,465,62,119,20,1,13,64,1,69,0.387,0.74,0.256,1.6},
	{"Brandon","Lowe","2B","L","R",149,535,97,132,31,0,39,99,7,68,0.523,0.863,0.247,4.7},
	{"Wander","Franco","SS","S","R",70,281,53,81,18,5,7,39,2,24,0.463,0.81,0.288,3.5},
	{"Joey","Wendle","3B","L","R",136,460,73,122,31,4,11,54,8,28,0.422,0.741,0.265,3.8},
	{"Austin","Meadows","LF","L","L",142,518,79,121,29,3,27,106,4,59,0.458,0.772,0.234,2.0},
	{"Kevin","Kiermaier","CF","L","R",122,348,54,90,19,7,4,37,9,33,0.388,0.716,0.259,3.4},
	{"Manuel","Margot","RF","R","R",125,421,55,107,18,3,10,57,13,37,0.382,0.696,0.254,2.8},
	{"Nelson","Cruz","DH","R","R",55,217,35,49,8,0,13,36,0,16,0.442,0.725,0.226,0.5},
	{"Gary","Sanchez","C","R","R",117,383,54,78,13,1,23,54,0,52,0.423,0.73,0.204,0.7},
	{"Anthony","Rizzo","1B","L","L",49,173,32,43,7,0,8,21,2,16,0.428,0.768,0.249,0.5},
	{"DJ","LeMahieu","2B","R","R",150,597,84,160,24,1,10,57,4,73,0.362,0.711,0.268,1.5},
	{"Gleyber","Torres","SS","R","R",127,459,50,119,22,0,9,51,14,50,0.366,0.697,0.259,0.8},
	{"Gio","Urshela","3B","R","R",116,420,42,112,18,2,14,49,1,20,0.419,0.72,0.267,0.6},
	{"Joey","Gallo","LF","L","R",58,188,33,30,7,0,13,22,0,37,0.404,0.707,0.16,0.5},
	{"Brett","Gardner","CF","L","L",140,387,47,86,16,4,10,39,4,60,0.362,0.689,0.222,1},
	{"Aaron","Judge","RF","R","R",148,550,89,158,24,0,39,98,6,75,0.544,0.916,0.287,6},
	{"Giancarlo","Stanton","DH","R","R",139,510,64,139,19,0,35,97,0,63,0.516,0.87,0.273,3.1},
	{"Christian","Vazquez","C","R","R",138,458,51,118,23,1,6,49,8,33,0.352,0.659,0.258,1},
	{"Bobby","Dalbec","1B","R","R",133,417,50,100,21,5,25,78,2,28,0.494,0.792,0.24,0.2},
	{"Christian","Arroyo","2B","R","R",57,164,22,43,12,0,6,25,1,8,0.445,0.769,0.262,1.4},
	{"Xander","Bogaerts","SS","R","R",144,529,90,156,34,1,23,79,5,62,0.493,0.863,0.295,4.9},
	{"Rafael","Devers","3B","L","R",156,591,101,165,37,1,38,113,5,62,0.538,0.89,0.279,3.5},
	{"Alex","Verdugo","LF","L","L",146,544,88,157,32,2,13,63,6,51,0.426,0.777,0.289,2.2},
	{"Enrique","Hernandez","CF","R","R",134,508,84,127,35,3,20,60,1,61,0.449,0.786,0.25,4.9},
	{"Hunter","Renfroe","RF","R","R",144,521,89,135,33,0,31,96,1,44,0.501,0.816,0.259,2.3},
	{"J.D.","Martinez","DH","R","R",148,570,92,163,42,3,28,99,0,55,0.518,0.867,0.286,3}
};
*/
/*
// allows the user to select a batter and returns the number for the chosen batter
int Batter::selectorInput() {
	int x{};
	while (true) {
		std::cout << "Type in the number corresponding to player you wish to view: ";
		std::cin >> x;
		
		//if (x > 9 || x < 1) {
		//	std::cout << "Try Again. ";
		//}
		//else {
		//	std::cout << "You selected: ";
			for (int i = 0; i < 10; i++) {
				if (i == x) {
					std::cout << batters[i].firstName << " " << batters[i].lastName << '\n';
				}
			}
			break;
		//}
	}
	std::cout << std::endl;
	return x;
}

// prints the batter selector screen and returns the number for the batter chosen
void Batter::selectorScreen() {
	for (int i = 1; i < 10; i++) {
		std::cout << i << ". " << batters[i].firstName << " "
			      << batters[i].lastName << '\n';
	}
	std::cout << std::endl;
}


std::string Batter::nameSelector(int name, int batter) {
	switch (name) {
	case 0:
		return batters[batter].firstName;
		break;
	case 1:
		return batters[batter].lastName;
		break;
	case 2:
		return batters[batter].position;
		break;
	default:
		return "Invalid Selection";
		break;
	}
}


// allows the user to select which stat they want to select
int Batter::statSelectorInput(int batter) {
	int stat{};
	while (true) {
		std::cout << "Type the number corresponding to the category you wish to view: ";
		std::cin >> stat;
		if (stat > 15 || stat < 3) {
			std::cout << "Try Again. ";
		}
		else {
			return stat;
			break;
		}
	}

}

// prints the batter selector screen and returns the value for the stat
int Batter::statSelectorScreen(int batter) {
	std::cout << 0 << ". " << "First Name" << '\n';
	std::cout << 1 << ". " << "Last Name" << '\n';
	std::cout << 2 << ". " << "Position" << '\n';
	std::cout << 3 << ". " << "Games" << '\n';
	std::cout << 4 << ". " << "At Bats" << '\n';
	std::cout << 5 << ". " << "Runs" << '\n';
	std::cout << 6 << ". " << "Hits" << '\n';
	std::cout << 7 << ". " << "Doubles" << '\n';
	std::cout << 8 << ". " << "Triples" << '\n';
	std::cout << 9 << ". " << "Homeruns" << '\n';
	std::cout << 10 << ". " << "RBIs" << '\n';
	std::cout << 11 << ". " << "Stolen Bases" << '\n';
	std::cout << 12 << ". " << "Walks" << '\n';
	std::cout << 13 << ". " << "SLG" << '\n';
	std::cout << 14 << ". " << "OPS" << '\n';
	std::cout << 15 << ". " << "AVG" << '\n';
	int y{ Batter::statSelectorInput(batter) };
	std::cout << y << std::endl;
	return y;
}
*/

/*
enum class Batter::BatterStat {
	G,
	AB,
	R,
	H,
	DBL,
	TRP,
	HR,
	RBI,
	SB,
	BB,
	SLG,
	OPS,
	AVG,
	WAR
};
*/

Batter::Batter(std::string firstName, std::string lastName, std::string position, std::string bats, std::string throws,
	int games, int atbats, int runs, int hits, int doubles, int triples, int homeruns, int rbis, int stolenbases, 
	int walks, double slugging, double ops, double average, double war) : Player(firstName, lastName, position, bats, throws) {


	stats[0] = games;
	stats[1] = atbats;
	stats[2] = runs;
	stats[3] = hits;
	stats[4] = doubles;
	stats[5] = triples;
	stats[6] = homeruns;
	stats[7] = rbis;
	stats[8] = stolenbases;
	stats[9] = walks;
	stats[10] = slugging;
	stats[11] = ops;
	stats[12] = average;
	stats[13] = war;


	
	statsString[0] = "G";
	statsString[1] = "AB";
	statsString[2] = "R";
	statsString[3] = "H";
	statsString[4] = "2B";
	statsString[5] = "3B";
	statsString[6] = "HR";
	statsString[7] = "RBI";
	statsString[8] = "SB";
	statsString[9] = "BB";
	statsString[10] = "SLG";
	statsString[11] = "OPS";
	statsString[12] = "AVG";
	statsString[13] = "WAR";

	
}

/*
double Batter::statSelector(int stat) {

	return stats[(int) stat];
}

void Batter::statSelectorPrinter(int stat) {
	std::cout << fullName();
	std::cout << " has ";
	std::cout << statSelector(stat);
	std::cout << " stat. ";
}
*/

/*
bool Batter::operator==(Batter obj) {
	for (int i = 0; i < 5; i++) {
		if (this->stringStatSelector(i) != obj.stringStatSelector(i)) {
			return false;
		}
	}
	for (int i = 0; i < 14; i++) {
		if (this->stats[i] != obj.stats[i]) {
			return false;
		}
	}
	return true;
}

bool Batter::operator!=(Batter obj) {
	return !(operator==(obj));
}*/