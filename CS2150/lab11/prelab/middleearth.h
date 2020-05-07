/**
 * @file middleearth.h
 * @brief middle earth class header
 *
 * 
 **/

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

/**
 * @class MiddleEarth
 * @brief Randomly generated Middle Earth world
 *
 * the middle earth class is a 2-D randomly generated world of up to 40 pre-defined cities;
 * each city has a random position in the 2-D world
 **/
class MiddleEarth {
public:
  /**
 * @brief MiddleEarth class constructor.
 *
 * @details Takes in 4 parameters and constructs a random 2-D middle earth world with a given number of cities and world size
 *
 * 
 * @param[in] xsize width of the world to generate
 * @param[in] ysize height of the world to generate
 * @param[in] num_cities the number of cities that will be in the generated world
 * @param[in] seed the random seed. If you specify a given number, the same world will be generated each time
 *
 *
 **/
    MiddleEarth(int xsize, int ysize, int num_cities, int seed);

    /**
 * @brief prints out info on the created world
 *
 * @details Prints out the number of cities available to choose from, how many cities will actually be used,
and info on each the cities being used in the world.
 *
 **/
    void print();

    /**
     * @brief prints tab-seperated table of the distances
     *
     * @details Prints out a table of the distances between each city in the generated world
     **/
    void printTable();
    /**
     * @brief finds the distance between two cities
     *
     * @details Calculates the distance between two inputted cities and returns a float of that distance. This method utilizes a hash map of distances that is contained within our middleearth class.
     *
     * @return returns the distance measured between the two inputted cities
     *
     * @param[in] city1 the first city 
     * @param[in] city2 the second city
     **/
    float getDistance(const string& city1, const string& city2);

    /**
     * @brief Gets the list of cities to travel to.
     *
     * @details This method returns a list of cities in our world that we must travel. The first city
     * is our start city. We must start from there and end up there after travelling to all other cities.
     *
     * @return A vector of strings that represent each city to travel to
     *
     * @param length the number of cities to travel to. This does not include the start/end point,
     * so there will be length+1 entries in the returned vector
     **/
    vector<string> getItinerary(unsigned int length);

private:
    /**
     * the number of cities to generate in our world
     **/
    int num_city_names;
      
    /**
     * width of our world
     **/
    int xsize;
    
    /**
     * height of our world
     **/
    int ysize;
    
    /**
     * a hash map that has cities as keys and their corresponding x-position in our world
     **/
    unordered_map<string, float> xpos;
    
    /**
     * a hash map that has cities as keys and their corresponding y-posiiton in our world
     **/
    unordered_map<string, float> ypos;
    
    /**
     * a vector containing the names of all the cities in middle earth
     **/
    vector<string> cities;
    
    /**
     * a hash map that contains the distance from each to city to all of the other cities.
     * each city is a key, each key's value is a map containing the distance to every other city
     **/
    unordered_map<string, unordered_map<string, float>> distances;

    /**
     * Mersenne-Twister random number engine used to randomly generate our world
     **/
    mt19937 gen; 
};

#endif
