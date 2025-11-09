#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    // Option 1: buy only single tickets
    int cost1 = n * a;

    // Option 2: buy as many m-ride tickets as possible + remaining rides as singles
    int cost2 = (n / m) * b + min((n % m) * a, b);

    cout << min(cost1, cost2) << '\n';
    return 0;
}