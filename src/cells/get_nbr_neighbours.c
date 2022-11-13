#include "gol.h"

int is_living(char const cell)
{
    return (cell == 'X' ? 1 : 0);
}

int get_nbr_neighbours(char **cells, int x, int y)
{
    int neighbours = 0;

    for (int i = y - 1; i <= y + 1; ++i){
        for (int j = x - 1; j <= x + 1; ++j) {
            if (i == y && j == x) {
                continue;
            }
            if (i >= 0 && j >= 0 && cells[i] && strlen(cells[i]) != 0) {
                neighbours += is_living(cells[i][j]);
            }
        }
    }
    return (neighbours);
}