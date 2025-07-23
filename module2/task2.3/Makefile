
all: complex_calculator run

complex_calculator: complex_calculator.o main.o
	gcc -o complex_calculator complex_calculator.o main.o 

main.o: main.c
	gcc -c main.c

complex_calculator.o: complex_calculator.c
	gcc -c complex_calculator.c

test_complex_calc.o: test_complex_calc.c
	gcc -c test_complex_calc.c

test: complex_calculator.o test_complex_calc.o
	gcc -o test complex_calculator.o test_complex_calc.o -lcheck -lm -lsubunit
	./test

run:
	./complex_calculator

clean:
	rm -rf test complex_calculator *.o