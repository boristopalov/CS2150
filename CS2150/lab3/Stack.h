/*
Boris Topalov, bnt4yb, 2/3/2020
This is the header file for our stack class, which will be 
implemented using a singly-linked list
*/

#ifndef STACK_H
#define STACK_H

#include "StackNode.h"


class Stack {
 public:
  //Constructor
  Stack();
  
  //Destructor
  ~Stack();

  //Pushes a StackNode with integer value n onto the stack
  void push(int n);

  //Removes the StackNode at the top of the stack
  void pop();

  //Accesses the StackNode at the top of the stack without removing it
  int top() const;

  //Checks to see if the Stack is empty
  bool empty() const;

  //Empties the stack
  void makeEmpty();

 private:
  //Keeps track of how many nodes are in the stack
  int size;
  //Pointer to the top node of the stack
  StackNode* theTop;

  

};

#endif
