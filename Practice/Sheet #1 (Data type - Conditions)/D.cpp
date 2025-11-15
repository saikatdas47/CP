#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long int r = (a * b) - (c * d);

    cout << "Difference = " << r;

    return 0;
}