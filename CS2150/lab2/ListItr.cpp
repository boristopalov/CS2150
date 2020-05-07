/*Boris Topalov, bnt4yb, 01/26/20
This is an implementation file for our ListItr class, which is going
to be used to be able to iterate along objects of type List
*/

#include <iostream>
#include "ListItr.h"
#include "ListNode.h"
#include "List.h"
using namespace std;

ListItr::ListItr() {
  current = NULL;
}

ListItr::ListItr(ListNode *theNode) {
  current = theNode;
}

bool ListItr::isPastEnd() const {
  //If the current node is pointing to the tail, the next node is null
  if (current->next == NULL) {
    return true;
  }
 else {
   return false;
 }
}

bool ListItr::isPastBeginning() const {
  //If the current node is pointing to the head, the previous node is null
  if (current->previous == NULL) {
    return true;
  }
  else {
    return false;
  }
}

void ListItr::moveForward() {
  //set the current node to the next node if we are not past the end of the list
  if (!isPastEnd()) {
    current = current->next;
  }
}

void ListItr::moveBackward() {
  //set the current node to the previous node if we are not past the end of the list
  if (!isPastBeginning()) {
    current = current->previous;
  }
}

int ListItr::retrieve() const {
  //fetches the value of the current node
  return current->value;
}
      

