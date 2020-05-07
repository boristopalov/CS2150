/*
Boris Topalov, bnt4yb, 2/9/2020
Filename: inlab4.cpp
Description: In-lab assignment for lab 4
*/

#include <iostream>
using namespace std;

int main() {
  bool b = false;
  char c = '0';
  int i = 0;
  unsigned int u = 0;
  float f = 0;
  double d = 0.0;
  int* p = NULL;
  char* cp = NULL;
  double* dp = NULL;

  cout << "Value of bool b: " << b << endl
       << "Value of char c: " << c << endl
       << "Value of int i: " << i << endl
       << "Value of unsigned int u: " << u << endl
       << "Value of float f: " << f << endl
       << "Value of double d: " << d << endl
       << "Value of int pointer p: " << p << endl
       << "Value of char pointer cp: " << cp << endl
       << "Value of double pointer dp: " << dp << endl;
  cout << "---------------------------------------------------------" << endl;

  int IntArray[10];
  char CharArray[10];
  int IntArray2D[6][5];
  char CharArray2D[6][5];

  for (int i = 0; i < sizeof(IntArray); i++) {
    IntArray[i] = i+1;
    CharArray[i] = i+2;
  }
  int rows = sizeof(IntArray2D) / sizeof(IntArray2D[0]);
  int columns = sizeof(IntArray2D[0]) / sizeof(int);
  cout << rows << endl << columns << endl;
  
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      IntArray2D[i][j] =(i+1)*j;
      CharArray2D[i][j] = i+j;
    }
  }

  cout << "Int Array: " << IntArray << endl
       << "Char Array: " << CharArray << endl
       << "2D Int Array: " << IntArray2D << endl
       << "2D Char Array: " << CharArray2D << endl;
    
  return 0;
}
