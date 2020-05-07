/*Boris Topalov, bnt4yb, 01/26/20
This is an implementation file for our List class, which can be
used to store elements of type int 
*/

#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;


List::List() { //Default Constructor
  count = 0;
  head = new ListNode();
  tail = new ListNode();
  head->next = tail;
  head->previous = NULL;
  tail->previous = head;
  tail->next = NULL;
}

List::List(const List& source) { //Copy Constructor
  count = 0;
  head = new ListNode();
  head->next = tail;
  tail = new ListNode();
  tail->previous = head;

  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

List::~List() { //Destructor
  makeEmpty();
  delete head;
  delete tail;
}

//Overloading the = operator (used when setting one list equal to another)
List& List::operator=(const List& source) { 
  if (this == &source) {
    return *this;
  }
  else {
    makeEmpty();

    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}


bool List::isEmpty() const {
  return count == 0;

}




ListItr List::first() { //Returns a pointer to the first element in the list
  ListItr i = ListItr(head->next);
  return i;
}

//Goes through the list and removes each element so it's empty
void List::makeEmpty() {
  ListItr *i = new ListItr();
  *i = first();
  while (!isEmpty()) { //Keep removing elements until list is empty
    i->moveForward();
    remove(i->current->previous->value);   
  }
  delete i; //Deallocate memory
  
  //Reset what the head and tail point to (each other since it's an empty list)
  head->next = tail; 
  tail->previous = head;
  count = 0;
}

ListItr List::last() { //Returns a pointer to the last element in the list
  ListItr i = ListItr(tail->previous);
  return i;
}

//Given a position/index in the list, insert a ListNode with the value x into
//the list in the position immediately following the given position
void List::insertAfter(int x, ListItr position) {
  ListNode *insertedNode = new ListNode();
  
  
  insertedNode->value = x;

  //Set the previous and next elements for the node being inserted
  insertedNode->previous = position.current;
  insertedNode->next = position.current->next;

  //Set the neighboring elements next and previous to the node being inserted
  position.current->next->previous = insertedNode;
  position.current->next = insertedNode;
  count++;

}

//Given a position/index in the list, insert a ListNode with the value x into
//the list in the position immediately before the given position
void List::insertBefore(int x, ListItr position) {
  ListNode *insertedNode = new ListNode();
  
  insertedNode->value = x;

  //Set the previous and next elements for the node being inserted
  insertedNode->next = position.current;
  insertedNode->previous = position.current->previous;

  //Set the neighboring elements next and previous to the node being inserted
  position.current->previous->next = insertedNode;
  position.current->previous = insertedNode;
  count++;
}

//Insert a ListNode into the list with value x at the end of the list
//This ListNode becomes the tail of the list
void List::insertAtTail(int x) {
  ListNode *insertedNode = new ListNode();
  
 
  insertedNode->value = x;

  //Set the previous and next elements for the node being inserted
  insertedNode->next = tail;
  insertedNode->previous = tail->previous;

  //Set the neighboring elements next and previous to the node being inserted
  tail->previous->next = insertedNode;
  tail->previous = insertedNode;
  count++;
}

//Looks for the value given in the list and returns a ListItr based on if the value
//is found
ListItr List::find(int x) {
  ListItr *i = new ListItr();
  *i = first();

  //Keep searching for the value until we reach the end of the list
  while (!i->isPastEnd()) {
    if (i->current->value == x) {
      ListItr foundVal = *i;
      delete i;
      return foundVal;
	}
    i->moveForward();
  }

  //Return NULL if the value we are searching for is not in the list
  cout << x << " not found in list" << endl;
  delete i;
  return NULL;
}

//Removes a ListNode with value x
void List::remove(int x) {

  //Only continue if the given value is actually in the list
  if (find(x).current != NULL) {
    ListItr i = find(x);
    
    
    //Making sure the neighboring elements are now pointing to the correct
    //next and previous elements
    i.current->previous->next = i.current->next;
    i.current->next->previous = i.current->previous;

    //store next node so we can access it after deleting the current node
    ListNode *temp = i.current->next;

    //Delete the current node
    delete i.current;

    i.current = temp;
    count--;
    

    
    
  }
  
}


int List::size() const {
  return count;
}

void printList(List& source, bool forward) {
    
  if (forward) {
    ListItr *i = new ListItr(source.first());
    //While we haven't reached the end of the list, keep printing the values
    while (!(i->isPastEnd())) {
      cout << i->retrieve() << endl;
      //Move the iterator forward to be able to retrieve the next value
      i->moveForward();
    }
    delete i;
  }

  //Same thing as above except we start from the end of the list (source.last)
  //and print backwards
  else {
    ListItr *i = new ListItr(source.last());
    while (!(i->isPastBeginning())) {
      cout << i->retrieve() << endl;
      i->moveBackward();
    }
    delete i;
  }
}
    


