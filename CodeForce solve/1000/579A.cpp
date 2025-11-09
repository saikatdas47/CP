#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    int ans = 0;
    while (x) {
        ans += (x & 1); // count 1-bits
        x >>= 1;
    }
    cout << ans << '\n';
    return 0;
}