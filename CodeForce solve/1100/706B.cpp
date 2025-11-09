#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) cin >> prices[i];
    sort(prices.begin(), prices.end());
    int q; cin >> q;
    while (q--) {
        int m; cin >> m;
        cout << upper_bound(prices.begin(), prices.end(), m) - prices.begin() << '\n';
    }
    return 0;
}