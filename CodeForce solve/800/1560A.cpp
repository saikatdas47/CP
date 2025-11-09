#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int count = 0, num = 0;
        while (count < k) {
            num++;
            if (num % 3 != 0 && num % 10 != 3)
                count++;
        }
        cout << num << '\n';
    }

    return 0;
}