#pragma once

#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class map{
	private:
		short width, height, length;
		std::string filename;
		std::vector<char> map_vec;
	
	public:
		map();
		void gotoxy(short, short) const;// in order(x,y)
		short getWidth() const;
		short getHeight() const;
		short getLength() const;

		std::string getFilename() const;
		char getmapat(short, short) const; //in order (y,x)
		void setWidth(short);
		void setHeight(short);
		void setFilename(std::string);
		void setmapat(short, short, char);
		void fillmap();
		void ResetMap();
		void ShowMap();
};

