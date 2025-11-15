#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    if (!(cin >> a >> b)) return 0;

    cout << a << " + " << b << " = " << a + b << "\n";
    cout << a << " * " << b << " = " << a * b << "\n";
    cout << a << " - " << b << " = " << a - b << "\n";

    return 0;
}

/*
C. Simple Calculator
time limit per test1 second
memory limit per test256 megabytes
Given two numbers X and Y. Print the summation and multiplication and subtraction of these 2 numbers.

Input
Only one line containing two separated numbers X, Y (1  ≤  X, Y  ≤  105).

Output
Print 3 lines that contain the following in the same order:

"X + Y = summation result" without quotes.
"X * Y = multiplication result" without quotes.
"X - Y = subtraction result" without quotes.
Example
inputCopy
5 10
outputCopy
5 + 10 = 15
5 * 10 = 50
5 - 10 = -5
Note
Be careful with spaces.
*/