#Boris Topalov, bnt4yb 2/24/2020

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=AVLNode.o AVLTree.o AVLPathTest.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out


AVLNode.o: AVLNode.cpp AVLNode.h

AVLTree.o: AVLTree.cpp AVLTree.h

AVLPathTest.o: AVLPathTest.cpp

.PHONY: clean

clean:
	-rm -f *.o *~ a.out
