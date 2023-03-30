#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "WordData.h"

using namespace std;

WordData::WordData(string wrd, int cnt)
{
  setWordData(wrd, cnt);
}

void WordData::setWord(string wrd)
{
  word = wrd;
}

void WordData::setCount(int cnt)
{
  count = cnt;
}

void WordData::setWordData(string wrd, int cnt)
{
  setWord(wrd);
  setCount(cnt);
}
string WordData::getWord() const
{
  return (word);
}

int WordData::getCount() const
{
  return (count);
}

void WordData::incCount(int inc)
{
  count += inc;
}

bool WordData::operator<(const WordData &right) const
{
  return (this->getWord() < right.getWord());
}

bool WordData::operator==(const WordData &right) const
{
  return (this->getWord() == right.getWord());
}

bool WordData::operator==(const string &right) const
{
  return (this->getWord() == right);
}

ostream &operator<<(ostream &output, const WordData &words)
{
  output << left << setw(15) << words.getWord() << setw(4) << right << words.getCount();
  return output;
}
