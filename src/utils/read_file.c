#include "utils.h"

char *read_file(char const *filepath)
{
    char *buffer;
    struct stat st;
    size_t file_size;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        return (NULL);
    }
    stat(filepath, &st);
    file_size = st.st_size;
    buffer = (char *)calloc(sizeof(char), (file_size + 1));
    if (!buffer) {
        return (NULL);
    }
    read(fd, buffer, file_size);
    close(fd);
    return (buffer);
}