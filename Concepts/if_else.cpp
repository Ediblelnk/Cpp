#include <iostream>
using namespace std;
int main()
{
    int x;
    cout << "Please Input A Number: ";
    cin >> x;
    if (x > 0)
        cout << x << " is positive";
    else if (x < 0)
        cout << x << " is negative";
    else
        cout << x << " is neither negative or positive";
}