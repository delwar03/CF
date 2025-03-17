#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; 
    cin >> N >> K;
    vector<vector<ll>> C(N, vector<ll>(N));
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> C[i][j];
        }
    }
    
    // Compute all-pairs shortest paths; d[u][v] will be our metric.
    vector<vector<ll>> d = C;
    for (int k=0; k<N; k++){
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if(d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    
    // The mandatory set is M = {0, 1, ..., K-1}.
    // Extra vertices (available for queries) are those with indices in {K, K+1, ..., N-1}.
    int extraCount = N - K;
    // For each extra vertex x (0-indexed) with x in [K, N-1],
    // we will compute an array F[x][v] for v in [0, N-1]:
    // F_x(v) = minimum cost of a tree connecting M ∪ {x} that "ends" at v.
    // We store these in a 2D array F_extra[ x-K ][v].
    vector<vector<ll>> F_extra(extraCount, vector<ll>(N, INF));
    
    // For each extra vertex x:
    for (int x = K; x < N; x++){
        int idx = x - K; // index into F_extra
        // Terminal set T: size m = K+1.
        // For i in [0, K-1]: terminal i is vertex i.
        // Terminal K: is the extra vertex x.
        int m = K + 1;
        int fullMask = (1 << m) - 1;
        // dp[mask][v]: DP state for current extra vertex x.
        vector<vector<ll>> dp(1 << m, vector<ll>(N, INF));
        
        // Base initialization: for each terminal in T.
        for (int i=0; i<m; i++){
            int term = (i < K ? i : x);
            for (int v=0; v<N; v++){
                dp[1 << i][v] = d[term][v];
            }
        }
        
        // DP over subsets.
        for (int mask = 1; mask < (1 << m); mask++){
            // Merge two nonempty, proper submasks.
            // (We iterate over proper nonempty submasks of 'mask'.)
            for (int sub = (mask-1)&mask; sub; sub = (sub-1)&mask){
                int other = mask ^ sub;
                for (int v=0; v<N; v++){
                    dp[mask][v] = min(dp[mask][v], dp[sub][v] + dp[other][v]);
                }
            }
            // Then relax the DP state:
            vector<ll> newdp(N, INF);
            for (int v=0; v<N; v++){
                for (int u=0; u<N; u++){
                    newdp[v] = min(newdp[v], dp[mask][u] + d[u][v]);
                }
            }
            dp[mask] = newdp;
        }
        // Save the result for extra vertex x.
        for (int v=0; v<N; v++){
            F_extra[idx][v] = dp[fullMask][v];
        }
    }
    
    // Precompute an "attachment" array H_extra for each extra vertex.
    // H_extra[x][w] = min_{v in V} { F_extra[x][v] + d[v][w] }.
    vector<vector<ll>> H_extra(extraCount, vector<ll>(N, INF));
    for (int i=0; i<extraCount; i++){
        for (int w=0; w<N; w++){
            for (int v=0; v<N; v++){
                H_extra[i][w] = min(H_extra[i][w], F_extra[i][v] + d[v][w]);
            }
        }
    }
    
    // Now answer queries.
    // Each query gives two distinct integers s and t (1-indexed) with s,t in {K+1, ..., N}.
    int Q; cin >> Q;
    // For a query with extra vertices s and t (convert to 0-index: they are in [K, N-1]),
    // one can show that an optimal good graph has cost
    //   ans = min{ min_{w in V} { F_extra[s'][w] + d[w][t] },
    //              min_{w in V} { F_extra[t'][w] + d[w][s] } }
    // where s' = s-K and t' = t-K (the indices in our precomputed arrays).
    for (int qi = 0; qi < Q; qi++){
        int s, t; 
        cin >> s >> t;
        s--; t--; // convert to 0-index
        int idx_s = s - K; // s is extra, so s >= K
        int idx_t = t - K; // t is extra
        ll ans = INF;
        // Option 1: attach t to the tree computed for extra vertex s.
        ans = min(ans, H_extra[idx_s][t]);
        // Option 2: attach s to the tree computed for extra vertex t.
        ans = min(ans, H_extra[idx_t][s]);
        cout << ans << "\n";
    }
    
    return 0;
}
