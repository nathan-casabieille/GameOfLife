#include "gol.h"

void kill_cell(char **cells, int x, int y)
{
    cells[y][x] = 'O';
}