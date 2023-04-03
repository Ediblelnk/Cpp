#include <string>
#include "WordCList.h"

using namespace std;

WordCList::WordCList()
{
  // code
}

bool WordCList::incMatch(string temp)
{
  CListItr<WordData> itr(TheWords);
  if (!itr.isEmpty())
  {
    itr.begin();
    do
    {
      if (temp == (*itr).getWord())
      {
        (*itr).incCount();
        return true;
      }
      ++itr;
    } while (!itr.isFirstNode());
  }
  return false;
}

void WordCList::parseIntoList(ifstream &inf)
{
  string temp;
  while (inf >> temp)
    if (!incMatch(temp))
      TheWords.insert(WordData(temp));
}

void WordCList::printIteratively()
{
  cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl
       << "Circular List Iterator" << endl
       << "~~~~~~~~~~~~~~~~~~~~~~" << endl
       << "Word       Occurrences" << endl
       << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << TheWords;
}

void WordCList::printRecursively()
{
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
       << "Circular List Iterator Recursive" << endl
       << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
       << "Word                 Occurrences" << endl
       << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  CListItr<WordData> itr(TheWords);
  printRecursivelyWorker(itr);
}

void WordCList::printRecursivelyWorker(CListItr<WordData> &itr)
{
  // code
}