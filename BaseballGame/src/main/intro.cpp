#include "intro.h"
#include "game.h"

#include <conio.h>
#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void run() {
	startMenu();
	int mode{ startMenuSelector() };
	std::cout << mode;
	//modeSelector(mode);

	new Game();
}

void startMenu() {
	std::cout << "Welcome to 'Baseball Game Simulator'\n\n";
	std::cout << "Options:\n";
	std::cout << "1. Season Simulation\n";
	std::cout << "2. Head to Head\n";
	std::cout << "3. Draft Mode\n";
	std::cout << '\n';
}

int startMenuSelector() {
	while (true) {
		int key{};
		key = _getch();
		switch (key) {
		case '1':
			return 1;
			break;
		case '2':
			return 2;
			break;
		case '3':
			return 3;
			break;
		default:
			return 0;
			break;
		}
	}
}