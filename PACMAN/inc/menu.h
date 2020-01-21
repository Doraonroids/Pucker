#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include "ghost.h"
#include "man.h"
#include "map.h"

class menu {
private:
	static std::string choices0[4];
	static std::string choices2[6];
	std::string* leaderboard;
	short lastOption, startLives, numGhosts;
	std::string filename;
	public:
		menu();
		void displayChoices0() const;
		void displayChoices0(short) const;
		void displayChoices2() const;
		void goToOption(short);
		void clearScreen() const;
		void displayLeaderBoard() const;
		void addtoLeaderBoard(short) const;
		std::string getFilename() const;
		void setFilename(std::string);
		void gameLoop(short);
};