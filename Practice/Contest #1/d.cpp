#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a + b - c) == d)
    {
        cout << "YES";
    }
    else if ((a - b + c) == d)
    {
        cout << "YES";
    }
    else if ((a - b * c) == d)
    {
        cout << "YES";
    }
    else if ((a * b - c) == d)
    {
        cout << "YES";
    }
    else if ((a * b + c) == d)
    {
        cout << "YES";
    }
    else if ((a + b * c) == d)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}

/*
D. Ali Baba and Puzzles
time limit per test1 second
memory limit per test256 megabytes
One day, Ali Baba had an easy puzzle that he couldn't solve. The puzzle consisted of 4 numbers and his task was to check whether he could get the fourth number using arithmetic operators (+,−,×) between the other three numbers; so that each operator is used only once.

𝑎◻𝑏◻𝑐=𝑑
Can you solve this tricky puzzle for him?
Input
Only one line containing four numbers 𝑎, 𝑏, 𝑐 and 𝑑 (−109≤𝑎,𝑏,𝑐≤109),(−1018≤𝑑≤1018).

Output
Print "YES" (without quotes) if you get the fourth number using arithmetic operators, otherwise, print "NO" (without quotes).

Examples
inputCopy
3 4 5 23
outputCopy
YES
inputCopy
9 5 3 7
outputCopy
YES
inputCopy
1 2 3 1
outputCopy
NO
*/