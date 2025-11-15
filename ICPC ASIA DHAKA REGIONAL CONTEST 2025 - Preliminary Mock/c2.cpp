#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int MAXN = 1000001;

ll fact[MAXN];
ll invFact[MAXN];
int mu[MAXN];
vector<int> primes;

// Modular exponentiation (a^b % mod)
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Modular inverse using Fermat's Little Theorem (a^(MOD-2) % MOD)
ll modInverse(ll n) {
    return power(n, MOD - 2);
}

// Precompute factorials and inverse factorials
void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

// Modular nCr (Binomial Coefficient)
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

// Precompute Mobius function and find primes
void precomputeMobiusAndPrimes() {
    vector<int> lp(MAXN, 0); // smallest prime factor
    mu[1] = 1;

    for (int i = 2; i < MAXN; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
            mu[i] = -1;
        }
        for (int p : primes) {
            if (p > lp[i] || i * p >= MAXN) break;
            lp[i * p] = p;
            if (p == lp[i]) {
                mu[i * p] = 0; // divisible by p^2
            } else {
                mu[i * p] = -mu[i]; // square-free, product of distinct primes
            }
        }
    }
}

// Factor a number and return its prime factors and their powers
vector<pair<int, int>> factorize(int n) {
    vector<pair<int, int>> factors;
    if (n <= 1) return factors;
    
    int temp = n;
    for (int p : primes) {
        if ((ll)p * p > temp) break;
        if (temp % p == 0) {
            int count = 0;
            while (temp % p == 0) {
                temp /= p;
                count++;
            }
            factors.push_back({p, count});
        }
    }
    if (temp > 1) {
        factors.push_back({temp, 1});
    }
    return factors;
}

// Generate all divisors of a number N from its prime factorization
void generateDivisors(int N, const vector<pair<int, int>>& factors, vector<int>& divisors, int index, int current_divisor) {
    if (index == factors.size()) {
        divisors.push_back(current_divisor);
        return;
    }

    int p = factors[index].first;
    int max_power = factors[index].second;

    for (int i = 0; i <= max_power; ++i) {
        generateDivisors(N, factors, divisors, index + 1, current_divisor);
        current_divisor *= p;
    }
}

// Counts ways to cut N into m pieces with GCD = 1
ll count_gcd_one(int N, int m) {
    if (N < m) return 0;
    if (N == m) return 1;

    vector<pair<int, int>> factors = factorize(N);
    vector<int> divisors;
    generateDivisors(N, factors, divisors, 0, 1);

    ll result = 0;
    // C(N, m) = sum_{d | N} mu(d) * S(N/d, m)
    for (int d : divisors) {
        if (mu[d] == 0) continue;
        
        // S(N/d, m) = nCr(N/d - 1, m - 1)
        ll combinations = nCr(N / d - 1, m - 1);
        
        if (mu[d] == 1) {
            result = (result + combinations) % MOD;
        } else { // mu[d] == -1
            result = (result - combinations + MOD) % MOD;
        }
    }
    return result;
}

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    int m = k + 1;
    ll total_ways = 0;

    vector<pair<int, int>> factors = factorize(n);
    
    // Iterate over all distinct prime divisors p of n
    for (const auto& factor : factors) {
        int p = factor.first;
        int np = n / p;
        
        // The number of ways to have gcd exactly p is C(n/p, k+1)
        ll ways_for_p = count_gcd_one(np, m);
        total_ways = (total_ways + ways_for_p) % MOD;
    }

    cout << total_ways << "\n";
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precomputeFactorials();
    precomputeMobiusAndPrimes();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}