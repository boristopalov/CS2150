#Boris topalov, bnt4yb, 3/2/20

C=-clang $(CFLAGS)
CFLAGS=-Wall -g
OBJECTS=linkedlist.o

a.out: $(OBJECTS)
	$(C) $(OBJECTS) -o a.out

linkedlist.o: linkedlist.c


.PHONY: clean

clean:
	-rm -f *.0 *~ a.out
