/*
Boris Topalov, bnt4yb, 2/3/2020
Filename: Stack.cpp
Description: Implementation for Stack class
*/


#include <cstddef>
#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack() {
  size = 0;
  theTop = new StackNode();
}


Stack::~Stack() {
  makeEmpty();
  delete theTop;
}
void Stack::push(int n) {
  StackNode* insertedNode = new StackNode();

  insertedNode->value = n;
  insertedNode->next = theTop;
  theTop = insertedNode;
  size++;
}

void Stack::pop() {
  if (!empty()) {
    StackNode* temp = theTop;
    theTop = theTop->next;
    delete temp;
    size--;
  }
}

int Stack::top() const {
  return theTop->value;
}

bool Stack::empty() const {
  return size == 0;
}

void Stack::makeEmpty() {
  while (size > 1) {
    StackNode* temp = theTop->next;
    delete theTop;
    theTop = temp;
    size--;
  }
}
