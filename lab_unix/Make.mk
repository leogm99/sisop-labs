CC=gcc
CFLAGS=-std=c11 -Wall -Werror -g

rm0:
	$(CC) $(CFLAGS) -o rm0 rm0.c
cat0:
	$(CC) $(CFLAGS) -o cat0 cat0.c
touch0:
	$(CC) $(CFLAGS) -o touch0 touch0.c
stat0:
	$(CC) $(CFLAGS) -o stat0 stat0.c

