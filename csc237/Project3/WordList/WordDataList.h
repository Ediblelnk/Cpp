// File: WordDataList.h
// Container of WordData objects. 
// Printing can be iterative or recursive. 


#ifndef WORDDATALIST_H
#define WORDDATALIST_H

#include <string>
#include "WordList.h"
#include "WordData.h"

using namespace std;

class WordDataList : public WordList {
public:

  WordDataList();

  // Put a string of strings into the list object
  virtual void parseIntoList(ifstream &inf);

  // Print the data iteratively
  virtual void printIteratively();
  
  // Print the data recursively
  virtual void printRecursively();
  
  // Print the data recursively with a pointer
  virtual void printPtr();

private:
  WordData TheWords[10];
  int numWords;

  // Look for a match and increment if found
  bool incMatch(string temp);
  
  // Function to actually perform recursive print
  void printRecursivelyWorker(int numWords);

  // Function to actually perform recursive print using pointer
  void printPtrWorker(int numWords);


};
  
#endif
