#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a < b)
    {
        cout << a << " ";
        int c = b - a;
        cout << c / 2;
    }
    else if (b < a)
    {
        cout << b << " ";
        int c = a - b;
        cout << c / 2;
    }
    else // a == b
    {
        cout << a << " " << 0;
    }

    return 0;
}