#include "pitcher.h"
#include <iostream>


/*
enum class Pitcher::PitcherStat {
	G,
	W,
	L,
	IP,
	H,
	R,
	ER,
	BB,
	SO,
	SV,
	WHIP,
	ERA,
	WAR
};*/

Pitcher::Pitcher(std::string firstName, std::string lastName, std::string position, std::string bats, std::string throws,
	int games, int wins, int loses, double inningspitched, int hits, int runs, int earnedruns, int walks,
	int strikeouts, int saves, double whip, double era, double war) : Player(firstName, lastName, position, bats, throws) {

	
	stats[0] = games;
	stats[1] = wins;
	stats[2] = loses;
	stats[3] = inningspitched;
	stats[4] = hits;
	stats[5] = runs;
	stats[6] = earnedruns;
	stats[7] = walks;
	stats[8] = strikeouts;
	stats[9] = saves;
	stats[10] = whip;
	stats[11] = era;
	stats[12] = war;

	
	statsString[0] = "G";
	statsString[1] = "W";
	statsString[2] = "L";
	statsString[3] = "IP";
	statsString[4] = "H";
	statsString[5] = "R";
	statsString[6] = "ER";
	statsString[7] = "BB";
	statsString[8] = "SO";
	statsString[9] = "SV";
	statsString[10] = "WHIP";
	statsString[11] = "ERA";
	statsString[12] = "WAR";
}

/*
double Pitcher::statSelector(int stat) {

	return stats[(int)stat];
}

// prints the stat for the specific batter
void Pitcher::statSelectorPrinter(int stat) {
	std::cout << fullName();
	std::cout << " has ";
	std::cout << statSelector(stat);
	std::cout << " stat. ";
}
*/