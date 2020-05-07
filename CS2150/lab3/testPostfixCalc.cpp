/*
Boris Topalov, bnt4yb, 2/1/2020
filename: testPostfixCalc.cpp
This file will test all of our functions in our post fix calculator
to make sure they work properly
*/

#include "postfixCalculator.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  PostfixCalc calc;
  while (cin >> input) {
    if (input == "+") {
      calc.add();
    }
    else if (input == "-") {
      calc.subtract();
    }
    else if (input == "*") {
      calc.mult();
    }
    else if (input == "/") {
      calc.div();
    }
    else if (input == "~") {
      calc.negate();
    }
    else {
      calc.pushNum(stoi(input));
    }
  }
  cout << "Result is: " << calc.getTopNum() << endl;

  return 0;
}
  
