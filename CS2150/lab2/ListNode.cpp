//Boris Topalov, bnt4yb, 01/26/20
//This is an implementation file for our ListNode class 
#include <iostream>
#include "ListNode.h"
using namespace std;


//Default constructor
ListNode::ListNode() {
  value = 0;
  next = NULL;
  previous = NULL;
  cout << "ListNode constructor" <<  endl;
}
