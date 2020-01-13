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
	bool works = true;
	bool lastworks = true;
	int direction = 0;
	while (works)
	{

		if (lastworks) {
			direction = lastmove;
		}
		else {
			direction = rand() % 4;
		}
		lastworks = false;
		switch (direction)
		{

		case 0:
			if (m.getmapat(getY() - 1,getX()) != '#')
			{
				setY(getY() - 1);
				lastmove = 0;
				works = false;
				lastworks = true;
			}
			break;
		case 1:
			if (m.getmapat(getY() + 1, getX()) != '#')
			{
				setY(getY() + 1);
				lastmove = 1;
				works = false;
				lastworks = true;
			}
			break;
		case 2:
			if (m.getmapat(getY(), getX()-1) != '#')
			{
				setX(getX() - 1);
				lastmove = 2;
				works = false;
				lastworks = true;
			}
			break;
		case 3:
			if (m.getmapat(getY(), getX()+1) != '#')
			{
				setX(getX() + 1);
				lastmove = 3;
				works = false;
				lastworks = true;
			}
			break;
		}
	}
}