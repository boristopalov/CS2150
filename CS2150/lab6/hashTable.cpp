/*
Boris Topalov, bnt4yb, 3/1/2020
Filename: hashTable.cpp
Description: hashTable class implementation
*/

#include <string>
#include <cstddef>
#include <vector>
#include <iostream>
#include <cmath>
#include "hashTable.h"

using namespace std;


hashTable::hashTable() {
  size = 0;
  collisions = 0;
}

hashTable::hashTable(int size) {
  table = vector<list <string> >(size);
  collisions = 0;
}

hashTable::~hashTable() {
}


//simple and hash method for a string for the purposes of this lab
unsigned int hashTable::hash(string s) {
  unsigned int hashVal = 101;
  
  for (int i=0; i<s.length(); i++) {
    hashVal = hashVal * 37 + int(s[i]);
  }

  
  return hashVal % table.size();

}


void hashTable::insert(string s) {
  unsigned int hashVal = hash(s);
  
  //push the string onto the bucket at index = hash(s)
  table[hashVal].push_back(s);
}
  

bool hashTable::find(string s) {
  unsigned int hashVal = hash(s);

  //iterates over the list at a given index of the hash table
  //to search for the string
  std::list<string>::const_iterator i;
  for (i = table[hashVal].begin(); i != table[hashVal].end(); i++) {
    if (*i == s) {
	return true;
      }
  }
  return false;
}
    
  
  


