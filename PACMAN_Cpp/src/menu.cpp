#include "menu.h"

std::string menu::choices0[4] = {
	"1 - Play",
	"2 - Settings",
	"3 - Leaderboard",
	"4 - Quit" };
std::string menu::choices2[6] = {
	"1 - Number of start lives",
	"2 - Number of ghosts",
	"3 - Speed of Pacman",
	"4 - Speed of Ghosts",
	"5 - Change map file name",
	"6 - Go Back" };
menu::menu()
{
	numGhosts = 4;
	speed = 50;
	startLives = 3;
	filename = "leaderboard.txt";
	leaderboard = new std::string[20];
	goToOption(0);
}

void menu::displayChoices0() const
{
	for (auto x : choices0)
		std::cout << x << "\n";
}
void menu::displayChoices0(short curr) const {
	for (auto x : choices0) {
		if (x != choices0[curr])
			std::cout << x << "\n";
	}
}
void menu::displayChoices2() const
{
	for (auto x : choices2)
		std::cout << x << "\n";
}
void menu::goToOption(short in)
{
	clearScreen();
	switch (in) {
		case 0:
			displayChoices0();
			break;
		case 1: 
			gameLoop();
			break;
		case 2: {
			/*std::cout << "SORRY THIS FUNCTION IS CURRENTLY UNAVAILABLE\nTHE SCREEN WILL AUTOMATICALLY RETURN TO THE MAIN MENU\n";
			Sleep(10000);
			goToOption(0);
			*/
			short set;
			displayChoices2();
			std::cin >> set;
			clearScreen();
			switch (set) {
				case 1:

					do {
						
						std::cout << "Please Enter number of start lives [1,6]:\n";
						std::cin >> startLives;
					}while (startLives < 0 && startLives > 7);
					std::cout << "\nLives is set to " << startLives;
					Sleep(3000);
					goToOption(2);
					break;
				case 2:
					do {
						std::cout << "Please Enter number of ghosts [1,4]:\n";
						std::cin >> numGhosts;
					} while (numGhosts < 0 && numGhosts > 5);
					std::cout << "\nGhosts is set to " << numGhosts;
					Sleep(3000);
					clearScreen();
					goToOption(2);
					break;
				case 3:
					do {
						std::cout << "Please Enter speed [30,200]:\n";
						std::cin >> ghostspeed;
					} while (speed < 0 && speed > 5);
					std::cout << "\nOverall speed is set to " << speed;
					Sleep(3000);
					clearScreen();
					goToOption(2);
					break;
				case 4:
					do {
						std::cout << "Please Enter ghost speed [1,4]:\n";
						std::cin >> ghostspeed;
					} while (ghostspeed < 0 && ghostspeed > 5);
					std::cout << "\nGhost speed is set to " << ghostspeed;
					Sleep(3000);
					clearScreen();
					goToOption(2);
					break;
				case 5:
					std::cout << "Please Enter name of leaderboard file:\n";
					std::cin >> filename;
					std::cout << "File name is set to: " << filename;
					Sleep(3000);
					clearScreen();
					goToOption(2);
					break;
				case 6:
					goToOption(0);
					break;
			}
			break; }
		case 3: //display leader board
			displayLeaderBoard();
			displayChoices0();
			break;
		case 4: //quit game
			delete[] leaderboard;
			exit(0);
			break;
	}
}


void menu::clearScreen() const
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { 0, 0 };
	SetConsoleCursorPosition(hStdout, position);
	for (short j = 0; j < 70; j++) {
		for (short i = 0; i < 50; i++) {
			position = { i, j };
			std::cout << " ";
		}
	}
	position = { 0,0 };
	SetConsoleCursorPosition(hStdout, position);
}
void menu::displayLeaderBoard() const {
	std::ifstream INF(filename);
	std::string line = "";
	if (!INF) {
		std::cout << "ERROR " << filename << " COULD NOT BE OPENED!";
	}
	std::cout << "NAME" << std::right << std::setw(12)  << "Score";
	std::cout << "\n================\n";
	for (int i = 0; i < 20; i++) {
		std::getline(INF, line);
		*(leaderboard + i) = line;
		if (i % 2 == 0 && i != 0) {
			std::cout << "\n";
		}
		std::cout << *(leaderboard + i);
		if (i % 2 == 0){
			std::cout << std::right << std::setw(12);
		}
	}
	std::cout << "\n";
	INF.close();
}

