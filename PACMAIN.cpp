#include <iostream>
#include "menu.h"

int main()
{
	menu Game;
	int input = 0;
	while (input != 99) {
		Game.goToOption(input);
		std::cin >> input;
	}
	return 0;
}