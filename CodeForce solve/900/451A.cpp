#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    int moves = min(n, m);
    if (moves % 2 == 1) cout << "Akshat\n";
    else cout << "Malvika\n";
    return 0;
}