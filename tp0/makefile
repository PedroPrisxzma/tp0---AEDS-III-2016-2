CC=gcc
CFLAGS=-g -Wall
DEPS = trie.h leitura.h
OBJ = trie.o main.o leitura.o
%.o: %.c $(DEPS)
				$(CC) -c -o $@ $< $(CFLAGS)

exec: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
