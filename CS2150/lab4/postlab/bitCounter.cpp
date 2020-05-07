/*
Boris Topalov, bnt4yb, 2/9/2020
Filename: bitCounter.cpp
Description: counts number of 1s in a binary representation of an integer
*/


#include <iostream>
#include <string>
using namespace std;

int bitCounter(int n) {
  //base case; if n is no longer divisible by 0 return 1 (which would be the remainder)
  if (n / 2 == 0) {
    return 1;
  }
  //If number is divisible by 2, then number of 1s will be the same
  //in n as in n / 2
  else if (n % 2 == 0) {
    return bitCounter(n / 2);
  }
  //If n has a remainder of 1 when dividing by 2, increment the count of 1's
  else {
    return 1 + bitCounter(n / 2);
  }
}



int main(int argc, char **argv) {
  /*
  cout << bitCounter(48) << endl;
  cout << bitCounter(5) << endl;
  cout << bitCounter(918124) << endl;
  */
  
  //If no command-line parameters passed, exit with error message
  if (argc == 1) {
    cout << "No number has been given!" << endl;
    exit(-1);
  }
  //Convert C-string to integer and call it param
  int param = stoi(argv[1]);
  cout << bitCounter(param) << endl;
  
  
  return 0;
}
