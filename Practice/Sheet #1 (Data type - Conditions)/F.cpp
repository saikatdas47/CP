#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int a, b;
    cin >> a >> b;
    int c, d;
    c = a % 10;
    d = b % 10;

    cout << c + d;

    return 0;
}
/*
F. Digits Summation
time limit per test0.25 seconds
memory limit per test64 megabytes
Given two numbers N and M. Print the summation of their last digits.

Input
Only one line containing two numbers N, M (0 ≤ N, M ≤ 1018).

Output
Print the answer of the problem.

Example
inputCopy
13 12
outputCopy
5
Note
First Example :

last digit in the first number is 3 and last digit in the second number is 2.

So the answer is: (3 + 2 = 5)
*/