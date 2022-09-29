/* ORTHOTOPE HEADER FILE */
#ifndef ORTHOTOPE_H
#define ORTHOTOPE_H

#include <string>
using namespace std;

class Orthotope {
  public:
    Orthotope(float w = 0, float x = 0, float y = 0, float z = 0);
    float getHyperVolume();
    void setDimension(char d, float n);
    void getDimensions(float &w, float &x, float &y, float &z);

    //special operators
    bool operator>(Orthotope &O);
    bool operator<=(Orthotope &O);
    bool operator<(Orthotope &O);
    bool operator>=(Orthotope &O);
    Orthotope operator+(Orthotope &O);

  private:
    float W, X, Y, Z;

};

#endif
/* ORTHOTOPE HEADER FILE */

/* ORTHOTOPE CLASS FILE */
using namespace std;

Orthotope::Orthotope(float w, float x, float y, float z) {
  W = w; X = x, Y = y, Z = z;
}

float Orthotope::getHyperVolume() {
  return W * X * Y * Z;
}

void Orthotope::setDimension(char d, float n) {
  switch (d)
  {
  case 'W':
    W = n;
    break;
  
  case 'X':
    X = n;
    break;

  case 'Y':
    Y = n;
    break;

  case 'Z':
    Z = n;
    break;

  default:
    break;
  }
}

void Orthotope::getDimensions(float &w, float &x, float &y, float &z) {
  w = W; x = X; y = Y; z = Z; 
}

bool Orthotope::operator>(Orthotope &O) {
  return getHyperVolume() > O.getHyperVolume();
}

bool Orthotope::operator<=(Orthotope &O) {
  return !(this->operator>(O));
}

bool Orthotope::operator<(Orthotope &O) {
  return getHyperVolume() < O.getHyperVolume();
}

bool Orthotope::operator>=(Orthotope &O) {
  return !(this->operator<(O));
}

Orthotope Orthotope::operator+(Orthotope &O) {
  float w, x, y, z;
  O.getDimensions(w, x, y, z);
  return Orthotope(W+w, X+x, Y+y, Z+z);
}
/* ORTHOTOPE CLASS FILE */

/* DRIVER FILE */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  Orthotope o = Orthotope(4, 4, 4, 4);
  Orthotope o2 = Orthotope(4, 6, 3, 4);
  Orthotope o3 = o + o2;
  float w, x, y, z;
  cout << "Hypervolume of O:  " << o.getHyperVolume() << endl;
  cout << "Hypervolume of O2: " << o2.getHyperVolume() << endl;
  cout << "Smaller Orthotope: " << ((o <= o2) ? o.getHyperVolume() : o2.getHyperVolume()) << endl;
  o3.getDimensions(w, x, y, z);
  cout << "Combined Orthotope: " << setw(3) << w << setw(3) << x << setw(3) << y << setw(3) << z << " area: " << o3.getHyperVolume() << endl;
}
/* DRIVER FILE */