/*
Boris Topalov, bnt4yb, 2/1/2020
Filename: postfixCalculator.h
This is the class declaration for our postfix calculator, which will
be implemented using the C++ STL stack 
*/

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H


#include <cstdlib>
#include "Stack.h"
#include "StackNode.h"
using namespace std;

class PostfixCalc {
 public:
  PostfixCalc();
  ~PostfixCalc();

  //Pops value from the stack, then pops again, and adds those 2 values
  //The result is pushed back onto the stack
  void add();

  //Pops value from stack, then pops again, and then subtracts the
  //value from the first pop from the value from the second pop
  //The result of this is pushed onto the stack
  //i.e. second value popped - first value popped
  void subtract();

  //Pops from the stack, then pops again, and multiplies those two
  //popped values, then pushes the result onto the stack
  void mult();

  //Pops from the stack, then pops again
  //Then divides second value popped by first value popped
  //and pushes the result onto the stack
  void div();

  //Pops from the stack once, then negates that popped value, making
  //it negative (essentially multiplying by -1)
  void negate();

  //Checks to see if the stack is empty 
  bool isEmpty() const;

  //Pushes a number to the top of the stack
  void pushNum(int val);

  //Retrieves the number at the top of the stack
  int getTopNum() const;

 private:
  Stack theStack;
};

#endif
