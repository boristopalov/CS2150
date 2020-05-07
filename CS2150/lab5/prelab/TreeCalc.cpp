// Boris Topalov, bnt4yb, 2/23/20
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {

}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
  while (!expressionStack.empty()) {
    cleanTree(expressionStack.top());
    expressionStack.pop();
  }
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
  //Deletes nodes recursively from the tree
  if (tree != NULL) {
    cleanTree(tree->left);
    cleanTree(tree->right);
    delete tree;
  }
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
  TreeNode* newNode = new TreeNode(val);

  //Check if value to insert is an operator
  if (val == "/" || val == "*" || val == "-" || val == "+"){

    //Operator's children are two operands which are on the stack
    newNode->right = expressionStack.top();
    expressionStack.pop();

    newNode->left = expressionStack.top();
    expressionStack.pop();
  }
  expressionStack.push(newNode);
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
  if (tree != NULL) {
    cout << tree->value << " ";
    printPrefix(tree->left);
    printPrefix(tree->right);
  }
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
  if (tree != NULL) {

    // if node is an operator, we print parentheses, then the first digit
    // then the operator, and finally the second digit and close parentheses
    if (tree->value == "+" || tree->value == "-" || tree->value == "*"
	|| tree->value == "/") {
      
      if (tree->left != NULL) {
	cout << "(";
	printInfix(tree->left);
      }
      cout << " " << tree->value << " ";

      if (tree->right != NULL) {
	printInfix(tree->right);
	cout << ")";
      }
    }
    //if not an operator just print the digit normally
    else {
      cout << tree->value;
    }
  }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
  if (tree != NULL) {
    printPostfix(tree->left);
    printPostfix(tree->right);
    cout << tree->value << " ";
  }
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}


// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
    if (tree != NULL) {

      // addition case 
      if (tree->value == "+") {
	return calculate(tree->left) + calculate(tree->right);
      }

      // subtraction case
      else if (tree->value == "-") {
	return calculate(tree->left) - calculate(tree->right);
      }
      // multiplication case
      else if (tree->value == "*") {
	return calculate(tree->left) * calculate(tree->right);
      }
      // division case 
      else if (tree->value == "/") {
	return calculate(tree->left) / calculate(tree->right);
      }
      // digit case
      else {
	return stoi(tree->value);
      }
    }
    cout << "Error: empty tree!" << endl;
    exit(-1);
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
  TreeNode* root = expressionStack.top();
  int result = calculate(root);
  expressionStack.pop();
  cleanTree(root);
  return result;
}
