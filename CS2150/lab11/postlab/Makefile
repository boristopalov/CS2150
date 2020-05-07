#Boris Topalov, bnt4yb, 3/2/2020

CXX=-clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=traveling.o middleearth.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	doxygen
	@echo Successfully compiled and created documentation!

traveling.o: traveling.cpp

middleearth.o: middleearth.h middleearth.cpp

.PHONY: clean

clean:
	-rm -f *.o *~ a.out
