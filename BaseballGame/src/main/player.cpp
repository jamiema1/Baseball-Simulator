#include "player.h"


/*
enum class PlayerStat {
	firstName,
	lastName,
	position,
	bats,
	throws
};
*/

// constructor
Player::Player(std::string firstName, std::string lastName, std::string position, std::string bats, std::string throws) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->position = position;
	this->bats = bats;
	this->throws = throws;
}


// returns the value of a stat for a given batter
std::string Player::stringStatSelector(int stat) {
	switch (stat) {
	case 0:
		return firstName;
		break;
	case 1:
		return lastName;
		break;
	case 2:
		return position;
		break;
	case 3:
		return bats;
		break;
	case 4:
		return throws;
		break;
	default:
		return "Invalid Selection";
		break;
	}
}

// returns a batters full name with a space inbetween
std::string Player::fullName() {
	std::string str{};
	std::string str1{ str.append(stringStatSelector(0)) };
	std::string str2{ str1.append(" ") };
	std::string str3{ str2.append(stringStatSelector(1)) };
	return str3;
}

double Player::statSelector(int stat) {

	return stats[stat];
}

void Player::statSelectorPrinter(int stat) {
	std::cout << fullName();
	std::cout << " has ";
	std::cout << statSelector(stat);
	std::cout << " ";
	std::cout << statsString[stat] << std::endl;
}