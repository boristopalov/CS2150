// Boris Topalov, bnt4yb, 3/31/20
// Filename: mathfun.cpp
// Description: test file for product and power methods
#include <iostream>
using namespace std;


extern "C" long power(long, long);
extern "C" long product(long, long);



int main() {
  long num1, num2;
  cout << "Enter num 1: ";
  cin >> num1;

  cout << "enter num 2: ";
  cin >> num2;

  cout << num1 << " x " << num2 << " = " << product(num1, num2) << endl;
  cout << num1 << " to the power of " << num2 << " = " << power(num1, num2) << endl;

  return 0;
}

    
