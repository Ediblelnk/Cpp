#include <iostream>

#include "CLinkedList.h"

using namespace std;

void print_menu();

int main()
{
  CLinkedList<int> clist;

  clist.insert(9);
  clist.insert(10);
  clist.insert(8);
  clist.insert(7);
  clist.insert(9);
  clist.insert(13);
  cout << clist << endl;
  clist.remove(11);
  cout << clist << endl;
  clist.insert(9);
  cout << clist << endl;
  clist.remove(7);
  cout << clist << endl;
}

void print_menu()
{
  cout << ".--------------------." << endl
       << "|        Menu        |" << endl
       << "|--------------------|" << endl
       << "| I - Insert Integer |" << endl
       << "| R - Remove Integer |" << endl
       << "| F - Forward Print  |" << endl
       << "| B - Backward Print |" << endl
       << "| E - Exit           |" << endl
       << "*--------------------*" << endl
       << endl
       << "     Your Choice: ";
}