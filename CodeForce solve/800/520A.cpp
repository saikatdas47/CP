#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count = 0;

    for (char c = 'a'; c <= 'z'; c++)
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            char ch = tolower(s[i]);
            if (ch == c)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
/*
A. Pangram
time limit per test2 seconds
memory limit per test256 megabytes
A word or a sentence in some language is called a pangram if all the characters of the alphabet of this language appear in it at least once. Pangrams are often used to demonstrate fonts in printing or test the output devices.

You are given a string consisting of lowercase and uppercase Latin letters. Check whether this string is a pangram. We say that the string contains a letter of the Latin alphabet if this letter occurs in the string in uppercase or lowercase.

Input
The first line contains a single integer n (1 ≤ n ≤ 100) — the number of characters in the string.

The second line contains the string. The string consists only of uppercase and lowercase Latin letters.

Output
Output "YES", if the string is a pangram and "NO" otherwise.

Examples
inputCopy
12
toosmallword
outputCopy
NO
inputCopy
35
TheQuickBrownFoxJumpsOverTheLazyDog
outputCopy
YES
*/