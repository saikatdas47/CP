#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        unsigned long long n;
        cin >> n;
        // if n is a power of two -> no odd divisor >1
        bool is_power_of_two = (n & (n - 1)) == 0;
        cout << (is_power_of_two ? "NO" : "YES") << '\n';
    }
    return 0;
}