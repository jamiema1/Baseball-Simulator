#include <iostream>
#pragma once

class Player {
public:
	std::string firstName{};
	std::string lastName{};
	std::string position{};
	std::string bats{};
	std::string throws{};

	enum class PlayerStat {
		firstName,
		lastName,
		position,
		bats,
		throws
	};

	// returns the value of a stat for a given batter
	std::string playerStringStatSelector(PlayerStat stat) {
		switch (stat) {
		case PlayerStat::firstName:
			return firstName;
			break;
		case PlayerStat::lastName:
			return lastName;
			break;
		case PlayerStat::position:
			return position;
			break;
		case PlayerStat::bats:
			return bats;
			break;
		case PlayerStat::throws:
			return throws;
			break;
		default:
			return "Invalid Selection";
			break;
		}
	}

	// returns a batters full name with a space inbetween
	std::string playerFullName() {
		std::string str{};
		std::string str1{ str.append(playerStringStatSelector(PlayerStat::firstName)) };
		std::string str2{ str1.append(" ") };
		std::string str3{ str2.append(playerStringStatSelector(PlayerStat::lastName)) };
		return str3;
	}
};