#include <iostream>
#include <cmath>   // for sqrt()
using namespace std;

// Check prime
bool isPrime(long long x)
{
    if (x < 2)
        return false;
    for (long long i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

// nCr
long long nCr(long long n, long long r)
{
    if (r > n)
        return 0;
    long long res = 1;
    for (long long i = 1; i <= r; i++)
    {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        long long totalWays = 0;
        long long pieces = k + 1;

        // all prime divisors of n
        for (long long g = 2; g <= n; g++)
        {
            if (!isPrime(g))
                continue;
            if (n % g != 0)
                continue;

            long long S = n / g;
            long long ways = nCr(S - 1, k);
            totalWays += ways;
        }

        cout << totalWays << "\n";
        
    }

    return 0;
}