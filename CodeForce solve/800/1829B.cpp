#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int ans = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x == 0) {
                cnt++;
                ans = max(ans, cnt);
            } else {
                cnt = 0;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}