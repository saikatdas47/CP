#include <bits/stdc++.h>
using namespace std;

// We'll use vector<uint64_t> as dynamic bitset for speed and memory control.
// But std::bitset<N> would be simpler if N were compile-time.
// Here we implement a small wrapper over vector<uint64_t>.

struct DynBitset {
    int n;                  // number of bits
    int W;                  // words
    vector<uint64_t> a;
    DynBitset() : n(0), W(0) {}
    DynBitset(int _n) { init(_n); }
    void init(int _n) {
        n = _n;
        W = (n + 63) >> 6;
        a.assign(W, 0ull);
    }
    void setBit(int pos) { // pos: 0-based
        a[pos >> 6] |= (1ull << (pos & 63));
    }
    bool test(int pos) const {
        return (a[pos >> 6] >> (pos & 63)) & 1ULL;
    }
    // OR with other bitset (same size)
    void orWith(const DynBitset &other) {
        for (int i = 0; i < W; ++i) a[i] |= other.a[i];
    }
    // check any intersection
    bool intersects(const DynBitset &other) const {
        for (int i = 0; i < W; ++i)
            if ((a[i] & other.a[i]) != 0) return true;
        return false;
    }
    // extract set bits into sorted vector of 1-based labels
    vector<int> toVectorLabels() const {
        vector<int> out;
        out.reserve(64);
        for (int w = 0; w < W; ++w) {
            uint64_t x = a[w];
            while (x) {
                int b = __builtin_ctzll(x);
                int pos = (w << 6) + b;
                if (pos >= n) break;
                out.push_back(pos + 1); // convert to 1-based label
                x &= x - 1;
            }
        }
        sort(out.begin(), out.end());
        return out;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#if defined(__GNUC__) || defined(__clang__)
    ios::sync_with_stdio(true);
#endif

    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; ++tc) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> g(N), gr(N);
        for (int i = 0; i < M; ++i) {
            int u, v; cin >> u >> v; --u; --v;
            g[u].push_back(v);
            gr[v].push_back(u);
        }

        // Topological sort (Kahn's algorithm)
        vector<int> indeg(N, 0);
        for (int u = 0; u < N; ++u)
            for (int v : g[u]) indeg[v]++;

        queue<int> q;
        for (int i = 0; i < N; ++i) if (indeg[i] == 0) q.push(i);
        vector<int> topo;
        topo.reserve(N);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (int v : g[u]) {
                if (--indeg[v] == 0) q.push(v);
            }
        }
        // If topo size != N, graph not DAG, but problem guarantees DAG.

        // Build reachability bitsets using reverse topo order:
        vector<DynBitset> reach(N), revReach(N);
        for (int i = 0; i < N; ++i) {
            reach[i].init(N);
            revReach[i].init(N);
        }
        // reach: process topo in reverse, for each u set u and or with children
        for (int idx = N - 1; idx >= 0; --idx) {
            int u = topo[idx];
            reach[u].setBit(u);
            for (int v : g[u]) {
                reach[u].orWith(reach[v]);
            }
        }
        // revReach: process reverse-topo in reverse on reversed graph (i.e., topo order forward)
        // Alternatively process topo forward on reversed graph
        for (int idx = 0; idx < N; ++idx) {
            int u = topo[idx]; // processing in topological order for reversed graph
            revReach[u].setBit(u);
            for (int p : gr[u]) {
                // p -> u in original graph means in reversed graph u->p
                // but we want set of nodes that can reach u in original:
                // revReach[u] should include revReach[p]? Wait: simpler: do DP on reverse graph same way:
                // process idx from 0..N-1 and for each p in gr[u], revReach[u] |= revReach[p]
            }
            // We'll do proper DP by iterating reversed topo:
        }
        // Better: compute revReach by running same DP but on reversed graph g_rev,
        // in reverse of topo (i.e., process original topo forward):
        for (int idx = 0; idx < N; ++idx) { // forward topo
            int u = topo[idx];
            revReach[u].setBit(u);
            for (int p : gr[u]) { // p -> u in original graph, so p is predecessor
                revReach[u].orWith(revReach[p]);
            }
        }

        // Precompute sorted vectors of labels for each node from reach and revReach
        vector<vector<int>> reachList(N), revReachList(N);
        for (int i = 0; i < N; ++i) {
            reachList[i] = reach[i].toVectorLabels();
            revReachList[i] = revReach[i].toVectorLabels();
        }

        int Q; cin >> Q;
        cout << "Case " << tc << ":\n";

        // For each query: if reach[U][V] then 0 else compute minimal |x-y|
        while (Q--) {
            int U, V; cin >> U >> V; --U; --V;
            if (reach[U].test(V)) {
                cout << 0 << '\n';
                continue;
            }
            // If either set is empty (shouldn't happen), handle
            const vector<int> &A = reachList[U];
            const vector<int> &B = revReachList[V];

            // If either list empty -> can't connect (but by constraints N>=1 each includes at least itself)
            if (A.empty() || B.empty()) { cout << abs((U+1) - (V+1)) << '\n'; continue; }

            // iterate over smaller vector and binary search on larger
            const vector<int> *small = &A;
            const vector<int> *large = &B;
            if (small->size() > large->size()) swap(small, large);

            long long best = LLONG_MAX;
            for (int x : *small) {
                // find lower_bound in large
                auto it = lower_bound(large->begin(), large->end(), x);
                if (it != large->end()) {
                    best = min(best, (long long)abs(x - *it));
                    if (best == 0) break;
                }
                if (it != large->begin()) {
                    --it;
                    best = min(best, (long long)abs(x - *it));
                    if (best == 0) break;
                }
            }
            cout << best << '\n';
        }
    }
    return 0;
}