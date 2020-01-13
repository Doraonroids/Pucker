#include <iostream>
#include <windows.h>
#include <string>
#include "ghost.h"
#include "man.h"
#include "map.h"



int main()
{
	long long int frame = 0;
	srand(time(NULL));
	bool running = true;
	bool running2 = true;
	man player1;
	ghost Blinky;
	map h;
	h.fillmap();
	
	while (running2) {
		h.ShowMap();
		player1.displayLives(h);

		player1.display();//display pacman symbol at his x y
		h.setmapat(player1.getY(), player1.getX(), player1.getSymbol());

		Blinky.display();
		
	
		while (running)
		{
			
			player1.display(' ');
			h.setmapat(player1.getY(), player1.getX(), ' ');
			Blinky.display(h.getmapat(Blinky.getY(), Blinky.getX()));
			if (GetAsyncKeyState(VK_UP)) {
				player1.move_up(h);
			}
			else if (GetAsyncKeyState(VK_DOWN)) {
				player1.move_down(h);
			}
			else if (GetAsyncKeyState(VK_LEFT)) {
				player1.move_left(h);
			} 
			else if (GetAsyncKeyState(VK_RIGHT)) {
				player1.move_right(h);
			}
			
			if (player1.getDotsate() % 192 == 0) {
				h.ResetMap();
				player1.reset();
				Blinky.reset();
				running = false;
			}

			player1.display();

			if (frame % 3 == 0)
			{
				
				Blinky.move_rand(h); 
			}
			Blinky.display(); 
			
			if (Blinky.getX() == player1.getX() && Blinky.getY() == player1.getY())
			{
				player1.setLives(player1.getLives() - 1);
				Sleep(10000);
				player1.displayLives(h);
				player1.reset();
				Blinky.display(h.getmapat(Blinky.getY(), Blinky.getX()));
				Blinky.reset();
				
			
				
				if (player1.getLives() == 0)
				{
					running2 = false;
				
				}
			}
			
			Sleep(50);
			player1.displayPoints(h);
			
			frame++;
		}
	}
	
	return 0;
}

