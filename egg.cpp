#include <ncurses.h>
#include <cstdlib> // rand() and srand()
#include "egg.h"




Egg::Egg(int pX, int pY)
{
	eggSkin = "[:]";
	eggX = pX;
	eggY = pY-1;
	time = 300;
}

Egg::~Egg()
{

}



int Egg::timer()
{
	if (time != 0)
	{
		time--;
	}	
	return time;
}

void Egg::printEgg()
{
	mvaddstr(eggX, eggY, eggSkin.c_str());
}
	





















		// for (int i = 0; i < 50; ++i)
		// {
		// 	timerEgg[i]--;
		// 	if (timerEgg[i] == 1)
		// 	{
		// 		eggX[i] = 0;
		// 		eggY[i] = 0;
		// 	}
		// }}
