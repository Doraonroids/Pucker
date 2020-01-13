
#include "map.h"

map::map()
{
	width = 26;
	height = 22;
	length = width * height;
	filename = "map.txt";

}

void map::gotoxy(short i, short j) const
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { i, j };
	SetConsoleCursorPosition(hStdout, position);
}

int map::getWidth() const
{
	return width;
}

int map::getHeight() const
{
	return height;
}
int map::getLength() const
{
	return length;
}
std::string map::getFilename() const
{
	return filename;
}

char map::getmapat(int y, int x) const
{
	if (x * y > length) 
	{
		std::cout << "\n\ngetmapat error\n\n";
	}
	else
	{
		return map_vec[x + width * y];
	}
	
}


void map::setWidth(int w)
{
	width = w;
}

void map::setHeight(int h)
{
	height = h;
}
void map::setFilename(std::string f)
{
	filename = f;
}
void map::setmapat(int y, int x, char c) {
	map_vec[x + width * y] = c;

}
/*
void map::fillWidthHeight()
{
	std::ifstream INF(filename);

	std::string line = "";
	while (std::getline(INF, line)) {
		if (line.substr(0, 1) == "x") {
			std::getline(INF, line);
			setWidth(stoi(line));
		}
		else if (line.substr(0, 1) == "y") {
			std::getline(INF, line);
			setHeight(stoi(line));
		}
		else {
			break;
		}

	}
	INF.close();
	

}
*/
void map::fillmap()
{
	std::ifstream INF(filename);
	std::string line = "";
	while (std::getline(INF, line)) {
		for (int i = 0; i < width; i++) {
			map_vec.push_back(line[i]);
		}
	}
	INF.close();
}

void map::ResetMap()
{
	map_vec.clear();
	gotoxy(0, 0);
	fillmap();
}


void map::ShowMap()
{

	for (int i = 1; i <= length; i++)
	{

		if (i % width == 0)
		{
			std::cout << std::endl;
		}
		else
		{
			std::cout << map_vec[i - 1];
		}

	}
}

