#include "utils.h"

int nbr_of_words(char const *str, char const separator)
{
    int c = 0;
    int i = 0;

    while (str[i] == c) {
        i++;
    }
    while (str[i]) {
        if ((str[i] == separator) && (str[i + 1] != separator)
            && (str[i + 1] && i != 0 && str[i + 1] != 0)) {
            c++;
        }
        i++;
    }
    return (c + 1);
}

char *substr(char const *str, int pos, int n)
{
    int i = 0;
    char *result = malloc(sizeof(char) * (n + 1));

    if (!result) {
        return (NULL);
    }
    while (n > 0) {
        result[i] = str[i + pos];
        i++;
        n--;
    }
    result[i] = '\0';
    return (result);
}

char **str_to_word_array(char const *str, char const separator)
{
    int cmpt = 0;
    int pos = 0;
    int index_tab = 0;
    char **tab = malloc(sizeof(char *) * (nbr_of_words(str, separator) + 2));

    if (!tab) {
        return (NULL);
    }
    for (size_t i = 0; i < strlen(str); i++) {
        cmpt++;
        if (str[i] == separator) {
            tab[index_tab] = substr(str, pos, cmpt - 1);
            pos += cmpt;
            cmpt = 0;
            index_tab++;
        }
    }
    tab[index_tab] = substr(str, pos, cmpt);
    tab[index_tab + 1] = NULL;
    return (tab);
}