/*
Boris Topalov, bnt4yb, 2/3/2020
Filename: StackNode.h
Description: StackNode class definition
*/

#ifndef STACKNODE_H
#define STACKNODE_H


class StackNode {
 public:
  StackNode();

 private:
  int value;
  StackNode* next;

  friend class Stack;

};

#endif
