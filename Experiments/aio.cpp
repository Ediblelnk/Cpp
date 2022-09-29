/* MYCLASS HEADER FILE */
#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass {
   public: 
      MyClass();  // default constructor!
      void setValue(int v) ;
      int getValue();

   private:
      int value;
};

#endif
/* MYCLASS HEADER FILE */

/* MYCLASS CLASS FILE */
#include <iostream>
using namespace std;

MyClass::MyClass() {
    cout << "constructing..." << endl;
    value=0;
}

void MyClass::setValue(int v) {
    value= v;
}

int MyClass::getValue() {
    return value;
}
/* MYCLASS CLASS FILE */

/* DRIVER FILE */
#include <iostream>
using namespace std;

int main() {
  MyClass c1;

  c1.setValue(10);
  cout << "Value is: " << c1.getValue() << endl;

  c1.setValue(20);
  cout << "Value is: " << c1.getValue() << endl;
}
/* DRIVER FILE */