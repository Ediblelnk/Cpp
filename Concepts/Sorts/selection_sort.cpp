#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

void print_array(int*, int);
void assign_array(int*, int, int, int);

int main() {
  srand(time(NULL));
  int rand();

  int length = 10;
  int arr[length];
  const int MAX = 100;
  const int OFFSET = 0;

  for (int j = 0; j < length; j++) {
    arr[j] = rand() % MAX + OFFSET;
  }
}

void print_array(int *a, int len) {
  cout << "[";
  for(int i = 0; i < len; i++) {
    cout << a[i];
    if(i = len -1) {cout << "]";}
    else {cout << a[i] << ", ";}
  }
}