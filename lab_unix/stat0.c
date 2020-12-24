#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int stat0(const char *path);

int stat0(const char *path)
{
    struct stat buf;
    int ret = stat(path, &buf);
    if (ret >= 0)
    {
        mode_t m = buf.st_mode;
        const char *file_type;
        const char *types[] = {"regular file", "directory", "character device",
                              "block device", "FIFO (named pipe)", "symbolic link", "socket"};
        int modes[] = {S_ISREG(m), S_ISDIR(m), S_ISCHR(m), S_ISBLK(m), S_ISFIFO(m), S_ISLNK(m), S_ISSOCK(m)};
        for(size_t i = 0; i < 7; i++)
            if(modes[i]) file_type = types[i];
        if(!file_type)
            return -1;
        printf("Size: %li\nFile: %s\nType: %s\n", buf.st_size, path, file_type);
    }
    return ret;
}

int main(int argc, const char *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "Wrong number of arguments");
        return -1;
    }
    return stat0(argv[1]);
}
