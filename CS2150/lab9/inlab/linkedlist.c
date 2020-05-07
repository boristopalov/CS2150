/** 
Boris Topalov, bnt4yb, 4/5/20
filename: linkedlist.c
description: simple C implementation of a linked list
**/

#include <stdio.h>
#include <stdlib.h>

// List node structure that has two fields:
// a pointer to the next node and an integer value for the node itself
typedef struct list_node {
  struct list_node* next;
  int val;
} node;


// struct for the list itself
// has 3 fields: head, tail, and length
struct list {
  node* head;
  node* tail;
  unsigned int length;
};


int main() {

  int n; // number of elements to insert into the list
  int x; // will store the value of each element

  // initialize a list 
  struct list* my_list = (struct list*) malloc(sizeof(struct list));
  node* temp;
  
  printf("Enter how many values to input: ");
  scanf("%d", &n);

  // insert at head
  for (int i = 1; i <= n; i++) {
    printf("Enter value %d: ", i);
    scanf("%d/n", &x);    
    node* n = (node*) malloc(sizeof(my_list));
    n->val = x;
   
    if (my_list->head == NULL) {
      my_list->head = n;
    }
    else {
      n->next = my_list->head;
      my_list->head = n;
    }

  }

  // loop that prints out elements
  temp = my_list->head;
  printf("%d\n", temp->val);  
  while (temp->next != NULL) {
    temp = temp->next;
    printf("%d\n", temp->val);
  }
  
      

  // while loop that frees up each node pointer 
  node* toFree = my_list->head;
  while (toFree->next != NULL) {
    free(toFree->next);
    toFree = toFree->next;
  }
  free(my_list->head);
  
  // free up pointer to the list
  free(my_list);
      



 return 0;
}



  
  
