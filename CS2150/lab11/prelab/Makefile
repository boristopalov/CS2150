#Boris Topalov, bnt4yb, 3/2/2020

CXX=-clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=topological.o middleearth.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	doxygen
	@echo Successfully compiled and created documentation!

topological.o: topological.cpp

middleearth.o: middleearth.h middleearth.cpp

.PHONY: clean

clean:
	-rm -f *.o *~ a.out
