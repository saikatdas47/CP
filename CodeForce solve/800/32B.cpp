#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, result;
    cin >> s;

    for (int i = 0; i < (int)s.size(); ) {
        if (s[i] == '.') {
            result += '0';
            i++;
        } else if (s[i] == '-' && i + 1 < (int)s.size()) {
            if (s[i + 1] == '.') {
                result += '1';
                i += 2;
            } else if (s[i + 1] == '-') {
                result += '2';
                i += 2;
            }
        }
    }

    cout << result << '\n';
    return 0;
}