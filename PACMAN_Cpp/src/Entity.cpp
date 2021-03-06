#include "Entity.h"
Entity::Entity()
{
	x = 0;
	y = 0;
	lives = 1;
	symbol = '%';
}

Entity::Entity(short X, short Y, short L, char S)
{
	x = X;
	y = Y;
	lives = L;
	symbol = S;
}

void Entity::setX(short val)
{
	x = val;
}

void Entity::setY(short val)
{
	y = val;
}

void Entity::setLives(short val)
{
	lives = val;
}

void Entity::setSymbol(char val)
{
	symbol = val;
}

short Entity::getX() const
{
	return x;
}

short Entity::getY() const
{
	return y;
}

short Entity::getLives() const
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
