#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>

int rm0(const char *);

// remove: el archivo ya existe y es regular
// ver syscall unlink
// -std=c11 -Wall -Wextra -g

// Destruye el archivo que se le pase por parametro
// Si no existe no hace nada, library call unlink(2)

int rm0(const char *path_to_rm)
{
    return unlink(path_to_rm);
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        return -1;
    }
    return rm0(argv[1]);
}
