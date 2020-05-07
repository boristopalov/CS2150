// Boris Topalov, bnt4yb, 2/26/2020
// Filename: AVLTree.cpp
// Description: AVLTree class implementation
#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
    numberOfNodes = 0;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE

  // Check if tree is empty: if it is then just make a new root node 
  if (root == NULL) {
    root = new AVLNode();
    root->value = x;
    numberOfNodes++;
  }
  // If tree already exists call private insert method
  else {
    insert(root, x);
  }

}

void AVLTree::insert(AVLNode*& node, const string& x) {
  // move down to left node
  if (x < node->value) {
    // check left node 
    if (node->left == NULL) {
      node->left = new AVLNode();
      node->left->value = x;
      numberOfNodes++;
    }
    // call insert on left node if it already exists
    else {
      insert(node->left, x);
    }
  }
  // move down to right node
  else if (x > node->value) {
    // check right node
    if (node->right == NULL) {
      node->right = new AVLNode();
      node->right->value = x;
      numberOfNodes++;
    }
    // cal insert on right node if it already exists
    else {
      insert(node->right, x);
    }
  }
  // updating the height of the tree and balancing the tree if necessary
  updateHeight(node);
  balance(node);
}
  
  

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
    // numberOfNodes--;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  // if tree is empty or value is not in the tree
  if (root == NULL || !find(x)) {
    return "";
  }
  else {
    return root->value + pathTo(root, x);
  }
}


string AVLTree::pathTo(AVLNode* node, const string& x) const {
  if (x == node->value) {
    return "";
  }
  // add the value of the left node to our string and move down to the left subtree recursively
  if (x < node->value) {
    return " " + node->left->value + pathTo(node->left, x);
  }
  // add the value of the right node to our string and move down to the right subtree recursively
  else if (x > node->value) {
    return " " + node->right->value + pathTo(node->right, x);
  }
  return "";
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  // calls private find method
  return find(root, x);
}

bool AVLTree::find(AVLNode* node, const string& x) const {
  // base case 1
  if (node == NULL) {
    return false;
  }
  // base case 2
  else if (x == node->value) {
    return true;
  }
  // move down to left subtree
  else if (x < node->value) {
    return find(node->left, x);
  }
  // move down to right subtree
  else if (x > node->value) {
    return find(node->right, x);
  }
  return false;
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  return numberOfNodes;
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  int leftHeight = height(n->left);
  int rightHeight = height(n->right);
  int balanceFactor = rightHeight - leftHeight;
  
  
  // if balance factor of node is -2
  if (balanceFactor < -1) {

    // balance of the left child
    int leftBalance = height(n->left->right) - height(n->left->left);

    // if sign of balance factor of child nodes are different
    if (leftBalance > 0) {
      n->left = rotateLeft(n->left);
      n = rotateRight(n);
    }

    // if sign of balance factor of children are the same
    else {
      n = rotateRight(n); 
    }
  }
  // if balance factor of node is 2 
  else if (balanceFactor > 1) {
    // balance of the right child 
    int rightBalance = height(n->right->right) - height(n->right->left);
    
    // if sign of balance factor of child nodes are different
    if (rightBalance < 0) {
      n->right = rotateRight(n->right);
      n = rotateLeft(n);
    }
    
    // if sign of balance factor of children are the same
    else {
      n = rotateLeft(n);
    }
  }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  // The parent of the rotated subtree will the the right child of the original subtree
  // so newParent is also the right child of the original parent
  AVLNode* newParent = n->right;

  // pointer to right child of original parent changes to left child of right subtree
  n->right = newParent->left;
  // left subtree of new parent is original parent
  newParent->left = n;
  // update the heights of our new subtrees
  updateHeight(n);
  updateHeight(newParent);
  
  return newParent;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  // the parent of the rotated subtree will be the left child of the original subtree
  // newParent is also the left child of the original parent
  AVLNode* newParent = n->left;
  // pointer to right child of original parent changes to right child of left subtree
  n->left = newParent->right;
  // right subtree of new parent is original parent
  newParent->right = n;
  // update the heights of our new subtrees
  updateHeight(n);
  updateHeight(newParent);
  
  return newParent;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
      numberOfNodes--;
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
	    numberOfNodes++;
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}


// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// recursively updates the height of each node
// used to keep track of balance factors
void AVLTree::updateHeight(AVLNode*& node) {
  if (node != NULL) {
    updateHeight(node->left);
    updateHeight(node->right);
    node->height = max(height(node->left), height(node->right)) + 1;
  }
}
 
		    
		    

		   
		    

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
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

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
