#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r;
    cin >> n >> r;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i = i + r)
    {
        int min = a[i];
        for (int j = i; j < i + r && j < n; j++)
        {
            if (a[j] < min)
                min = a[j];
        }
        cout << min << " ";
    }

    return 0;
}

/*
C. Finding Minimums
time limit per test1 second
memory limit per test256 megabytes
You are given 𝑁 numbers, and you should divide them into consecutive groups of size 𝐾, then print the minimum among each group. If the last group is of size <𝐾, print the minimum number found just after the last number received.

For more explanation, see the notes.

Input
First line contains two numbers 𝑁,𝐾 (1≤𝐾≤𝑁≤105) – the number of values, and the range length after which you should print the minimum.

Second line contains 𝑁 numbers (−109≤𝑥≤109).

Output
Print the answer in a single line.

Examples
inputCopy
8 3
4 -1 2 3 5 0 2 7
outputCopy
-1 0 2 
inputCopy
8 4
4 -1 2 3 5 0 2 7
outputCopy
-1 0 
Note
In the first test case:

The minimum number among [4,−1,2] is −1.
The minimum number among [3,5,0] is 0.
The minimum number among [2,7] is 2.

In the second test case:

The minimum number among [4,−1,2,3] is −1.
The minimum number among [5,0,2,7] is 0.
*/