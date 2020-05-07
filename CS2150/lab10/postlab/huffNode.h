/**
Boris Topalov, bnt4yb, 4/11/20
filename: huffNode.h
description: header file for our huffNode class. These nodes will be inserted into our heap
**/
using namespace std; 
#ifndef HUFFNODE_H
#define HUFFNODE_H

class huffNode {
 public:
  huffNode();
  huffNode(string d);
  ~huffNode();
  string data;
  int freq;
  huffNode* left;
  huffNode* right;

};


#endif
