#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int a, b, k;
    cin >> a >> b >> k;
    if (a % k == 0 && b % k == 0)
    {
        cout << "Both";
    }
    else if (a % k == 0)
    {
        cout << "Memo";
    }
    else if (b % k == 0)
        {
            cout << "Momo";
        }
    else
    {
        cout << "No One";
    }
    return 0;
}


/*B. Memo and Momo
time limit per test1 second
memory limit per test256 megabytes
Memo and Momo are playing a game. Memo will choose a positive number 𝑎, and Momo will choose a positive number 𝑏.

Your task is to tell them who will win according to the following rules:

If both 𝑎 and 𝑏 are divisible by 𝑘, both of them win and you should print "Both".
If 𝑎 is divisible by 𝑘 but 𝑏 isn't, Memo wins and you should print "Memo".
If 𝑏 is divisible by 𝑘 but 𝑎 isn't, Momo wins and you should print "Momo".
If both 𝑎 and 𝑏 are not divisible by 𝑘, no one wins and you should print "No One".
Input
Only one line containing three positive numbers 𝑎, 𝑏 and 𝑘 (1≤𝑎,𝑏,𝑘≤1018).

Output
Print the answer as described in the statement.

Examples
inputCopy
15 7 3
outputCopy
Memo
inputCopy
22 10 2
outputCopy
Both
*/