#include <bits/stdc++.h>
using namespace std;

bool isComposite(int x) {
    if (x < 4) return false; // smallest composite is 4
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int x = 4; x < n; x++) {
        int y = n - x;
        if (isComposite(x) && isComposite(y)) {
            cout << x << " " << y << '\n';
            break;
        }
    }

    return 0;
}