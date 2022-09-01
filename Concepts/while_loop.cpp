#include <iostream>
using namespace std;
int main() 
{
    int num = 8654;

    cout << "3n+1 Problem starting with the number " << num << endl;
    cout << num << endl;
    while (num > 1) {
        if (num%2) {
            num = 3 * num + 1;
        } else {
            num = num/2;
        }
        cout << num << endl;
    }
}