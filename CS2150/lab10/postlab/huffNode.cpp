/**
Boris Topalov, bnt4yb, 4/11/20
filename: huffNode.cpp
description: huffNode class implementation
**/

#include <cstddef>
#include <string>
#include "huffNode.h"

using namespace std;

huffNode::huffNode() {
  data = "";
  freq = 0;
  left = NULL;
  right = NULL;
}

huffNode::huffNode(string d) {
  data = d;
  freq = 1;
  left = NULL;
  right = NULL;
}

huffNode::~huffNode() {
}
