#define MAX_SIZE_BYTES 2 << 13
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
 * Abre, lee y escribe en stdout un archivo mediante su file descriptor
 * Utiliza las library calls open(2), read(2), write(2), close(2)
 */

int cat0(int);

int cat0(int fd)
{
    char *buf[MAX_SIZE_BYTES] = {0};

    ssize_t rd = read(fd, buf, MAX_SIZE_BYTES);
    ssize_t wr = -1;
    if (rd >= 0)
    {
        wr = write(1, buf, MAX_SIZE_BYTES);
        return (wr >= 0 ? close(fd) : wr);
    }
    return rd;
}

int main(int argc, char const *argv[])
{

    if (argc != 2)
        return -1;

    // abro como readonly

    int fd = open(argv[1], O_RDONLY);

    if (fd < 0)
    {
        return fd;
    }

    return cat0(fd);
}
