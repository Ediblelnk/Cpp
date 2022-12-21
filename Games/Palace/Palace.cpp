#include "Card.cpp"
#include "Deck.cpp"
#include <iostream>

using namespace std;

int main() {
  Deck D = Deck(5);

  D += Card("H", 5);
  D += Card("D", 9);
  D += Card("S", 3);
  D += Card("C", 2);

  cout << D << endl;
}