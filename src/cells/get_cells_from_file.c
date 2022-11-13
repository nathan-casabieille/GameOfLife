#include "gol.h"

char **get_cells_from_file(char const *filepath)
{
    char **cells;
    char *file = read_file(filepath);
    
    if (!file) {
        printf("Cannot open file.\n");
        return (NULL);
    }
    cells = str_to_word_array(file, '\n');
    free(file);
    return (cells);
}