#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long int n;
    cin >> n;
    int k = 0;
    for (int i = 2; i < n; i++) //logic: let n=7 1 r 7 bad e jekhono number between 1-7 er modde{2,3,4,5,6} er shate 7 ke vag diye jodi kono ekbar shate vagshes na thake setha prime number hobe na 
    {
        if (n % i == 0) 
        {

            k = 1; // kono ektar shate vagshes 0 pailam mane prime na. than break kore disi cz ami amar answer peye gesi. noyto complexity barbe
            break;
        }
    }
    if (k == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
/*
H. One Prime
time limit per test3 seconds
memory limit per test64 megabytes
Given a number X. Determine if the number is prime or not

Note:

A prime number is a number that is greater than 1 and has only two factors which are 1 and itself.

In other words : prime number divisible only by 1 and itself.

Be careful that 1 is not prime .

The first few prime numbers are


Input
Only one line containing a number X (2 ≤ X ≤ 105).

Output
print "YES" if the number is prime and "NO" otherwise.

Examples
inputCopy
7
outputCopy
YES
inputCopy
15
outputCopy
NO
Note
First Example :

7 is prime because it is not divisible by 2,3,4,5,6, and only divisible by 1 and itself, so the answer is YES.

Second Example :

15 not is prime because it is divisible by 3 ,5, so the answer is NO.
*/