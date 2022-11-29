#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <assert.h>

using namespace std;

template <class T>
class Stack {
  public:
  Stack(int=10);        //constructor
  Stack(const Stack&);  //copy constructor
  ~Stack();             //deconstructor
  const Stack& operator=(const Stack&);   //operators
  void push(T);                           //methods
  T pop();

  private:
  //vars
  T* ptr;
  int size;
  int place;
};

//constructor
template <class T>
Stack<T>::Stack(int size) {
  //no negative stacks
  this->size = (size > 0 ? size : 10);

  //memory allocation
  this->ptr = new T[this->size];
  assert(this->ptr);

  //empty stack
  this->place = 0;
}

//copy constructor
template <class T>
Stack<T>::Stack(const Stack &S) {
  //copy values over
  this->size = S.size;
  this->place = S.place;

  //deep copy
  this->ptr = new T[size];

  //copy values up to place
  for(int i = 0; i < this->place; i++) {this->ptr[i] = s.ptr[i];}
}

//deconstructor
template <class T>
Stack<T>::~Stack() {
  delete[] this->ptr;
}

//assignment
template <class T>
const Stack<T>& Stack<T>::operator=(const Stack &S) {
  //self assignment
  if(&S == this) {return *this;}


}

#endif