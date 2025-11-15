#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    int a[k];
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    int e = 0, o = 0, p = 0, n = 0;
    for (int i = 0; i < k; i++)
    {
        if (a[i] < 0)
        {
            n++;
        }
        if (a[i] > 0)
        {
            p++;
        }
        if (abs(a[i]) % 2 == 0)
        {
            e++;
        }
        if (abs(a[i]) % 2 != 0)
        {
            o++;
        }
    }

    cout << "Even: " << e << endl;
    cout << "Odd: " << o << endl;
    cout << "Positive: " << p << endl;
    cout << "Negative: " << n << endl;

    return 0;
}

/*C. Even, Odd, Positive and Negative
time limit per test1 second
memory limit per test256 megabytes
Given N numbers. Count how many of these values are even, odd, positive and negative.

Input
First line contains one number N (1 ≤ N ≤ 103) number of values.

Second line contains N numbers (-105 ≤ Xi ≤ 105).

Output
Print four lines with the following format:

First Line: "Even: X", where X is the number of even numbers in the given input.

Second Line: "Odd: X", where X is the number of odd numbers in the given input.

Third Line: "Positive: X", where X is the number of positive numbers in the given input.

Fourth Line: "Negative: X", where X is the number of negative numbers in the given input.

Example
inputCopy
5
-5 0 -3 -4 12
outputCopy
Even: 3
Odd: 2
Positive: 1
Negative: 3
Note
First Example :

Even Numbers are : 0, -4 , 12

Odd Numbers are : -5 , -3

Positive Numbers are : 12

Negative Numbers are : -5 , -3 , -4
*/