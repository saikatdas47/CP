#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        // prefix max
        vector<long long> pref(N);
        pref[0] = A[0];
        for (int i = 1; i < N; i++)
            pref[i] = max(pref[i - 1], A[i]);

        // suffix min
        vector<long long> suff(N);
        suff[N - 1] = A[N - 1];
        for (int i = N - 2; i >= 0; i--)
            suff[i] = min(suff[i + 1], A[i]);

        int ans = -1;
        for (int i = 0; i < N; i++) {
            bool tallerThanFront = (i == 0) ? true : (A[i] > pref[i - 1]);
            bool shorterThanBack = (i == N - 1) ? true : (A[i] < suff[i + 1]);
            if (tallerThanFront && shorterThanBack) {
                ans = i + 1;   // 1-based index
                break;
            }
        }

        cout << "Case " << tc << ": ";
        if (ans == -1) cout << "Humanity is doomed!\n";
        else cout << ans << "\n";
    }

    return 0;
}