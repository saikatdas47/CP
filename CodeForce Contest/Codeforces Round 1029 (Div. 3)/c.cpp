#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

#define ll long long
#define MOD 1000000007
#define MAXN 200000

int A[MAXN+2];

int main() {
    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        ll n;
        cin >> n;
        set<int> all_sets[2];
        int curr_set_idx = 0;
        int ans = 0;
        for(int i=1; i<=n; i++) {
            cin >> A[i];
            all_sets[1-curr_set_idx].erase(A[i]);
            all_sets[curr_set_idx].insert(A[i]);
            if(all_sets[1-curr_set_idx].empty()) {
                ans++;
                curr_set_idx = 1 - curr_set_idx;
            }
        }
        cout << ans << endl;
    }
    return 0;
}