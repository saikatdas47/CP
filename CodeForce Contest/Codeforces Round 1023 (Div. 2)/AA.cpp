#include <iostream>
#include <vector>
#include <numeric>  // for std::gcd

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        bool f = false;
        vector<int> r(n, 1); 

        for(int i = 1; i < n; i++){
            if(a[i] != a[0]){
                r[i] = 2; 
                int g1 = a[0], g2 = a[i];

                for(int j = 1; j < n; j++){
                    if(j == i) continue;
                    if(gcd(g1, a[j]) != g1){
                        r[j] = 2;
                        g2 = gcd(g2, a[j]);
                    } else {
                        r[j] = 1;
                        g1 = gcd(g1, a[j]);
                    }
                }

                if(g1 != g2){
                    f = true;
                    cout << "Yes\n";
                    for(int j = 0; j < n; j++) cout << r[j] << " ";
                    cout << "\n";
                }

                break;
            }
        }

        if(!f){
            cout << "No\n";
        }
    }

    return 0;
}