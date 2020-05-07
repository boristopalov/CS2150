/** Boris Topalov, bnt4yb, 4/4/20
filename: threexinput.cpp
description: cpp file to test threexplusone subroutine
**/

#include <iostream>
#include "timer.h"
using namespace std;

extern "C" int threexplusone(int);

int main() {
  timer t;
  int x, n;
  cout << "Enter a number to apply the Collatz Conjecture to: " << endl;
  cin >> x;
  cout << "How many times should the subroutine run? " << endl;
  cin >> n;

  int res;
  t.start(); //Start the timer
  res = threexplusone(x);
  t.stop(); //Stop the timer
  cout << "Collatz Conjecture was used " << res << " times." << endl;
  cout << "One run took " << t.getTime()*1000000000 << " nanoseconds." << endl;

  
  t.start(); //Start timer
  for (int i = 0; i < n; i++) {
    res = threexplusone(x);
  }
  t.stop(); //Stop timer

  //Default timer is in seconds so we convert to nanoseconds
  cout << n << " runs took average "<< (t.getTime()*1000000000)/n << " nanoseconds." << endl;

  return 0;
}
  
