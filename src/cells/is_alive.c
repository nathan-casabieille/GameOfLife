#include "gol.h"

int is_alive(char **cells, int x, int y)
{
    if (cells[y][x] == 'X') {
        return (1);
    }
    return (0);
}