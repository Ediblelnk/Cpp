// File: WordDataList.cpp
// Container of WordData objects
//   Implementations of member functions including inherited pure virtual fns.

#include <sstream>
#include <iostream>
#include "WordDataList.h"

using namespace std;

WordDataList::WordDataList(ifstream &inf)
{
  numWords = 0;
  parseIntoList(inf);
}

bool WordDataList::incMatch(string temp)
{
  for (int i = 0; i < numWords; i++)
  {
    if (temp == TheWords[i].getWord())
    {
      TheWords[i].incCount();
      return true;
    }
  }
  return false;
}

void WordDataList::parseIntoList(ifstream &inf)
{
  string temp;
  while (inf >> temp)
    if (!incMatch(temp) && numWords < 10)
    {
      TheWords[numWords].setWord(temp);
      TheWords[numWords++].setCount(1);
    }
}

// Print the data iteratively
void WordDataList::printIteratively()
{
  cout << "+-------------------------+" << endl
       << "| Object Array  Iterative |" << endl
       << "+-------------------------+" << endl
       << "| Word        Occurrences |" << endl
       << "+-------------------------+" << endl;
  for (int i = 0; i < numWords; i++)
    cout << TheWords[i] << endl;
  cout << "+-------------------------+" << endl;
}

// Print the data recursively
void WordDataList::printRecursivelyWorker(int numWords)
{
  if (numWords < 0)
    return;
  printRecursivelyWorker(numWords - 1);
  cout << TheWords[numWords] << endl;
}

// Call worker function to print the data recursively
void WordDataList::printRecursively()
{
  cout << "+-------------------------+" << endl
       << "| Object Array  Recursive |" << endl
       << "+-------------------------+" << endl
       << "| Word        Occurrences |" << endl
       << "+-------------------------+" << endl;
  printRecursivelyWorker(numWords - 1);
  cout << "+-------------------------+" << endl;
}

// Print the data recursively with a pointer
void WordDataList::printPtrWorker(int numWords)
{
  if (!numWords)
    return;
  printPtrWorker(numWords - 1);
  cout << *(TheWords + (numWords - 1)) << endl;
}

// Call worker function to print the data recursively
void WordDataList::printPtr()
{
  cout << "+-------------------------+" << endl
       << "|  Object Array  Pointer  |" << endl
       << "+-------------------------+" << endl
       << "| Word        Occurrences |" << endl
       << "+-------------------------+" << endl;
  printPtrWorker(numWords);
  cout << "+-------------------------+" << endl;
}
