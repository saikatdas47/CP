#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> r = {2, 1};

        for (int i = 3; i <= n; i++) {
            r.insert(r.end() - 1, i);
        }

        for (int x : r)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}