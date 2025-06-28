#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // যেহেতু একটি মাত্র সংখ্যা আলাদা, তাই প্রথম তিনটা দিয়ে common value বের করা যাবে
        int common;
        if (a[0] == a[1]) {
            common = a[0];
        } else if (a[0] == a[2]) {
            common = a[0];
        } else {
            common = a[1];
        }

        for (int i = 0; i < n; ++i) {
            if (a[i] != common) {
                cout << i + 1 << '\n'; // 1-based index
                break;
            }
        }
    }

    return 0;
}