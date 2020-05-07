/**
 * @file traveling.cpp
 * 
 * @brief creates a middle earth world and applies the TSP to it.
 *
 * @details This file is meant to create a middle earth world based on command-line parameters and use it as a 
 * map for the traveling salesperson problem. 
 **/
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"
#include <map>

/**
 * @brief computes total distances for a given route of cities.
 *
 * @details Given a vector of cities to travel to, this function will iteratively compute the distance between each city
 * and return the total distance between all cities
 *
 *
 * @return total distance traveled
 *
 * @param[in] me middleearth object passed in; will have its class's computeDistance method called on each pair of cities
 * @param[in] start the start city
 * @param[in] dests the vector of cities to travel to
 **/
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
/**
 * @brief prints out the route.
 *
 * @details This function goes through a given vector of cities to travel to and prints out the route to take. Iterates through the vector and prints out each city
 * 
 *
 * @param[in] start the start city
 * @param[in] dests the vector of cities to travel to
 **/
void printRoute(const string& start, const vector<string>& dests);
/**
 * @brief stores the route in a string
 *
 * @details Creates a string of the route. If we were to print it out, it would be the same as calling printRoute.
 * This function is used to keep track of each possible route
 *
 * @param[in] start the start city
 * @param[in] dests the vector of cities to travel to
 **/
string getRoute(const string& start, const vector<string>& dests);
  


int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE

    // map to store the distance of each route
    map<float, string> paths;
    string start = dests[0];
     

    // sort all but the start city
    sort(next(dests.begin(),1),  dests.end());
    
    // Edge case if there is only 1 city to visit
    if (cities_to_visit == 1) { // next_permutation will not work in this case so we must account for that
      string s = getRoute(start, dests);
      float d = computeDistance(me, start, dests);
      paths[d] = s;
    }

    // store each route and the total distance of that route in a map
    while(next_permutation(next(dests.begin(), 1), dests.end())) {
      string s = getRoute(start, dests);
      float d = computeDistance(me, start, dests);
      paths[d] = s;
      }

    // the first value in the map is the path of least distance
    cout << "Minimum path has distance " << paths.begin()->first << ": " << paths.begin()->second << endl;
    
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth &me, const string& start, vector<string> dests) {
  float total = 0;
  total += me.getDistance(start, dests[1]); //Compute distance b/w start and first city 
  for (int i = 1; i < dests.size()-1; i++) {
    total += me.getDistance(dests[i], dests[i+1]);
  }
  total += me.getDistance(dests[dests.size()-1], start);
  return total;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    cout << start;
    
    for (int i = 1; i < dests.size(); i++) {
      cout << " -> " <<  dests[i];
  }
    cout << " -> " << start << endl;
}

string getRoute(const string& start, const vector<string>& dests) {
  string s = start;
 
   for (int i = 1; i < dests.size(); i++) {
      s = s + " -> " + dests[i];
  }
    s = s + " -> " + start;
    return s;
}

