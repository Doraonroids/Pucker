#pragma once
#include "Entity.h"
#include "map.h"
#include <time.h>
#include <cstdlib>
class ghost :
	public Entity
{
	private:
		bool edible;
		int lastmove;
	public:
		ghost();
		void move_rand(map&);
		void reset();
		//void move_cont();


};

