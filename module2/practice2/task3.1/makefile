CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lcheck -lm -lsubunit

all: chmod test_file run

chmod: chmod.o main.o
	$(CC) $(CFLAGS) -o chmod chmod.o main.o

main.o: main.c 
	$(CC) $(CFLAGS) -c main.c

chmod.o: chmod.c
	$(CC) $(CFLAGS) -c chmod.c

test_chmod.o: test_chmod.c
	$(CC) $(CFLAGS) -c test_chmod.c

test: test_chmod.o chmod.o
	$(CC) $(CFLAGS) -o test test_chmod.o chmod.o $(LDFLAGS)
	./test

test_file:
	touch test_file.txt

run: chmod
	./chmod

clean:
	rm -f chmod test *.txt *.o
