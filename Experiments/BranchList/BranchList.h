#ifndef BRANCHLIST
#define BRANCHLIST

#include <iostream>
#include <cstdlib>
#include <assert.h>

using namespace std;

//prototypes
template <class T> class BranchList;
template <class T> class BranchIter;
template <class T> class Joint;

//JOINT DECLARATION
template <class T>
class Joint {
  private:
    //(de)constructors
    Joint(int branches, T data = T());
    Joint(const Joint &);
    ~Joint();

    //variabels
    int branches;
    T data;
    Joint* ptr;

};

#endif