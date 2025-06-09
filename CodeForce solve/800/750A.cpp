#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int m = 0;
    int p = 240 - k;
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        m = m + (5 * i);
        
        if (m > p)
        {
            break;
        }c = i;
    }
    cout << c << endl;
    return 0;
}