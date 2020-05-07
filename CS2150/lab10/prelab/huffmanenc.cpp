/**
Boris Topalov, bnt4yb, 4/11/20
filename: huffmanenc.cpp
description: huffman encoder implementation
**/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include "heap.h"
#include "huffNode.h"
using namespace std;

void getPrefixes(huffNode* root, string prefix, unordered_map<string, string> &prefixes) { 
  if (root == NULL) {
    return;
  }

  // We know we are at a leaf node if we are not at a placeholder node
  // insert a pair of the letter and its prefix into our map
  // and write the letter and its prefix to our output file
  if (root->data != "PlaceHolder") {
    string code = root->data + ": " + prefix;
    prefixes.insert(make_pair(root->data, prefix));
    cout << code << endl;    
  }

  //Recurisve call to both child nodes
  getPrefixes(root->left, prefix + "0", prefixes);
  getPrefixes(root->right, prefix + "1", prefixes);

}

void deleteTree(huffNode* root) {
  if (root == NULL) {
    return;
  }

  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}


int main(int argc, char* argv[]) {
  unordered_map<string, int> cmap;
  unordered_map<string, string> prefixmap;
  binary_heap hufftree;
  
  if (argc != 2) {
    cout << "Input file must be specified, and nothing else!" << endl;
    exit(1);
  }

  ifstream file(argv[1]);
  if (!file.is_open()) {
    cout << "File not found!";
    exit(1);
  }

  char c;
  // Determine the frequency of each character in the input file
  // And build a hashmap of each character and its frequency
  while (file.get(c) && int(c) > 31 && int(c) < 127) {
    string s(1, c);
    // If the character is not in our map yet,
    // Add it to our map with frequency 1
    if (cmap.find(s) == cmap.end()) {
      cmap.insert(make_pair(s, 1)); 
    }
    // If the character is already in our map, just increment the frequency
    else {
      cmap[s] += 1;
    }

  }
  // Replace blankspace character with "space"
  if (cmap.find(" ") != cmap.end()) {
    cmap.insert(make_pair("space", cmap[" "]));
    cmap.erase(" ");
  }
  // Clear the status of the file and reset it to the beginning
  // So it can be reread later
  file.clear();
  file.seekg(0);


  // create a huffnode for each character and insert it into the heap
  for (auto i = cmap.begin(); i != cmap.end(); i++) {
    huffNode* node = new huffNode();
    node->data = i->first;
    node->freq = i->second;
    hufftree.insert(node);
  }


  while (hufftree.size() > 1) {
    huffNode* min1 = hufftree.deleteMin();
    huffNode* min2 = hufftree.deleteMin();
  
    huffNode* newNode = new huffNode();
    newNode->freq = min1->freq + min2->freq;
    newNode->data = "PlaceHolder";
    newNode->left = min1;
    newNode->right = min2;
    hufftree.insert(newNode);
  }

  // get the prefixes for each letter
  getPrefixes(hufftree.findMin(), "", prefixmap);
  cout << "----------------------------------------" << endl;
  
  

  
  // count the size of compressed and original files in bits
  float originalsize = 0;
  float compressedsize = 0;
   while (file.get(c) && int(c) > 31 && int(c) < 127) {
     originalsize += 1;
     string s(1, c);
     if (int(c) == 32) {
       cout << prefixmap["space"] << " ";
       compressedsize += prefixmap["space"].length();
     }
     else {
       cout << prefixmap[s] << " ";
       compressedsize += prefixmap[s].length();
     }
   }
   originalsize *= 8;

   
   cout << endl;
   cout << '\n' << "----------------------------------------" << '\n';
   float compratio = originalsize / compressedsize;
   cout << "Compression ratio: " << compratio << endl;
   cout << "The Huffman tree cost " << compressedsize / (originalsize/8)
	 << " bits per character. " << endl;

   deleteTree(hufftree.findMin());
   
  return 0;
}


