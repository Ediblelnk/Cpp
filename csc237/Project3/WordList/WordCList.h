#ifndef WORDCLIST_H
#define WORDCLIST_H

#include <string>
#include "WordList.h"
#include "WordData.h"
#include "CLinkedList.h"

using namespace std;

class WordCList : public WordList
{
public:
  WordCList(ifstream &inf);

  virtual void parseIntoList(ifstream &inf);

  virtual void printIteratively();

  virtual void printRecursively();

private:
  CLinkedList<WordData> TheWords;

  bool incMatch(string temp);

  void printRecursivelyWorker(CListItr<WordData> &itr);
};

#endif