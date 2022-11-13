#include "gol.h"

void destroy_cells(char **cells)
{
    int i = 0;

    while (cells[i]) {
        free(cells[i]);
        i++;
    }
    free(cells);
}