CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lcheck -lm -lsubunit
NAME = queue

all: $(NAME)

$(NAME): $(NAME).o main.o
	$(CC) $(CFLAGS) -o $(NAME) $(NAME).o main.o
	./$(NAME)

$(NAME).o: $(NAME).c 
	$(CC) $(CFLAGS) -c $(NAME).c

main.o: main.c
	$(CC) $(FLAGS) -c main.c

test_$(NAME).o: test_$(NAME).c
	$(CC) $(CFLAGS) -c test_$(NAME).c

test: test_$(NAME).o $(NAME).o
	$(CC) $(CFLAGS) -o test test_$(NAME).o $(NAME).o $(LDFLAGS)
	./test

clean:
	rm -f *.o test $(NAME)