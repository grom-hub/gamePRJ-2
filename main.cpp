#include <ncurses.h>
#include <unistd.h> // usleep()
#include <cstdlib> // rand() and srand()
#include <ctime> // time()



int main()
{
	int key;
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
    clear();
    refresh();

	WINDOW *win1 = newwin(LINES, COLS, 0, 0);



	while(key != 'q')
	{
		usleep(10000);

		wclear(win1);
		box(win1, 0, 0);
		mvwaddch(win1, pX, pY, 'A');
		wrefresh(win1);

		key = getch();
		if (key == KEY_DOWN && pX < LINES-2)
			pX++;
		if (key == KEY_UP && pX > 1)
			pX--;
		if (key == KEY_RIGHT && pY < COLS-2)
			pY++;
		if (key == KEY_LEFT && pY > 1)
			pY--;
	}



	delwin(win1);
	endwin();
	return 0;
}