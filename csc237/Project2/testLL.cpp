#include <iostream>

#include "CLinkedList.h"

using namespace std;

int main()
{
  CLinkedList<int> clist;
  clist.insert(15);

  cout << clist << endl;
}