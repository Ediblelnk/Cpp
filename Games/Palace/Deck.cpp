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
    const Card &operator[](int i) const;
    Card &operator[](int i);
    Deck &operator+=(Card C);

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
  if(this == &D) return *this;

  this->max = D.max;
  this->current = D.current;

  delete this->ptr;
  this->ptr = new Card[D.max];

  for(int i = 0; i < D.current; i++) {(*this)[i] = D[i];}

  return *this;
}

const Card &Deck::operator[](int i) const {
  assert(-1 < i && i < this->current);
  return this->ptr[i];
}

Card &Deck::operator[](int i) {
  assert(-1 < i && i < this->current);
  return this->ptr[i];
}

Deck &Deck::operator+=(Card C) {
  assert(this->current < this->max);
  (*this)[this->current++] = C;

  return *this;
}

ostream &operator<<(ostream &output, const Deck &D) {
  for(int i = 0; i < D.current; i++) {
    output << "+-------+" << "  ";
  } output << endl;

  for(int i = 0; i < D.current; i++) {
    output << "| " << D[i].rank << "   " << D[i].rank << " |" << "  ";
  } output << endl;

  for(int i = 1; i < 2; i++) {
    for(int i = 0; i < D.current; i++) {
      output << "|   " << D[i].suit << "   |" << "  ";
    } output << endl;
  }

  for(int i = 0; i < D.current; i++) {
    output << "| " << D[i].rank << "   " << D[i].rank << " |" << "  ";
  } output << endl;

  for(int i = 0; i < D.current; i++) {
    output << "+-------+" << "  ";
  }

  return output;
}

#endif