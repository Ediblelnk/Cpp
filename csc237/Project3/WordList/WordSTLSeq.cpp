#include "WordSTLSeq.h"

using namespace std;

WordSTLSeq::WordSTLSeq(ifstream &inf)
{
  parseIntoList(inf);
}

bool WordSTLSeq::incMatch(string temp)
{
  if (TheWords.empty())
    return false;
  list<WordData>::iterator itr = TheWords.begin();
  do
  {
    if (temp == (*itr).getWord())
    {
      (*itr).incCount();
      return true;
    }
    ++itr;
  } while (itr != TheWords.begin());
  return false;
}

void WordSTLSeq::parseIntoList(ifstream &inf)
{
  // code
  string temp;
  while (inf >> temp)
    if (!incMatch(temp))
      TheWords.push_back(WordData(temp));
  TheWords.sort();
}

void WordSTLSeq::printIteratively()
{
  cout << "+-------------------------+" << endl
       << "|    STL List Iterator    |" << endl
       << "+-------------------------+" << endl
       << "| Word        Occurrences |" << endl
       << "+-------------------------+" << endl;

  if (!TheWords.empty())
  {
    list<WordData>::iterator itr = TheWords.begin();
    do
    {
      cout << *itr << endl;
      ++itr;
    } while (itr != TheWords.end());
  }
  cout << "+-------------------------+" << endl;
}

void WordSTLSeq::printRecursively()
{
  cout << "+-------------------------+" << endl
       << "|   STL List  Recursive   |" << endl
       << "+-------------------------+" << endl
       << "| Word        Occurrences |" << endl
       << "+-------------------------+" << endl;
  list<WordData>::iterator itr = TheWords.begin();
  if (!TheWords.empty())
    printRecursivelyWorker(itr);
  cout << "+-------------------------+" << endl;
}

void WordSTLSeq::printRecursivelyWorker(list<WordData>::iterator &itr)
{
  if (itr != TheWords.end())
  {
    cout << *itr << endl;
    printRecursivelyWorker(++itr);
  }
}