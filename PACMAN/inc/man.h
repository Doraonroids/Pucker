#pragma once
#include "Entity.h"
#include "map.h"
class man :
	public Entity
{
	
	private:
		short points, dotsate;
	public:
		man();
		void setDotsate(short);
		short getDotsate() const;
		
		void displayPoints(map&) const;
		void displayLives(map&);
		void reset();
		void move_up(map&);
		void move_down(map&);
		void move_left(map&);
		void move_right(map&);
};

