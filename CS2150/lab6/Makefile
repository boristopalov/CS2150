#Boris Topalov, bnt4yb, 3/2/2020

CXX=-clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=hashTable.o timer.o wordPuzzle.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

hashTable.o: hashTable.cpp hashTable.h

timer.o: timer.cpp timer.h

wordPuzzle.o: wordPuzzle.cpp

.PHONY: clean

clean:
	-rm -f *.o *~ a.out
