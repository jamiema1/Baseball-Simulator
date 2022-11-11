#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <conio.h>
#include <iostream>

int speed{ 1 };
int maxSpeed{ 5 };
int buffer{ 1 }; // when to stop showing text

void resetSpeed() {
	speed = { 1 };
}

void stop() {
	while (true) {
		int move{};
		move = _getch();
		if (move == 's') {
			break;
		}
	}
}

void pause() {
	switch (speed) {
	case 0:
		stop();
		speed++;
		break;
	case 1:
		Sleep(1000);
		break;
	case 2:
		Sleep(500);
		break;
	case 3:
		Sleep(100);
		break;
	case 4:
		//Sleep(10);
		break;
	case 5:
		break;
		//case 6:
		//	break;
	}
}

void speedPrinter() {
	std::cout << "The current speed is: " << speed << "\n\n";
}

void gameSpeed() {
	if (_kbhit()) {
		int key{};
		key = _getch();
		switch (key) {
		case 's':
			speed = 0;
			speedPrinter();
			break;
		case 'd':
			if (speed < maxSpeed) {
				speed++;
			}
			speedPrinter();
			break;
		case 'a':
			if (speed > 0) {
				speed--;
				speedPrinter();
				break;
			}
		default:
			break;
		}
	}
}

bool displayText() {
	if (speed < maxSpeed - buffer) {
		return true;
	}
	else {
		return false;
	}
}

bool isLessThanMaxSpeed() {
	if (speed < maxSpeed) {
		return true;
	}
	else {
		return false;
	}
}