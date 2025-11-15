#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long modpow(long long a, long long e=MOD-2){
    long long r=1;
    while(e){
        if(e&1) r = (r*a)%MOD;
        a = (a*a)%MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if(!(cin>>T)) return 0;
    while(T--){
        int N, K;
        cin >> N >> K;
        vector<string> A(N);
        for(int i=0;i<N;i++) cin >> A[i];

        // Wmask[i] has bits of people i thinks WEAKER (i.e. i counts them as weaker)
        vector<int> Wmask(N,0);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(A[i][j]=='W') Wmask[i] |= (1<<j);
            }
        }

        int FULL = (1<<N) - 1;
        long long total_sum = 0; // will accumulate sum_{u=1..N} sum_{m=1..K} count(S_u >= m) mod MOD

        // Precompute factorial N!
        long long fact = 1;
        for(int i=2;i<=N;i++) fact = fact * i % MOD;

        // For every threshold u = 1..N compute distribution of S_u
        for(int u=1; u<=N; ++u){
            // dp[mask][c] = number of ways to form prefix 'mask' with exactly c satisfied (X_{.,u}=1) among placed people
            // We store as vector of vectors or a flat structure.
            // Size: 2^N masks, each needs up to N+1 counters.
            int SZ = 1<<N;
            // allocate dp as vector of vectors of ints (mod)
            vector< vector<int> > dp(SZ, vector<int>(N+1, 0));
            dp[0][0] = 1;

            for(int mask=0; mask < SZ; ++mask){
                // for each mask, iterate possible count c that has non-zero dp
                for(int c=0; c<=N; ++c){
                    int cur = dp[mask][c];
                    if(cur==0) continue;
                    // try to place each i not in mask
                    int notmask = (~mask) & FULL;
                    // iterate set bits of notmask:
                    int mm = notmask;
                    while(mm){
                        int bit = mm & -mm;
                        int i = __builtin_ctz(bit);
                        mm -= bit;
                        // number of weaker of i already in mask:
                        int wk = __builtin_popcount(mask & Wmask[i]);
                        int sat = (wk >= u) ? 1 : 0;
                        dp[mask | (1<<i)][c + sat] = (dp[mask | (1<<i)][c + sat] + cur) % MOD;
                    }
                }
            }

            // We have dp[FULL][s] = number of permutations with S_u = s
            // compute for m=1..K how many permutations have S_u >= m
            // We can compute prefix sums of dp[FULL]
            vector<int> cnt(N+1, 0);
            for(int s=0;s<=N;s++) cnt[s] = dp[FULL][s];

            // compute suffix sums: cnt_ge[m] = sum_{s>=m} cnt[s]
            vector<int> cnt_ge(N+2, 0);
            long long running = 0;
            for(int s=N; s>=0; --s){
                running = (running + cnt[s]) % MOD;
                cnt_ge[s] = (int)running;
            }
            // Add sum_{m=1..K} cnt_ge[m] to total_sum
            long long addu = 0;
            for(int m=1; m<=K; ++m){
                addu += cnt_ge[m];
                if(addu >= (1LL<<62)) addu %= MOD; // keep safe (though unlikely)
            }
            total_sum = (total_sum + (addu % MOD)) % MOD;
        }

        // expected value = total_sum / N!  (modulo)
        long long invfact = modpow(fact, MOD-2);
        long long ans = total_sum % MOD * invfact % MOD;
        cout << ans << "\n";
    }
    return 0;
}