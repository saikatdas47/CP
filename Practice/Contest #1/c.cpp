#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char c;
    cin >> c;

    if (c == 'z')
        cout << 'a';
    else
        cout << char(c + 1);

    return 0;
}
/*
C. Next Alphabet
time limit per test1 second
memory limit per test256 megabytes
Given a lowercase alphabet character. You have to print the next character in the alphabet.

Input
Only one line containing a lowercase English letter 𝐶.

Output
Print the next letter to 𝐶 in the alphabet.

Example
inputCopy
a
outputCopy
b
Note
The next letter to z is a.
*/