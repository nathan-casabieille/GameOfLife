#ifndef __UTILS_H_
#define __UTILS_H_

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

char *read_file(char const *filepath);
char **str_to_word_array(char const *str, char const separator);

#endif //__UTILS_H_