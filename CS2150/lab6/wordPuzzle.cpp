/* Boris Topalov, bnt4yb, 3/1/2020
Filename: wordPuzzle.cpp
Description: word puzzle solver
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "timer.h"
#include "hashTable.h"

using namespace std;

#define LOADFACTOR 0.75
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];


bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global grid[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columns as specified in the input file;
 *             as this is a reference, it is set by the function.
 */
bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;

    // then the columns
    file >> cols;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
        }
    }
    return true;
}

/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static string variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A STATIC string containing the letters in the provided direction.
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */
string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}

//helper method to print out the direction of the word
//different direction is printed for each value of i
string getDirection(int i) {
  if (i == 0) {
    return "N ";
  }

  else if (i == 1) {
	        return "NE";
  }

 else if (i == 2) {
		return "E ";
	      }

	      else if (i == 3) {
	        return "SE";
	      }

	      else if (i == 4) {
                 return "S ";
	      }

	      else if (i == 5) {
		return "SW";
	      }

	      else if (i == 6) {
		return "W ";
	      }

	      else if (i == 7) {
		return "NW";
	      }
  return "";
}
  
int main(int argc, char* argv[]) {
  ifstream file;
  int rows, cols;
  int tableSize = 0;

  //keeps track of how many words we find in our grid
  int wordCount = 0;
  string word;

  //timer to keep track of how long our word search takes
  timer timer;

  //open the dictionary file to count how many words are in it
  file.open(argv[1]);
  if (file.is_open()) {
    while (file >> word) {
      tableSize++;
    }
  }
  file.close();



  //buffer to store the output and print out after timer ends
  list<string> words;
  //set the hash table size to a prime number
  tableSize = getNextPrime(tableSize);
  
  
  //initialize a hash table with a prime size
  hashTable t(tableSize);
  
  //Let's assume that on average each word will have
  //5 prefixes we need to store
  hashTable prefixes(getNextPrime(tableSize*5));
 

  //now we read the file again and insert each word in our hash table
  file.open(argv[1]);
  if (file.is_open()) {
    while (file >> word) {
      t.insert(word);
      //in addition to adding the word to our dictionary t,
      //we add all prefixes of length 3 or greater
      //to a separate hash table called prefixes
      for (int i = 3; i < word.length()+1; i++) {
	prefixes.insert(word.substr(0, i));
	}
    }
  }
  file.close();

  //create the grid/word puzzle
  bool result = readInGrid(argv[2], rows, cols);
  if (!result) {
    cout << "Error reading the file!" << endl;
    return 1;
  }


  //start the timer for our word search
  timer.start();

  //check for 3 letter words or greater in each spot in our grid
  //in each direction
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      for (int i = 0; i < 8; i++) {
	//max length of a word in our dictionary t is 22
	for (int l = 3; l < 22; l++) {
	  word = getWordInGrid(r, c, i, l, rows, cols);

	  //move to the next direction if the word in our grid is less than 3 letters long
	  if (word.length() < 3) {
	    break;
	  }

	  //check if the word is a prefix-- if it isn't we know no further words in that direction will be a word as well
	  //so we move on to the next direction 
	  if (!prefixes.find(word)) {
	    break;
	  }

	  
	  if (l < 21) {
	    // use this to check edge (literally!) cases
	    // an edge case is when our current word is the same as the word with 1 greater length in the grid
	    // they would be the same word because there would be no more letters in that particular direction
	    string nextWord = getWordInGrid(r, c, i, l+1, rows, cols);

	    //move to next direction if we are on the edge and our current word is not found
	    //because all further words in that direction will just be the same word
	    if (word == nextWord && !t.find(word)) {
	      break;
	    }
	  
	    //if we have a word that is on an edge of the grid
	    //skip the rest of the lengths and go to the next direction
	    if (word == nextWord && t.find(word) ) {
	      words.push_back(getDirection(i) + "(" + to_string(r) + ", " + to_string(c) + "):   " + word);
	      wordCount++;
	      break;
	    }  
	  }

	  
	  //non-edge case
	  if (t.find(word)) {
	    words.push_back(getDirection(i) + "(" + to_string(r) + ", " + to_string(c) + "):   " + word);
	    wordCount++;
	  }
	  
	 //lots of brackets...
	}
      }
    }
  }
  timer.stop();
  cout << wordCount << " words found" << endl;
  cout << "Found all words in " << timer.getTime() << " seconds" << endl;
  cout << int(timer.getTime() * 1000) << endl;

  return 0;
}

