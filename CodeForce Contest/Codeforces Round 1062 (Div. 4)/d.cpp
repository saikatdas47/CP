#include <iostream>
#include <vector>
#include <algorithm> // for std::gcd

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        long long g = a[0];
        for (int i = 1; i < n; i++)
            g = gcd(g, a[i]);

        if (g == 1) {
            cout << 2 << '\n';
            continue;
        }

        bool done = false;
        for (long long x = 2; x <= 1000000; x++) {
            for (auto val : a) {
                if (gcd(val, x) == 1) {
                    cout << x << '\n';
                    done = true;
                    break;
                }
            }
            if (done) break;
        }

        if (!done)
            cout << g + 1 << '\n';
    }
}