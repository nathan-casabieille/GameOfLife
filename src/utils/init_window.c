#include "gol.h"

int init_window(void)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color.\n");
		return (0);
    }
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_WHITE);
	return (1);
}