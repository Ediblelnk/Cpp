/*---Array.h---*/
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array {
  public:
    //constructors
    Array(int=10);
    Array(const Array &);
    //deconstructors
    ~Array();

    //methods
    int size() const;

    //overloads
    const Array &operator=(const Array &);
    bool operator==(const Array &) const;
    bool operator!=(const Array &) const;
    int &operator[](int);
    const int &operator[](int) const;

  private:
    int len; //length
    int *ptr;
};

ostream &operator<<(ostream &, const Array &);
istream &operator>>(istream &, Array &);

#endif
/*---Array.h---*/

/*---Array.cpp---*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <assert.h>
//#include "Array.h"
using namespace std;

//constructor
Array::Array(int len) {
  //no negative arrays
  this->len = (len > 0 ? len : 10);

  //ensure memory allocation
  this->ptr = new int[this->len];
  assert(this->ptr != 0);

  //init all values to 0
  for(int i = 0; i < this->len; i++) {
    this->ptr[i] = 0;
  }
}

//copy constructor
Array::Array(const Array &init): len(init.len) {
  this->ptr = new int[this->len];
  assert(this->ptr != 0);

  //copy each value into array
  for(int i = 0; i < this->len; i++) {
    this->ptr[i] = init.ptr[i];
  }

}

//deconstructor
Array::~Array() {
  delete[] this->ptr;
}

//size property
int Array::size() const {
  return this-> len;
}

const Array &Array::operator=(const Array &right) {
  //check if self assignment
  if(&right != this) {
    //handle possible size different
    if(right.len != this->len) {
      delete[] ptr;
      this->len = right.len;
      this->ptr = new int[len];
      assert(ptr != 0);
    }
    //copy values
    for(int i = 0; i < this->len; i++)
      ptr[i] = right.ptr[i];
  }

  return *this;
}

bool Array::operator==(const Array &right) const {
  //arrays of different size
  if(this->len != right.len) {return false;}

  //loop through all values and ensure they are equal
  for(int i = 0; i < this->len; i++) {
    if(this->ptr[i] != right.ptr[i]) {return false;}
  }

  return true;
}

bool Array::operator!=(const Array &right) const {
  return !(*this == right);
}

//subscript for non-const Arrays
int &Array::operator[](int subscript) {
  //assert subscript is in range
  assert(0 <= subscript && subscript < this->len);

  //return reference so value can be changed
  return this->ptr[subscript];
}

//subscript for const Arrays
const int &Array::operator[](int subscript) const {
  //assert subscript is in range
  assert(0 <= subscript && subscript < this->len);

  //return const reference so value CANT be changed
  return ptr[subscript];
}

ostream &operator<<(ostream &output, const Array &A) {
  output << "[";
  for(int i = 0; i < A.size(); i++) {
    if(i != A.size()-1) {output << A[i] << ", ";}
    else {output << A[i];}
  }
  output << "]";
  return output;
}

istream &operator>>(istream &input, Array &A) {
  cout << "Array(4): ";
  input >> nounitbuf;
  for(int i = 0; i < A.size(); i++) {
    input >> A[i];
  }

  return input;
}
/*---Array.cpp---*/

/*---ArrayRun.cpp---*/
#include <iostream>
//#include "Array.h"
using namespace std;

int main() {
  Array a = Array(10);
  cin >>  a;

  cout << a;
}