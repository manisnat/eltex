all: phone_book run

phone_book: phone_book.o main.o liblist.a
	gcc phone_book.o main.o -L. -llist -o phone_book

phone_book.o: phone_book.c
	gcc -c phone_book.c

main.o: main.c
	gcc -c main.c
	
list.o: list.c
	gcc -c list.c
	
liblist.a: list.o
	ar rc liblist.a list.o

test_phonebook.o: test_phonebook.c
	gcc -c test_phonebook.c 

test: liblist.a test_phonebook.o 
	gcc test_phonebook.o -L. -llist -o test -lcheck -lm -lsubunit
	./test

run: phone_book
	./phone_book

clean:
	rm -rf phone_book test *.o liblist.a
