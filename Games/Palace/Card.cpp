#ifndef CARD_CPP
#define CARD_CPP

#include <iostream>
using namespace std;

//DECLARE
class Card {
  public:
    Card(string suit, int rank);
    Card(const Card &C);

    //special operators
    bool operator>=(const Card &C);

    //vars
    string suit; int rank;
};

ostream &operator<<(ostream &output, const Card &C);

//DEFINE
Card::Card(string suit, int rank) {
  this->suit = suit; this->rank = rank;
}

Card::Card(const Card &C) {
  this->suit = C.suit; this->rank = C.rank;
}

bool Card::operator>=(const Card &C) {
  return this->rank >= C.rank;
}

ostream &operator<<(ostream &output, const Card &C) {
  output << "[" << C.rank << " " << C.suit << "]";
  return output;
}

#endif