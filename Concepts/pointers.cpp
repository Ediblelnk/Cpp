#include <iostream>
#include <string>
using namespace std;

void byval( int );
void byref( int& );
void byptr( int* );

main() {
 int v;
 int &r= v;
 int *p= &v;

 v= 10;
 cout << "---------------------" << endl;
 cout << "v=10;" << endl;
 cout << "v : " << v << endl;
 cout << "r : " << r << endl;
 cout << "*p: " << *p << endl;
 cout << "p : " << p << endl;
 
 r= 20; 
 cout << "---------------------" << endl;
 cout << "r=20;" << endl;
 cout << "v : " << v << endl;
 cout << "r : " << r << endl;
 cout << "*p: " << *p << endl;
 cout << "p : " << p << endl;
 
 *p= 30; 
 cout << "---------------------" << endl;
 cout << "*p=30;" << endl;
 cout << "v : " << v << endl;
 cout << "r : " << r << endl;
 cout << "*p: " << *p << endl;
 cout << "p : " << p << endl;
 cout << "---------------------" << endl;
 
 // pass variable by value
 cout << "* Pass by value" << endl;
 v=1;
 cout << "v= " << v << ";" << endl;
 cout << "calling byval(v)" << endl;
 byval(v);
 cout << "v after: " << v << endl;
 cout << "---------------------" << endl;

 // pass variable by reference
 cout << "* Pass by reference" << endl;
 v=2;
 cout << "v= " << v << ";" << endl;
 cout << "calling byref(v)" << endl;
 byref(v);
 cout << "v after: " << v << endl;
 cout << "---------------------" << endl;

 // pass variable by pointer
 cout << "* Pass by pointer" << endl;
 v=3;
 cout << "v= " << v << ";" << endl;
 cout << "calling byptr(&v)" << endl;
 byptr(&v);
 cout << "v after: " << v << endl;
 cout << "---------------------" << endl;
}

// pass by value
void byval(int x) {
  x += 1;
  cout << "inside byval: " << x << endl;
}

// pass by reference
void byref(int &x) {
  x += 1;
  cout << "inside byref: " << x << endl;
}

// pass by const reference
void constref(const int &x) {
  // what happens if we uncomment this????
  //x += 1;
  cout << "inside constref: " << x << endl;
}

// pass by pointer
void byptr(int *x) {
  *x += 1;
  cout << "inside byptr: " << *x << endl;
}