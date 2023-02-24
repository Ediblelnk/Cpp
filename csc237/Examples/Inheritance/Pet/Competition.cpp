#include <iostream>
#include <iomanip>

#include "AustralianShepherd.h"

using namespace std;

int main() {
  AustralianShepherd* asP = new AustralianShepherd(13, "Sticker");
  AustralianShepherd as(13, "Sticker");
  Dog* dP = new Dog(10, "Paint", "Jack Russel");
  Dog d(10, "Paint", "Jack Russel");

  Dog* dsP = new AustralianShepherd(15, "Zipper");
  Pet* psP = new AustralianShepherd(3, "Blinker");

  dsP->print();
  psP->print();

  asP->print();

  cout << asP->getName() << endl;
  cout << as.getName() << endl;

  as.print();
  dP->print();

  cout << dP->getName() << endl;
  cout << d.getName() << endl;

  d.print();
}