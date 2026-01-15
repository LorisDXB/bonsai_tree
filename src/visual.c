#include "../include/base.h"
#include "../include/lindermayer.h"

/* F = draw forward */

/* X = no geometric meaning */

/* + = 60% right */

/* — = 60% left */

/* [] = Start/end of branch */

void setupNcurses()
{
	puts("setting up curses");
	return;
}

void runBonsai()
{
	int i = 0;
	WINDOW *win;
	char *axiom = strdup("F+F");

	initscr();
	refresh();
	int cursor[2] = {LINES - 1, COLS / 2}; // x y
	while (1) {
		sleep(1); // sleep 1 second between tick
		processSentence(axiom, &cursor);
		axiom = applyRulesToSentence(axiom);
		/* printf("%d\n", cursor[0]); */
		/* mvprintw(cursor[0], cursor[1], "."); */
		refresh();
		i++;
	}

	endwin();
	free(win);
	/* test = applyRulesToSentence(test); */
	/* test = applyRulesToSentence(test); */
	/* test = applyRulesToSentence(test); */
	return;
}
