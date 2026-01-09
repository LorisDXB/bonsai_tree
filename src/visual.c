#include "../include/base.h"

void setupNcurses()
{
	puts("setting up curses");
	return;
}

void runBonsai()
{
	int i = 0;
	WINDOW *win;

	initscr();
	refresh();
	while (1) {
		sleep(1);
		mvprintw(LINES - (1 + i), COLS / 2 - 1, ".");
		refresh();
		i++;
	}

	endwin();
	free(win);
	return;
}
