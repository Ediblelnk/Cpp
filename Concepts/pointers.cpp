#include <iostream>
using namespace std;

int main() {
  int x = 75;
  int* p = new int;
  int& r = x;

  *p = 77;

  cout << "x:  " << x << endl
       << "*p: " << *p << endl
       << "p:  " << p << endl
       << "r:  " << r << endl;
}