#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    vector<int> divisors;
    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0 && b % i == 0)
        {

            divisors.push_back(i);
        }
    }
    cout << *max_element(divisors.begin(), divisors.end());

    return 0;
}





/*
L. GCD
time limit per test1 second
memory limit per test256 megabytes
Given two numbers A and B. Print the greatest common divisor between (A, B).

Note: The greatest common divisor (GCD) of two or more integers, which are not all zeroes, is the largest positive integer that divides each of the integers.

For example:

the GCD of 8 and 12 is 4.

because the numbers that divides both 8 and 12 are (1,2,4) and 4 is the largest one .

Input
Only one line containing two numbers A and B (1 ≤ A, B ≤ 103).

Output
Print the GCD of A and B.

Examples
inputCopy
12 8
outputCopy
4
inputCopy
3 7
outputCopy
1
inputCopy
3 7
outputCopy
1
inputCopy
5 10
outputCopy
5
Note
What is the greatest common divisor of 54 and 24?

*The number 54 can be expressed as a product of two integers in several different ways:

54 * 1 = 27 * 2 = 18 * 3 = 9 * 6 .....

Thus the divisors of 54 are: 1,2,3,6,9,18,27,54

Similarly, the divisors of 24 are: 1,2,3,4,6,8,12,24

The numbers that these two lists share in common are the common divisors of 54 and 24:

1,2,3,6

The greatest of these is 6. That is, the greatest common divisor of 54 and 24. One writes:

gcd(54,24) = 6.
*/



/*
LCM(A, B) = (A * B )/GCD(A, B)
*/