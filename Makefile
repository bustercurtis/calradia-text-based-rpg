CC = clang
CFLAGS = -g

all: stbg.c calcCheck.c characterInits.c cont.c fighting.c intro.c print.c level.c
	$(CC) $(CFLAGS) -o calradia stbg.c calcCheck.c characterInits.c cont.c fighting.c intro.c print.c level.c

clean: client server
	rm -f calradia
