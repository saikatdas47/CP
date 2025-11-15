#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int n;
    cin >> n;
    cout << (n * (n + 1)) / 2;

    return 0;
}
/*G. Summation from 1 to N
time limit per test0.25 seconds
memory limit per test256 megabytes
Given a number 𝑁. Print the summation of the numbers that is between 1 and 𝑁 (inclusive).

.∑𝑖=1𝑁𝑖
Input
Only one line containing a number 𝑁 (1≤𝑁≤109)
Output
Print the summation of the numbers that are between 1 and 𝑁 (inclusive).

Examples
inputCopy
3
outputCopy
6
inputCopy
10
outputCopy
55
Note
First Example :

the numbers between 1 and 3 are 1,2,3 .

So the answer is: (1 + 2 + 3 = 6)

Second Example :

the numbers between 1 and 10 are 1,2,3,4,5,6,7,8,9,10.

So the answer is: (1 + 2 + 3 + 4 + 5 + 6 +7 +8 + 9 + 10 = 55)
*/