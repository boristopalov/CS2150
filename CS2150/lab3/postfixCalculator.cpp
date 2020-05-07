/*
Boris Topalov, bnt4yb, 2/1/2020
Filename: postfixCalculator.cpp
Implementation of our post fix calculator using the C++ STL stack
*/

#include <iostream>
#include "postfixCalculator.h"
using namespace std;

PostfixCalc::PostfixCalc() {
}

PostfixCalc::~PostfixCalc() {
}

void PostfixCalc::pushNum(int val) {
  theStack.push(val);
}


void PostfixCalc::add() {
  //Always check to see if the stack is empty before popping
  //Since pop doesn't return anything we need to call top() to actuall use the values
  //This applies to all of our functions 
  if (!isEmpty()) {
      int num1 = theStack.top();
      theStack.pop();
      
      if (!isEmpty()) {
	int num2 = theStack.top();
	theStack.pop();

	int result = num2 + num1;
	pushNum(result);
      }
      else if (isEmpty()) {
	cout << "Error: not enough numbers on the stack!" << endl;
	exit(-1); }
      
  }
  else if (isEmpty()) {
    cout << "Error: not enough numbers on the stack!" << endl;
    exit(-1); }
  
}

void PostfixCalc::subtract() {
  if (!isEmpty()) {
      int num1 = theStack.top();
      theStack.pop();
      
      if (!isEmpty()) {
	int num2 = theStack.top();
	theStack.pop();

	//Ex. 1 2 - is the same as 1 - 2
	//num1 is subtracted from num2; in this case num1 is 2 and
	//num2 is 1 since num1 is popped first and num2 is popped second
	int result = num2 - num1;
        pushNum(result);
      }
      
      else if (isEmpty()) {
	cout << "Error: not enough numbers on the stack!" << endl;
	exit(-1); }
  }
  else if (isEmpty()) {
    cout << "Error: not enough numbers on the stack!" << endl;
    exit(-1); }
  
}

void PostfixCalc::mult() {
  if (!isEmpty()) {
      int num1 = theStack.top();
      theStack.pop();
     
      if (!isEmpty()) {
	int num2 = theStack.top();
	theStack.pop();

	int result = num2 * num1;
	pushNum(result);
      }
      else if (isEmpty()) {
	cout << "Error: not enough numbers on the stack!" << endl;
	exit(-1); }
      
  }
  else if (isEmpty()) {
      cout << "Error: not enough numbers on the stack!" << endl;
      exit(-1); }
}

void PostfixCalc::div() {
  if (!isEmpty()) {
    int num1 = theStack.top();
    theStack.pop();
      
      if (!isEmpty()) {
	int num2 = theStack.top();
	theStack.pop();

	int result = num2 / num1;
        pushNum(result);
      }
      else if (isEmpty()) {
	cout << "Error: not enough numbers on the stack!" << endl;
	exit(-1); }
     
  }
  else if (isEmpty()) {
    cout << "Error: not enough numbers on the stack!" << endl;
    exit(-1); }
  
}

void PostfixCalc::negate() {
  if (!isEmpty()) {
    int num = theStack.top();
    theStack.pop();
    
    int result = num * -1;
    pushNum(result);
  }
  
  else if (isEmpty()) {
    cout << "Error: not enough numbers on the stack!" << endl;
    exit(-1); }

}

bool PostfixCalc::isEmpty() const {
  return theStack.empty();
  }

int PostfixCalc::getTopNum() const {
  return theStack.top();
}

    
  
  

