/****************************************************************/
/*   Filename:       WordData.h                                 */
/*   Purpose:        The Only Addition i made to this file was  */
/*                   an overloading of the << operator.         */
/****************************************************************/

#ifndef WORDDATA_H
#define WORDDATA_H
#include <iostream>
#include <string>

using namespace std;

class WordData
{

public:
  // Constructor
  WordData(string wrd = "", int cnt = 1);

  // Sets
  void setWord(string wrd);
  void setCount(int cnt);

  // Set Whole WordData Object
  void setWordData(string, int);

  // Gets
  string getWord() const;
  int getCount() const;

  // Increment
  void incCount(int inc = 1);

  const bool operator<(const WordData &right) const;

private:
  // variables
  string word;
  int count;
};

ostream &operator<<(ostream &output, const WordData &words);

#endif
