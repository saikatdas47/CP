#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int total = 0;   // sizeof (excluding final \0)
        int len = 0;     // strlen
        bool null_found = false;

        for (int i = 0; i < s.size();) {
            if (i + 1 < s.size() && s[i] == '\\' && s[i + 1] == '0') {
                // we found a null character
                total += 1;
                if (!null_found) null_found = true;
                i += 2; // skip both '\' and '0'
            } else {
                total += 1;
                if (!null_found) len += 1;
                i += 1;
            }
        }

        cout << (total + 1) << " " << len << "\n";  // +1 for final compiler null
    }
}