void menu::addtoLeaderBoard(short score) const {
	bool test = true;
	std::string name = "", line = "", line2 = "";
	int width = 0, ct = 0;
	do {
		std::cout << "Enter a 4 character name for Leader Board\n";
		std::cin >> name;

	} while (name.length() > 4);
	unsigned int x = 4 - name.length();
	if (name.length() < 4) {
		for (unsigned int k = 0; k < x; k++) {
			name += " ";
		}
	}
	std::fstream F;
	F.open(filename, std::fstream::in | std::fstream::out);
	if (!F) {
		std::cout << "ERROR " << filename << " COULD NOT BE OPENED!";
	}
	while (std::getline(F, line)) {
		*(leaderboard + ct) = line;
		ct++;
	}
	for (int i = 0; i < 20; i += 2) {
		line = *(leaderboard + i);
		line2 = *(leaderboard + i + 1);
		if (score > std::stoi(line2) && test) {
			*(leaderboard + i) = name;
			*(leaderboard + i + 1) = std::to_string(score);
			test = false;
		}
	}
	F.close();
	std::ofstream ofs;
	ofs.open("leaderboard.txt", std::fstream::out | std::fstream::trunc);

	for (int j = 0; j < 20; j++) {
		ofs << *(leaderboard + j) << "\n";
	}

	ofs.close();
}

std::string menu::getFilename() const {
	return filename;
}

void menu::setFilename(std::string f) {
	filename = f;
}

void menu::gameLoop() {
	unsigned long long int frame = 0;
	srand(time(0));
	bool running = true;
	bool running2 = true;

	man player1;

	ghost Blinky;
	ghost Pinky;
	ghost Inky;
	ghost Clyde;
	
	map h;
	h.fillmap();
	player1.setLives(startLives);
	while (running2) {
		running = true;
		h.ShowMap();
		player1.displayLives(h);

		player1.display();//display pacman symbol at his x y
		h.setmapat(player1.getY(), player1.getX(), player1.getSymbol());
		
		switch (numGhosts) {
			case 4: Blinky.display();
			case 3: Pinky.display();
			case 2: Inky.display();
			case 1: Clyde.display();
		}

		while (running)
		{

			player1.display(' ');
			h.setmapat(player1.getY(), player1.getX(), ' ');
			switch (numGhosts) {
				case 4: Blinky.display(h.getmapat(Blinky.getY(), Blinky.getX()));
				case 3: Pinky.display(h.getmapat(Pinky.getY(), Pinky.getX()));
				case 2: Inky.display(h.getmapat(Inky.getY(), Inky.getX()));
				case 1: Clyde.display(h.getmapat(Clyde.getY(), Clyde.getX()));
			}

			if (GetAsyncKeyState(VK_UP)) {
				player1.move_up(h);
			}
			else if (GetAsyncKeyState(VK_DOWN)) {
				player1.move_down(h);
			}
			else if (GetAsyncKeyState(VK_LEFT)) {
				player1.move_left(h);
			}
			else if (GetAsyncKeyState(VK_RIGHT)) {
				player1.move_right(h);
			}
			player1.displayPoints(h);

			if (player1.getDotsate() == 215) {
				clearScreen();
				h.ResetMap();
				player1.reset();
				switch (numGhosts) {
					case 4: Blinky.reset();
					case 3: Pinky.reset();
					case 2: Inky.reset();
					case 1: Clyde.reset();
				}
				player1.setDotsate(0);
				running = false;
				break;
			}

			player1.display();

			if (frame % 3 == 0){
				switch (numGhosts) {
					case 4: Blinky.move_rand(h);
					case 3: Pinky.move_rand(h);
					case 2: Inky.move_rand(h);
					case 1: Clyde.move_rand(h);
				}
			}
			switch (numGhosts) {
				case 4: Blinky.display();
				case 3: Pinky.display();
				case 2: Inky.display();
				case 1: Clyde.display();
			}
			
			//this if statement needs to be changed to something else
			//error when user hits non existing ghosts starting points
			if ((Blinky.getX() == player1.getX() && Blinky.getY() == player1.getY()) 
				|| (Pinky.getX() == player1.getX() && Pinky.getY() == player1.getY()) 
				|| (Inky.getX() == player1.getX() && Inky.getY() == player1.getY()) 
				|| (Clyde.getX() == player1.getX() && Clyde.getY() == player1.getY()) )
			{
				player1.setLives(player1.getLives() - 1);
				Sleep(5000);
				player1.displayLives(h);
				player1.reset();
				switch (numGhosts) {
					case 4: 
						Blinky.display(h.getmapat(Blinky.getY(), Blinky.getX()));
						Blinky.reset();
					case 3: 
						Pinky.display(h.getmapat(Pinky.getY(), Pinky.getX()));
						Pinky.reset();
					case 2: 
						Inky.display(h.getmapat(Inky.getY(), Inky.getX()));
						Inky.reset();
					case 1: 
						Clyde.display(h.getmapat(Clyde.getY(), Clyde.getX()));
						Clyde.reset();
				}
				if (player1.getLives() == 0)
				{
					clearScreen();
					addtoLeaderBoard(player1.getPoints());
					clearScreen();
					displayLeaderBoard();
					Sleep(5000);
					running2 = false;
					running = false;
					break;
				}
			}
			//this sleep sets speed of pacman AND ghosts
			Sleep(speed);
			
			frame++;
		}
	}
	goToOption(0);
}
