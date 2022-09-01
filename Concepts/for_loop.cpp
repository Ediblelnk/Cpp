#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    string str = "the quick brown fox jumps over the lazy dog";

    for (int i = 0; i < str.length(); i++) {
        cout << setw(2) << i+1 << " " << str.substr(i, 1) << endl;
    }
}