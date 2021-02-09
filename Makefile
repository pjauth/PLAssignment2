CC = gcc -g -Wall -I../../src
#
# -g debug flag
#
ht:	main.o ht.o 
	$(CC) -o ht main.o ht.o list.o misc.o 

list.o: list.c list.h
	$(CC) -c -O list.c -o list.o

main.o:	main.c ht.h
	$(CC) -c -O main.c -o main.o

ht.o:	ht.c ht.h
	$(CC) -c -O ht.c -o ht.o

clean:
	@-/bin/rm ht *.bak ht.o main.o a.out core xx &> /dev/null

print:
	a2ps --delegate=no -T 4 -q -Avirtual -2 -o xd ht.h ht.c misc.c main.c 

handout:
	a2ps --delegate=no -T 4 -q -Avirtual -2 -o xd main.c ht.h misc.h misc.c 
