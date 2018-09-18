cipher: cipher.o
	gcc cipher.o -o cipher
cipher.o: cipher.c

test: test1 test2
test1:
	./cipher 1 Hi data.txt data.out
test2:
	./cipher 2 Hi data.out data.bak
