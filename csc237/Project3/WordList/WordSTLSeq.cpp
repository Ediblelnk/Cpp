#include "WordSTLSeq.h"

using namespace std;

WordSTLSeq::WordSTLSeq()
{
  // code
}

void WordSTLSeq::parseIntoList(ifstream &inf)
{
  // code
}

void WordSTLSeq::printIteratively()
{
  cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl
       << "Circular List Iterator" << endl
       << "~~~~~~~~~~~~~~~~~~~~~~" << endl
       << "Word       Occurrences" << endl
       << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << TheWords;
}

void WordSTLSeq::printRecursively()
{
  // code
}

void WordSTLSeq::printRecursivelyWorker(list<WordData>::iterator &itr)
{
  // code
}

bool incMatch(string temp)
{
  // code
}

template <typename T>
ostream &operator<<(ostream &out, const list<T> &right)
{
  // code

  return out;
}