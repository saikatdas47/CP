#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

     long int n;
    cin >> n;

    if (n == 1)
    {
        cout << -1 << endl;
    }
    else
    {
        for ( long int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                cout << i << endl;
            }
            else
            {
                continue;
            }
        }
    }

    return 0;
}
/*B. Even Numbers
time limit per test1 second
memory limit per test256 megabytes
Given a number N. Print all even numbers between 1 and N inclusive in separate lines.

Input
Only one line containing a number N (1 ≤ N ≤ 103).

Output
Print the answer according to the required above. If there are no even numbers print -1.

Examples
inputCopy
10
outputCopy
2
4
6
8
10
inputCopy
5
outputCopy
2
4
*/