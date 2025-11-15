#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    string k = n;
    reverse(k.begin(), k.end()); // full reverse

    int l;
    for (int i = 0; i < k.size();) //not leading zeroes er index ber korsi 
    {
        if (k[i] == '0')
        {
            i++;
        }
        else
        {
            l = i;
            break;
        }
    }
    for (; l < k.size(); l++) // than print korsi
    {
        cout << k[l];
    }
    cout << endl;

    // palindrome check (compare original with full reversed)
    if (n == k)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}

/*
I. Palindrome
time limit per test1 second
memory limit per test256 megabytes
Given a number 𝑁. Print 2 lines that contain the following respectively:

Print 𝑁 in a reversed order and not leading zeroes.
If 𝑁 is a palindrome number print "YES" otherwise, print "NO.
Note:

A palindrome number is a number that reads the same forward or backward.

For example: 12321, 101 are palindrome numbers, while 1201, 221 are not.

A leading zero is any 0 digit that comes before the first nonzero digit in a number for example : numbers (005 , 01 , 0123 , 02 , 000250 ) are leading zeroes but ( 5 , 123 , 20 ,2500 ) not leading zeroes numbers .

Input
Only one line containing a number 𝑁 (1≤𝑁≤107).

Output
Print the answer required above.

Examples
inputCopy
12121
outputCopy
12121
YES
inputCopy
160
outputCopy
61
NO
*/