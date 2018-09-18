all: operations.h operations.o main.o
	gcc -o p operations.o main.o	

main.o: operations.h main.c
	gcc -c main.c

operations.o: operations.h operations.c
	gcc -c operations.c

run:
	./p data.txt
clean:
	rm -f *.o

