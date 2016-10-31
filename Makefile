CC = clang
CC2 = gcc
CFLAGS = -g

all: stbg.c calcCheck.c characterInits.c cont.c fighting.c intro.c print.c level.c map.c
	$(CC) $(CFLAGS) -o calradia stbg.c calcCheck.c characterInits.c cont.c fighting.c intro.c print.c level.c map.c

alt: stbg.c calcCheck.c characterInits.c cont.c fighting.c intro.c print.c level.c map.c
	$(CC2) $(CFLAGS) -o calradia stbg.c calcCheck.c characterInits.c cont.c fighting.c intro.c print.c level.c map.c

clean: calradia
	rm -f calradia
