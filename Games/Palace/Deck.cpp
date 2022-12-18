#ifndef DECK_CPP
#define DECK_CPP

#include <iostream>
#include <assert.h>
#include "Card.cpp"
using namespace std;

//DECLARE
class Deck {
  public:
    Deck(int max);
    Deck(const Deck &D);

    //operators
    const Deck operator=(const Deck &D);
    Card operator[](int i) const;

    //vars
    Card *ptr;
    int max;
    int current;
};

ostream &operator<<(ostream &output, const Deck &D);

//DEFINE
Deck::Deck(int max) {
  this->max = max; this->current = 0;
  this->ptr = new Card[max];
}

Deck::Deck(const Deck &D) {
  this->max = D.max;
  this->current = D.current;
  this->ptr = new Card[D.max];

  for(int i = 0; i < D.current; i++) {(*this)[i] = D[i];}
}

const Deck Deck::operator=(const Deck &D) {
  this->max = D.max;
  this->current = D.current;
  this->ptr = new Card[D.max];

  for(int i = 0; i < D.current; i++) {(*this)[i] = D[i];}

  return *this;
}

Card Deck::operator[](int i) const {
  assert(0 < i && i < this->current);
  return this->ptr[i];
}

ostream &operator<<(ostream &output, const Deck &D) {
  output << "<";
  for(int i = 0; i < D.current; i++) {output << D[i];}
  output << ">";
  return output;
}

#endif