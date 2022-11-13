#include "gol.h"

char **new_generation(char **cells)
{
    int x = 0;
    int y = 0;
    int nbr_neighbours;
    char **new_gen = duplicate_cells(cells);

    if (!new_gen) {
        return (NULL);
    }
    while (cells[y]) {
        while (cells[y][x]) {
            nbr_neighbours = get_nbr_neighbours(cells, x, y);
            if (is_alive(cells, x, y)) {
                if (nbr_neighbours < 2 || nbr_neighbours > 3) {
                    kill_cell(new_gen, x, y);
                }
            }
            else {
                if (nbr_neighbours == 3) {
                    new_cell(new_gen, x, y);
                }
            }
            x++;
        }
        x = 0;
        y++;
    }
    return (new_gen);
}

void gol(char const *filepath)
{
    char **new_gen = NULL;
    char **cells = get_cells_from_file(filepath);

    if (cells) {
        if (init_window()) {
            while (getch() != KEY_ESCAPE) {
                new_gen = new_generation(cells);
                clear();
                display_cells(new_gen);
                refresh();
                destroy_cells(cells);
                cells = new_gen;
                sleep(1);
            }
            destroy_cells(new_gen);
            endwin();
        }
    }
}