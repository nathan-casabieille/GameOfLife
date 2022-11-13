#include "gol.h"

void display_cells(char **cells)
{
    int y = 0;
    int x = 0;
    
    while (cells[y]) {
        while (cells[y][x]) {
            if (is_alive(cells, x, y)) {
                attron(COLOR_PAIR(BLACK_PAIR));
            }
            else {
                attron(COLOR_PAIR(WHITE_PAIR));
            }
            printw("%c", cells[y][x]);
            x++;
        }
        x = 0;
        printw("\n");
        y++;
    }
}