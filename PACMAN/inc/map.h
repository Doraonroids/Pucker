#pragma once

#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class map
{
	private:
		int width, height, length;
		std::string filename;
		std::vector<char> map_vec;
		std::vector<char> orig;
	public:
		
		map();

		void gotoxy(short, short) const;// in order(x,y)
		int getWidth() const;
		int getHeight() const;
		int getLength() const;
		std::string getFilename() const;
		char getmapat(int, int) const; //in order (y,x)
		void setWidth(int);
		void setHeight(int);
		void setFilename(std::string);
		void setmapat(int, int, char);
		//void fillWidthHeight();
		void fillmap();
		void ResetMap();
		void ShowMap();

};

