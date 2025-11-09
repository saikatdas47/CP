#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "codeforces";
    int t;
    cin >> t;
    while (t--) {
        char c;
        cin >> c;
        if (s.find(c) != string::npos)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}