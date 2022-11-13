#ifndef __GOL_H_
#define __GOL_H_

#include "utils.h"
#include <ncurses.h>

#define BLACK_PAIR 1
#define WHITE_PAIR 2
#define KEY_ESCAPE 263

int init_window(void);
void gol(char const *filepath);

// cells
void destroy_cells(char **cells);
void display_cells(char **cells);
void new_cell(char **cells, int x, int y);
void kill_cell(char **cells, int x, int y);
char **get_cells_from_file(char const *filepath);
int get_nbr_neighbours(char **cells, int x, int y);
char **duplicate_cells(char **cells);
int is_alive(char **cells, int x, int y);

#endif //__GOL_H_