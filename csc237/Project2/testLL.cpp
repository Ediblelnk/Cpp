#include <iostream>

#include "CLinkedList.h"

using namespace std;

void print_menu();

int main()
{
  CLinkedList<int> clist;
  int input;

  print_menu();

  cin >> input;

  clist.insert(input);
  clist.insert(input + 1);
  clist.insert(input + 2);

  cout << endl
       << clist << endl;
}

void print_menu()
{
  cout << ".----------------------." << endl
       << "|         Menu         |" << endl
       << "|----------------------|" << endl
       << "| I < > Insert Integer |" << endl
       << "| R < > Remove Integer |" << endl
       << "| F < > Forward Print  |" << endl
       << "| B < > Backward Print |" << endl
       << "| E < > Exit           |" << endl
       << "*----------------------*" << endl
       << endl
       << "      Your Choice: ";
}