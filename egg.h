#pragma once
#include <string>


class Egg
{
public:
	Egg(int pX, int pY);
	~Egg();

	int timer();
	void printEgg();









private:

	std::string eggSkin;
	int eggX;
	int eggY;
	int eggNum;
	int time;




};