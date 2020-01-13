#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

#include "map.h"
class Entity
{
private:
	int x, y, lives;
	char symbol;
public:
	Entity();
	Entity(int, int, int, char);
	void setX(int); //sets x value
	void setY(int); //sets y value
	void setLives(int); //sets lives variable
	void setSymbol(char);   //sets symbol variable
	int getX() const; //returns x value
	int getY() const; //returns y value
	int getLives() const;   //returns lives
	char getSymbol() const; // returns symbol
	void gotoxy(short, short) const;
	void display() const;
	void display(char) const;
	void replace() const;
	

};

