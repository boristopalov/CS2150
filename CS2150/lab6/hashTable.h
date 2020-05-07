/*
Boris Topalov, bnt4yb, 3/1/2020
Filename: hashTable.h
Description: hash table class definition
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <string>

using namespace std;


class hashTable {
 public:
  hashTable();
  hashTable(int size);
  ~hashTable();

  //insert a string into the hash table
  void insert(string s);
  //get hash value of the string
  unsigned int hash(string s);
  //look up the string in our hash table;
  bool find(string s);
  int collisions;
 
 private:
  int size;
  //a vector of lists of strings that will be serve as our hash table
  vector<list <string> > table;
};




#endif
