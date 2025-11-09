#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int n;
        cin >> n; 

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i]; 
        }

      
        vector<int> b = a;
        sort(b.begin(), b.end());

       
        bool hasEven = false;
        bool hasOdd = false;

        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0)
                hasEven = true;
            else
                hasOdd = true;
        }

        
        if (hasEven && hasOdd) {
            for (int i = 0; i < n; i++) {
                cout << b[i] << " ";
            }
        }
       
        else {
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}