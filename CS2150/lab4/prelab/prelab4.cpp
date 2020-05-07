/*
Boris Topalov, bnt4yb, 2/9/2020
Filename: prelab4.cpp
Description: Assignment for pre-lab portion of lab 4
*/

#include <iostream>
#include <climits>
#include <stack>
using namespace std;

//Prints out the size of various primitive C++ types
void sizeOfTest() {
  cout <<"Size of an int: " << sizeof(int) << endl
       <<"Size of an unsigned int: " <<  sizeof(unsigned int) << endl
       <<"Size of a float: " << sizeof(float) << endl
       <<"Size of a double: " << sizeof(double) << endl;
  
  cout <<"Size of a char: " << sizeof(char) << endl
       <<"Size of a bool: " << sizeof(bool) << endl
       <<"Size of an int pointer: " << sizeof(int*) << endl
       <<"Size of a char pointer: " << sizeof(char*) << endl
       <<"Size of a double pointer: " << sizeof(double*) << endl;
  cout << "" << endl;
}

//Takes in an integer and prints out the integer's binary representation
void outputBinary(unsigned int x) {
  stack<int> theStack;
  cout << "Printing " << x << " in binary... " << endl;

  //pushes the remainder of x / 2 onto the stack (always 0 or 1)
  while (x > 0) {
    theStack.push(x % 2);
    x = x / 2;
  }

  //The binary representation is now on the stack
  //Now we are figuring out how many zeros we need in the 32-bit representation
  int zeros = 32 - theStack.size();
  for (int i = zeros; i > 0; i--) {
    theStack.push(0);
  }


  //Now the Stack is zeros followed by the binary representation of x
  while (!theStack.empty()) {
    int digit = theStack.top();
    theStack.pop();
    cout << digit;

    //Prints a space in between every four digits (i.e. every 1/2 byte)
    if (theStack.size() % 4 == 0) {
      cout << " ";
      }
    
  }
  cout << "" << endl;
}
    
//Function that examines what happens when we overflow an integer
void overflow() {
  unsigned int x;
  x = UINT_MAX;
  cout << "" << endl;
  cout << "Max value of an unsigned int x: " << x << endl;
  x += 1;
  cout << "Value of x when we add 1 to max value: " << x << endl;

  cout << "To prevent the program from crashing, our value of x loops back to 0 when trying to set x to greater than its maximum value" << endl;
  
}
 

int main() {
  unsigned int num;
  cout << "Type in a number to convert to binary" << endl;
  cin >> num;
  cout << "" << endl;
  
  sizeOfTest();
  outputBinary(num);
  overflow();

  return 0;
}

