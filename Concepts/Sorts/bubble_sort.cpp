#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

//prints out an array with len elements
void print_array(int arr[], int len) {
    for (int j = 0; j < len; j++) {
        cout << setw(2) << arr[j] << ", ";
    }
    cout << endl;
}

int main() {
    // generator
    srand(time(NULL));
    // ^ changes the seed of the random num generator based on current time since Jan 1, 1970
    int rand();

    // vars
    int length = 10;
    int arr[length];
    const int MAX = 30;
    const int OFFSET = 0;

    // assigns random values to each element of array
    for (int j = 0; j < length; j++) {
        arr[j] = rand() % MAX + OFFSET;
    }

    print_array(arr, length);

    bool flag = true;
    int temp;
    while (flag) {
        flag = false;
        for (int i = 0; i < length - 1; i++) {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

                flag = true;
            }
        }
    }

    print_array(arr, length);
}