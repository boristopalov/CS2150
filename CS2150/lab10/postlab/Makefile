#Boris Topalov, bnt4yb, 3/2/2020

CXX=-clang++ $(CXXFLAGS)
CXXFLAGS=-Wall 
DEBUG=-g
OBJECTS=huffmandec.o huffNode.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

huffNode.o: huffNode.cpp huffNode.h

huffmandec.o: huffmandec.cpp

.PHONY: clean

clean:
	-rm -f *.o *~ a.out
