#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        int sum = 0;
        int evenCount = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            if (a[i] % 2 == 0) ++evenCount;
        }

        if (sum % 2 == 1) {
            cout << "NO\n";
        } else {
            // total sum is even
            if (evenCount > 0) cout << "YES\n";
            else cout << "YES\n"; // all odd but total even => number of odds is even => possible
        }
    }
    return 0;
}