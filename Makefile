CC = gcc

CFLAGS = -Wall -pedantic

LD = gcc

LDFLAGS = 

ttt: main.o draw.o checks.o
	$(LD) $(LDFLAGS) -o ttt main.o draw.o checks.o

main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

draw.o: draw.c
	$(CC) $(CFLAGS) -c -o draw.o draw.c

checks.o: checks.c
	$(CC) $(CFLAGS) -c -o checks.o checks.c

clean:
	rm -rf ./*.o ./ttt

#test: myprog
#	echo Testing myprog
#	./myprog < inputfile
#	echo done.

#shoutout to PLN for providing original makefile which I copied it from
