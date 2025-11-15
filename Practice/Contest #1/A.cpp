#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(2);

    float  d, p;
    cin >> d >> p;
    cout << (p / ((100 - d) / 100));

    return 0;
}


/*A. Winter Sale
time limit per test1 second
memory limit per test256 megabytes
The winter sale began, and Mrs. Sarah wants to buy a T-shirt for her son. The T-shirt has a ticket that indicates a discount of 𝑋% and its price 𝑃 after the discount. She now wants to know the price before the discount to know if the discount was worthy. Help her!

Input
Only one line containing two numbers 𝑋 and 𝑃 (1≤𝑋≤99,1≤𝑃≤4×104) – the discount percentage, and the price of the T-shirt after the discount.

Output
Print the price of the T-shirt before the discount rounded up to two decimal places.

Examples
inputCopy
20 80
outputCopy
100.00
inputCopy
15 20
outputCopy
23.53
*/