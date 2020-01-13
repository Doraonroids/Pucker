#include "Entity.h"
Entity::Entity()
{
	x = 0;
	y = 0;
	lives = 1;
	symbol = '%';

}

Entity::Entity(int X, int Y, int L, char S)
{
	x = X;
	y = Y;
	lives = L;
	symbol = S;
}

void Entity::setX(int val)
{
	x = val;
}

void Entity::setY(int val)
{
	y = val;
}

void Entity::setLives(int val)
{
	lives = val;
}

void Entity::setSymbol(char val)
{
	symbol = val;
}

int Entity::getX() const
{
	return x;
}

int Entity::getY() const
{
	return y;
}

int Entity::getLives() const
{
	return lives;
}

char Entity::getSymbol() const
{
	return symbol;
}

void Entity::gotoxy(short i, short j) const
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { i, j };
	SetConsoleCursorPosition(hStdout, position);
}
void Entity::display() const {
	gotoxy(x, y);
	std::cout << symbol;
}

void Entity::display(char c) const {
	gotoxy(x, y);
	std::cout << c;
	
}

void Entity::replace() const {
	gotoxy(x, y);
	
}
