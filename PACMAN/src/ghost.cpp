#include "ghost.h"
ghost::ghost()
{
	lastmove = 0;
	edible = 0;
	setX(12);
	setY(7);
	setLives(1);
	setSymbol('?');
}
void ghost::reset(){
	setX(12);
	setY(7);
}

void ghost::move_rand(map& m)
{
	
	short nextX = 0, nextY = 0;
	short direction = lastmove;
	while (true) {
		switch (direction) {
		case 0: nextY = getY() - 1; nextX = getX();     break;
		case 1: nextY = getY() + 1; nextX = getX();     break;
		case 2: nextY = getY();     nextX = getX() - 1; break;
		case 3: nextY = getY();     nextX = getX() + 1; break;
		}
		if (m.getmapat(nextY, nextX) != '#') {
			setY(nextY);
			setX(nextX);
			lastmove = direction;
			break;
		}
		else {
			direction = rand() % 4;
		}
	}
}