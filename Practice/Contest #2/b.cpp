#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i == j && i == n / 2) // center cell → X
            {
                cout << 'X';
            }
            else if (i == j) // find  left diagonal → "\"
            {
                cout << '\\';  // \\ produces a single backslash in output
            }
            else if (j == n - 1 - i) //find  right diagonal → /
            {
                cout << '/';
            }
            else                //	Everywhere else → *
            {
                cout << '*';
            }
        }
        cout << "\n";
    }
    return 0;
}

/*
B. Drawing 'X'
time limit per test1 second
memory limit per test256 megabytes
Some day, an artist wanted to draw an X mark on the wall in a fashionable way.

He wanted to do so by grouping snippets of slashes /, backslashes \, asterisks * and a capital X letter in an 𝑁×𝑁 square as shown in the sample. Can you help him?

Input
Only one line containing one odd number 𝑁 (3≤𝑁≤49).

Output
Print the fashionable drawing.

Example
inputCopy
5
outputCopy

 https://codeforces.com/group/MWSDmqGsZm/contest/326907/problem/B
*/