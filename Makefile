CC = clang
CC2 = gcc
CFLAGS = -g

all: stbg.c calcCheck.c characterInits.c cont.c fighting.c intro.c print.c level.c
	$(CC) $(CFLAGS) -o calradia stbg.c calcCheck.c characterInits.c cont.c fighting.c intro.c print.c level.c

alt: stbg.c calcCheck.c characterInits.c cont.c fighting.c intro.c print.c level.c
	$(CC2) $(CFLAGS) -o calradia stbg.c calcCheck.c characterInits.c cont.c fighting.c intro.c print.c level.c

clean: calradia
	rm -f calradia
