all: phone_book run

phone_book: phone_book.o main.o
	gcc -o phone_book phone_book.o main.o

phone_book.o: phone_book.c
	gcc -c phone_book.c

main.o: main.c
	gcc -c main.c

test_phonebook.o: test_phonebook.c
	gcc -c test_phonebook.c 

test: phone_book.o test_phonebook.o
	gcc -o test test_phonebook.o phone_book.o -lcheck -lm -lsubunit
	./test

run: phone_book
	./phone_book

clean:
	rm -rf phone_book *.o