#include "team.h"
#pragma once

Team::Team(std::string name, std::string initials, Batter* batters[20], Batter* battingLineup[9], Batter* fieldingLineup[8],
	Batter* currentBatter, Pitcher* pitchers[20], Pitcher* currentPitcher) {

	this->name = name;
	this->initials = initials;
	for (int i = 0; i < 20; i++) {
		this->batters[i] = batters[i];
		this->pitchers[i] = pitchers[i];
		if (i < 9) {
			this->battingLineup[i] = battingLineup[i];
		}
		if (i < 8) {
			this->fieldingLineup[i] = fieldingLineup[i];
		}
	}
	this->currentBatter = currentBatter;
	this->currentPitcher = currentPitcher;
}



std::string Team::getName() {
	return name;
}

std::string Team::getInitials() {
	return initials;
}

Batter* Team::getBatterInLineup(int index) {
	return battingLineup[index];
}

Batter* Team::getFielderInLineup(int index) {
	return fieldingLineup[index];
}

Batter* Team::getCurrentBatter() {
	return currentBatter;
}

Pitcher* Team::getCurrentPitcher() {
	return currentPitcher;
}

void Team::setCurrentBatter(Batter* batter) {
	currentBatter = batter;
}

int Team::getWins() {
	return wins;
}

void Team::setWins(int wins) {
	this->wins = wins;
}




void Team::lineups(Team* homeTeam, Team* awayTeam) {
	std::cout << "Away: " << awayTeam->getName();
	for (int i = 0; i < (6 - (((int) (awayTeam->getName().length()) + 6) / 8)); i++) {
		std::cout << '\t';
	}
	std::cout << "Home: " << homeTeam->getName() << "\n\n";

	//pitching lineups
	for (int i = 0; i < 1; i++) {
		awayTeam->pitcherLineupPrinter(i);
		homeTeam->pitcherLineupPrinter(i);
		std::cout << std::endl;
	}
	std::cout << std::endl;


	// batting lineups
	for (int i = 0; i < 9; i++) {
		awayTeam->batterLineupPrinter(i);
		homeTeam->batterLineupPrinter(i);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Team::pitcherLineupPrinter(int i) {
	std::cout << i + 1 << ". " << currentPitcher->fullName();
	for (int j = 0; j < (4 - (static_cast<int>(currentPitcher->fullName().length()) + 3) / 8); j++) {
		std::cout << '\t';
	}
	std::cout << currentPitcher->stringStatSelector(2) << "\t\t";
}

void Team::batterLineupPrinter(int i) {
	std::cout << i + 1 << ". " << battingLineup[i]->fullName();
	for (int j = 0; j < (4 - ((int)(battingLineup[i]->fullName().length()) + 3) / 8); j++) {
		std::cout << '\t';
	}
	std::cout << battingLineup[i]->stringStatSelector(2) << "\t\t";
}












void Team::nextBatter() {
	for (int i = 0; i < 9; i++) {
		if (currentBatter == battingLineup[i]) {
			if (i == 8) {
				currentBatter = battingLineup[0];
			}
			else {
				currentBatter = battingLineup[i + 1];
			}
			break;
		}
	}
}

void Team::winsPrinter() {
	std::cout << initials << ": " << wins << '\n';
}