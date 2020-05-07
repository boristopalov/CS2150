#Boris Topalov, bnt4yb, 3/2/2020

CXX=-clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=huffmanenc.o huffNode.o heap.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

heap.o: heap.cpp heap.h

huffNode.o: huffNode.cpp huffNode.h

huffmanenc.o: huffmanenc.cpp

.PHONY: clean

clean:
	-rm -f *.o *~ a.out
