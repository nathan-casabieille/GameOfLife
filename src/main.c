#include "gol.h"

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Bad arguments: ./gol [file]\n");
        return (1);
    }
    gol(argv[1]);
    return (0);
}