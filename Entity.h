#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

#include "map.h"
class Entity {
private:
	short x, y, lives;
	char symbol;
public:
	Entity();
	Entity(short, short, short, char);
	void setX(short); //sets x value
	void setY(short); //sets y value
	void setLives(short); //sets lives variable
	void setSymbol(char);   //sets symbol variable
	short getX() const; //returns x value
	short getY() const; //returns y value
	short getLives() const;   //returns lives
	char getSymbol() const; // returns symbol
	void gotoxy(short, short) const;
	void display() const;
	void display(char) const;
	void replace() const;
};