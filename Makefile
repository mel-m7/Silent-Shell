all: main

main: main.o loop.o builtin.o
	g++ main.o loop.o builtin.o -o main
           
main.o: main.c
	g++ -c main.c
	
loop.o: builtin.o
	g++ -c builtin.o
clean:
	rm *.o main
