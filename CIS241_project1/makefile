all: functions.h functions.o p1.o
	gcc -o p functions.o p1.o

p1.o: functions.h p1.c
	gcc -c p1.c

functions.o: functions.h functions.c
	gcc -c functions.c

enc: 
	./p e GOODMORNING data cipher

dec: 
	./p d GOODMORNING cipher ddata

test:
	./p e GOODMORNING data cipher
	./p d GOODMORNING cipher ddata
	diff -s data ddata

clean:
	rm -f *.o p cipher ddata

