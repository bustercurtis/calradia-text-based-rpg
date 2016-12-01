CC = clang
CC2 = gcc
CFLAGS = -g -o calradia
FILES = stbg.c calcCheck.c characterInits.c cont.c fighting.c intro.c print.c level.c map.c commands.c items.c mainQuests.c

all: $(FILES)
	$(CC) $(CFLAGS) $(FILES)

alt: $(FILES)
	$(CC2) $(CFLAGS) $(FILES)

clean: calradia
	rm -f calradia
