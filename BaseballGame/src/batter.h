#ifndef BATTER_H
#define BATTER_H
#include <string>
/*
enum class Name {
	firstName,
	lastName,
	position
};
*/

struct Batter {
	std::string firstName{};
	std::string lastName{};
	std::string position{};
	std::string bats{};
	std::string throws{};
	int games{};
	int atbats{};
	int runs{};
	int hits{};
	int doubles{};
	int triples{};
	int homeruns{};
	int rbis{};
	int stolenbases{};
	int walks{};
	double slugging{};
	double ops{};
	double average{};
	double war{};
};


void batterSelectorScreen();
int batterStatSelectorScreen(int stat);
int batterSelectorInput();
int batterStatSelectorInput(int batter);
std::string batterFullName(int batter);
std::string batterStringStatSelector(int stat, int batter);
double batterStatSelector(int stat, int batter);
void batterStatSelectorPrinter(int stat, int batter);
#endif