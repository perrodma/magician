
output=magician
CC=gcc
CFLAGS=-W -Wall -std=c99
LDFLAGS=
src=src/main.c src/magic.c
obj=$(src:.c=.o)

all: $(output)


$(output): $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)



%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(obj)

distclean: clean
	rm -f $(output)
