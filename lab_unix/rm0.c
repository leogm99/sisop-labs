#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int rm0(const char *);

// remove: el archivo ya existe y es regular
// ver syscall unlink
// -std=c11 -Wall -Wextra -g

// Destruye el archivo que se le pase por parametro
// Si no existe no hace nada, library call unlink(2)

// perror escribe a stderr, por eso uso fprintf y no printf
// guardo errno ya que fprintf puede que lo escriba (no estoy seguro)

int rm0(const char *path_to_rm)
{
    if(unlink(path_to_rm) < 0){
        int err = errno;
        fprintf(stderr, "rm: Cannot remove '%s': ", path_to_rm);
        errno = err;
        perror(NULL);
        return errno;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        return -1;
    }
    return rm0(argv[1]);
}
