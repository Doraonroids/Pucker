#include "man.h"

man::man()
{
	setX(12);
	setY(15);
	setLives(3);
	setSymbol('@');
	points = 0;
	dotsate = 1;
}

void man::setDotsate(short d)
{
	dotsate = d;
}

short man::getDotsate() const
{
	return dotsate;
}



void man::displayPoints(map& m) const {
	gotoxy(m.getWidth() + 1, m.getHeight());
	std::cout << "Points: "<< points;
}

void man::displayLives(map& m)
{
	gotoxy(m.getWidth() + 1, m.getHeight() - 1);
	std::cout << "Lives: " ;
	for (short i = getLives(); i > 0; i--) {
		std::cout << " @ ";
	}
}

void man::reset()
{
	setX(12);
	setY(15);
	
}

void man::move_up(map& m)
{
	if (m.getmapat(getY() - 1,getX()) == '.')
	{
		setY(getY() - 1);
		points++;
		dotsate++;
	}
	else if (m.getmapat(getY() - 1,getX()) == ' ')
	{
		setY(getY() - 1);
	}
	//else
	//{
		//std::cout << "/n/nMove_up() Error/n/n";
		////exit(-1);
	//}
}

void man::move_down(map& m)
{
	if (m.getmapat(getY() + 1,getX()) == '.')
	{
		setY(getY() + 1);
		points++;
		dotsate++;
	}
	else if (m.getmapat(getY() + 1, getX()) == ' ')
	{
		setY(getY() + 1);
	}
	//else
	//{
		//std::cout << "/n/nMove_down() Error/n/n";
		//exit(-1);
	//}
}

void man::move_left(map& m)
{
	if (m.getmapat(getY(), getX() - 1) == '.')
	{
		setX(getX() - 1);
		points++;
		dotsate++;
	}
	else if (m.getmapat(getY(), getX() - 1) == ' ')
	{
		setX(getX() - 1);
	}
	//else
	//{
		//std::cout << "/n/nMove_left() Error/n/n";
		//exit(-1);
	//}
}
void man::move_right(map& m)
{
	if (m.getmapat(getY(),getX() + 1) == '.')
	{
		setX(getX() + 1);
		points++;
		dotsate++;
	}
	else if (m.getmapat(getY(),getX() + 1) == ' ')
	{
		setX(getX() + 1);
	}
	//else
	//{
		//std::cout << "/n/nMove_right() Error/n/n";
		//exit(-1);
	//}
}
