#include "gol.h"

int get_cells_height(char **cells)
{
    int y = 0;

    while (cells[y]) {
        y++;
    }
    return (y);
}

char **duplicate_cells(char **cells)
{
    char **new_cells = NULL;
    int height = get_cells_height(cells);
    
    new_cells = malloc(sizeof(char *) * (height + 1));
    if (!new_cells) {
        return (NULL);
    }
    for (int i = 0; i < height; i++) {
        new_cells[i] = strdup(cells[i]);
        if (!new_cells[i]) {
            return (NULL);
        }
    }
    new_cells[height] = NULL;
    return (new_cells);
}