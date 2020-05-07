#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
    numberOfNodes = 0;
}

BinarySearchTree::~BinarySearchTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  if (root == NULL) {
    root = new BinaryNode();
    root->value = x;
    numberOfNodes++;
  }
  //Calls private insert method if we are inserting into an existing tree
  else {
    insert(root, x);
  } 
}

void BinarySearchTree::insert(BinaryNode*& node, const string& x) {
  if (x < node->value) {
    if (node->left == NULL) {
      //Insert at the left child if our value is less than the current node
      // and the left child is null
      node->left = new BinaryNode();
      node->left->value = x;
      numberOfNodes++;
    }
    else {
      // if left child is not null, recursively call insert on left child
      insert(node->left, x);
    }
  }
  
  else if (x > node->value) {
    //insert at right child if our value is greater than the current node
    // and the right child is null
    if (node->right == NULL) {
      node->right = new BinaryNode();
      node->right->value = x;
      numberOfNodes++;
    }
    // recursively call insert if our right child exists
    else {
      insert(node->right, x);
    }
  }
  
}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) {
  //Sets the tree equal to the tree with the value removed
    root = remove(root, x);
    

}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
      numberOfNodes--;
        if (n->left == NULL && n->right == NULL) {
            // no children
            // just delete it :)
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // single child (right)
            // remove current node and return right child node for parent
            BinaryNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // single child (left)
            // remove current node and return left child node for parent
            BinaryNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children
            // replace current node with right child node's minimum, then remove that node
            string value = min(n->right);
            n->value = value;
            n->right = remove(n->right, value);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }
    return n;
}

string BinarySearchTree::pathTo(BinaryNode* node, const string&x) const{
  //if we have reached the node we are looking for, exit the function
  if (x == node->value) {
    return "";
  }
  // if we must travel to the left child to reach the node, add the
  // value of the left child to our path and recursively call pathTo
  // on the left child to continue down our path
  if (x < node->value) {
    return " " + node->left->value + pathTo(node->left, x);
  }
  // add value of right child to our string and continue down our path
  else if (x > node->value) {
    return " " + node->right->value + pathTo(node->right, x);
  }
  return "";
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  // return an empty string if the value we are looking for is not
  // in the tree
  if (root == NULL || !find(x)) {
    return "";
  }
  else {
    // call to private pathTo method
    return root->value + pathTo(root, x);
  }
}

bool BinarySearchTree::find(BinaryNode* node, const string& x) const {
  if (node == NULL) {
    return false;
  }
  else if (x == node->value) {
    return true;
  }
  // travel to left child if value we are looking for is less than current value
  else if (x < node->value) {
    return find(node->left, x);
  }
  // travel to right child if value we are looking for is greater than current value
  else if (x > node->value) {
    return find(node->right, x);
  }
  return false;
}
  

// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    // call to private find method
    return find(root, x);
}
    
// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  return numberOfNodes;
}
  
  
  
 

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}


// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

void BinarySearchTree::printTree() {
    printTree(root, NULL, false);
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}
