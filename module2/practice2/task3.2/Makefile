CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lcheck -lm -lsubunit

all: ip

ip: ip.o main.o
	$(CC) $(CFLAGS) -o ip ip.o main.o
	./ip 192.168.1.1 255.255.255.0 5

ip.o: ip.c 
	$(CC) $(CFLAGS) -c ip.c

main.o: main.c
	$(CC) $(FLAGS) -c main.c

test_ip.o: test_ip.c
	$(CC) $(CFLAGS) -c test_ip.c

test: test_ip.o ip.o
	$(CC) $(CFLAGS) -o test test_ip.o ip.o $(LDFLAGS)
	./test

clean:
	rm -f *.o test ip