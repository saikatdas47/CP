#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n+1), c(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }

        const long long INF = numeric_limits<long long>::max() / 4;
        // dp0 = keep this position, dp1 = change this position
        long long dp0_prev = 0;    // for i=1, if we keep position 1, cost=0
        long long dp1_prev = c[1]; // if we change position 1, cost=c1
        // If we change position 1, we can choose any value, so no drop concern yet.

        for (int i = 2; i <= n; i++) {
            long long dp0_curr = INF;
            long long dp1_curr = INF;

            // Case: we keep a[i]
            // To keep a[i], we need previous value ≤ a[i].
            // If previous was kept: a[i-1] ≤ a[i]
            if (a[i-1] <= a[i]) {
                dp0_curr = min(dp0_curr, dp0_prev);
            }
            // If previous was changed: we could set previous to any value ≤ a[i]
            dp0_curr = min(dp0_curr, dp1_prev);

            // Case: we change a[i]
            // We pay cost c[i], and we can pick any value for this position,
            // so prefix up to i-1 must be valid, but we are free now.
            dp1_curr = min(dp1_curr, min(dp0_prev, dp1_prev) + c[i]);

            // Move to next
            dp0_prev = dp0_curr;
            dp1_prev = dp1_curr;
        }

        long long answer = min(dp0_prev, dp1_prev);
        cout << answer << "\n";
    }

    return 0;
}