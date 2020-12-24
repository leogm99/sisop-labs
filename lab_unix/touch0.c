#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
 * touch0 crea un archivo con el nombre que se le pase por parametro si no existe
 * en otro caso no hace nada
 * se llama a open con O_CREAT que en caso de no existir el archivo con permisos de lectura, escritura y ejec
*/

void touch0(const char *);

void touch0(const char *path)
{
    //cambio la mascara de creacion para que pueda ponerle los permisos que quiera al archivo (y que no queden marcados por el proceso)
    umask(0);
    int fd = open(path, O_CREAT | O_WRONLY, __S_IREAD | __S_IWRITE);
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        return -1;
    }
    touch0(argv[1]);
    return 0;
}
