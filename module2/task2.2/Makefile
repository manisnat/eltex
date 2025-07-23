
all: simple_calculator run

simple_calculator: simple_calculator.c main.c
	gcc simple_calculator.c main.c -o simple_calculator

test: simple_calculator.c test_simple_calc.c
	gcc simple_calculator.c test_simple_calc.c -o test
	./test

run:
	./simple_calculator

clean:
	rm -rf test simple_calculator