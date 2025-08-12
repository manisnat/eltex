
all: complex_calculator run

complex_calculator: main.c add.so sub.so mult.so divide.so
	gcc main.c -o complex_calculator -ldl
	
add.so: add.c
	mkdir -p libs
	gcc -shared -fPIC -o libs/libadd.so add.c
	
sub.so: sub.c
	gcc -shared -fPIC -o libs/libsub.so sub.c

mult.so: mult.c
	gcc -shared -fPIC -o libs/libmult.so mult.c

divide.so: divide.c
	gcc -shared -fPIC -o libs/libdivide.so divide.c

test: add.so sub.so mult.so divide.so test_complex_calc.c 
	gcc test_complex_calc.c -o test -ldl -lcheck -lm -lsubunit
	./test

run:
	./complex_calculator

clean:
	rm -rf test complex_calculator libs
