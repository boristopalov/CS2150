/**
Boris Topalov, bnt4yb, 4/12/20
filename: huffmandec.cpp
description: huffman decoder
**/


#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <unordered_map>
#include "huffNode.h"
using namespace std;


// Function to recursively build a huffman tree
void buildTree(huffNode* root, string prefix, unordered_map<string, string> &prefixes) {
  if (root == NULL) {
    cout << "Can't build without a root!" << endl;
    exit(1);
  }

  // If our prefix is not in our prefixes map, we know to create a placeholder node
  if (prefixes.find(prefix) == prefixes.end()) {
    root->data = "PlaceHolder";
    root->left = new huffNode();
    root->right = new huffNode();

    // recurisve call to both child nodes
    // add a 0 or 1 to our prefix depending on if we go to the left or right subtree
    buildTree(root->left, prefix + "0", prefixes);
    buildTree(root->right, prefix + "1", prefixes);  
  }

  // If we find the prefix in our map, we know it will be a leaf node
  else {
    root->data = prefixes[prefix];
  }

}
void deleteTree(huffNode* root) {
  if (root == NULL) {
    return;
  }

  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

    

// main(): we want to use parameters
int main (int argc, char** argv) {
  unordered_map<string, string> prefixes;
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        //cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
	prefixes.insert(make_pair(prefix, character));	
    }


    // Print out each prefix and the letter it corresponds to
    for (auto i = prefixes.begin(); i != prefixes.end(); i++) {
      cout << i->first << ": " << i->second << endl;
    }
    cout << "----------------------------------------" << endl;

    // Create a root node and build a huffman tree based on the prefixes 
    huffNode* root = new huffNode();
    buildTree(root, "", prefixes);
    
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();

    cout << "----------------------------------------" << endl;

    
    // Read each bit and traverse the tree based on each bit
    // If we reach a leaf node print it out
    string bit;
    huffNode* temp = root;
    for (int i = 0; i < allbits.length(); i++) {
      bit = allbits[i];     
      if (bit == "0") {
	temp = temp->left;
      }
      if (bit == "1") {
	temp = temp->right;
      }
      if (temp->data != "PlaceHolder") {
	cout << temp->data;
	temp = root;
      }
    }
    cout << '\n';

    deleteTree(root);

    return 0;

   
}
