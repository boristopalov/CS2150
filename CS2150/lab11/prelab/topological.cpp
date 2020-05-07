/**
 * Boris Topalov, bnt4yb, 4/18/20
 * filename: topological.cpp
 * description: topological sort implementation
**/

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main(int argc, char* argv[]) {
 
  
  if (argc != 2) {
    cout << "Must specify one input file as the one and only parameter" << endl;
    exit(1);
  }
 


  ifstream file(argv[1], ifstream::binary);

  if (!file.is_open()) {
    cout << "Unable to open file" << endl;
    exit(2);
  }

  string val1, val2;
  vector<string> vertices;

  // Read in each class and add it to a vector containing each unique class
  file >> val1;
  file >> val2;
  while (val1 != "0" && val2 != "0") {
    if (find(vertices.begin(), vertices.end(), val1) == vertices.end()) {
      vertices.push_back(val1);
    }
    if (find(vertices.begin(), vertices.end(), val2) == vertices.end()) {
	vertices.push_back(val2);
      }

    file >> val1;
    file >> val2;
  }

   int vertnum = vertices.size();

   // 2-d array/matrix
   int graph[vertnum][vertnum];

   // initialize every spot in the graph to 0
   for (int i = 0; i < vertnum; i++) {
     for (int j = 0; j < vertnum; j++) {      
       graph[i][j] = 0;
     }
   }
   // clear the state of the file and reset it to the beginning so it can be read again
   file.clear();
   file.seekg(0);

   
   string v1, v2;
   int xpos; // x-position in our graph (horizontal index)
   int ypos; // y-position in our graph (vertical index)
   //Read in the file again
   file >> v1;
   file >> v2;

   // If we find the string being read in in our vector containing each class, set xpos and ypos
   // We are taking advantage of the way the file is structured
   // v1 will always be a vertex and v2 will be another vertex that v1 is pointing to
   while (v1 != "0" && v2 != "0") {
     for (int i = 0; i < vertnum; i++) {
       if (v1 == vertices[i]) {
	 xpos = i;
       }
       if (v2 == vertices[i]) {
	 ypos = i;
       }
     }
     // this spot is where our edge is so set it to 1 rather than 0
     graph[xpos][ypos] = 1;
   

     file >> v1;
     file >> v2;

     
   }

   unordered_set<string> known; // keep track of each class we've traveled to
   for (int l = 0; l < vertnum; l++) { // first for-loop is so that the subsequent loops run for each class in our vector
     for (int i = 0; i < vertnum; i++) { 
       bool start = true; // boolean variable that keeps track of the starting class (i.e. class with indegree 0)
       for (int j = 0; j < vertnum; j++) { // each column is a class
	 if (graph[j][i] == 1) { // if there is an edge found we now indegree is not 0
	   start = false;	 
	 }            
       }
       if (start) { // if indegree is 0
	 if (known.find(vertices[i]) == known.end() ) { // if we haven't already traveled to this class
	   cout << vertices[i] << " ";
	   known.insert(vertices[i]);
	 }
	 
	 for (int k = 0; k < vertnum; k++) { // get ridge of each edge of a class once we travel to that class
	   graph[i][k] = 0;
	 }
       }
     }
        
   }
   cout << endl;
   return 0;
  
}
  

  
  

 
  
