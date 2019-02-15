#include <ncurses.h>
#include <unistd.h> // usleep()
#include <cstdlib> // rand() and srand()
#include <ctime> // time()
#include <string>
#include <vector>

#include "egg.h"



int main()
{
	setlocale(LC_ALL, "");

	int key;
	char pSkin = 197;
	int pX = 5;
	int pY = 5;



	if (!initscr())
    {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(1);
    }
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    //use_legacy_coding(2); //корректно отображает текст в однобайтовой восьмибитной кодировке CP866
    clear();
    refresh();

    srand(time(0));

	std::vector<Egg> eggs;

	

	while(key != 'q')
	{
		usleep(10000);

		clear();
		box(stdscr, 0,0);

		for (int i = 0; i < eggs.size(); ++i)
		{
			if (eggs[i].timer() != 0)
			{
				eggs[i].printEgg();
			}			
		}
		
		mvaddch(pX, pY, pSkin);
		refresh();

		key = getch();
		if (key == KEY_DOWN && pX < LINES-2)
			pX++;
		if (key == KEY_UP && pX > 1)
			pX--;
		if (key == KEY_RIGHT && pY < COLS-3)
			pY++;
		if (key == KEY_LEFT && pY > 2)
			pY--;
		if (key == ' ') 
		{
			eggs.push_back(Egg(pX,pY)); // Создать яйцо
		}

		// for (int i = 0; i < eggs.size(); ++i)
		// {
		// 	if (eggs[i].timer() = 0)
		// 	{
				
		// 	}			
		// }
	}



	endwin();
	return 0;
}