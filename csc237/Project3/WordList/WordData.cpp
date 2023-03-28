/***************************************
 *    File:    WordData.cpp            *
 *    Purpose:                         *
 *                                     *
 ***************************************/

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
        return(word);
}

int WordData::getCount() const
{
        return(count);
}

void WordData::incCount(int inc)
{
        count+=inc;
}

ostream &operator<<(ostream& output, const WordData &words)
{
  output<<words.getWord()<<"\t\t"<<words.getCount();
  return output;
}
