#ifndef WORDSTLSEQ_H
#define WORDSTLSEQ_H

#include <string>
#include "WordList.h"
#include "WordData.h"
#include <list>

using namespace std;

class WordSTLSeq : public WordList
{
public:
  WordSTLSeq();

  virtual void parseIntoList(ifstream &inf);

  virtual void printIteratively();

  virtual void printRecursively();

private:
  list<WordData> TheWords;

  bool incMatch(string temp);

  void printRecursivelyWorker(list<WordData>::iterator &itr);
};

template <typename T>
ostream &operator<<(ostream &out, const list<T> &right);

#endif