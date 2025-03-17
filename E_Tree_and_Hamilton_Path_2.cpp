#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<pair<int, int>> g[n + 1];
    int sum = 0;
    for(int i = 0; i < n - 1; i++) {
        int u, v, w; cin>>u>>v>>w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        sum += w;
    }

    vector<int> down(n + 1), up(n + 1);

    function<void(int, int)> dfs_down = [&] (int u, int p) {
        for(auto it : g[u]) {
            int v = it.ff, wt = it.ss;
            if(v ^ p) {
                dfs_down(v, u);
                down[u] = max(down[u], down[v] + wt);
            }
        }
    };

    function<void(int, int)> dfs_up = [&] (int u, int p) {
        vector<int> pref, suff;
        for(auto it : g[u]) {
            int v = it.ff, wt = it.ss;
            if(v ^ p) {
                pref.push_back(wt + down[v]);
                suff.push_back(wt + down[v]);
            }
        }

        int k = pref.size();
        for(int i = 1; i < k; i++) pref[i] = max(pref[i], pref[i - 1]);
        for(int i = k - 2; i >= 0; i--) suff[i] = max(suff[i], suff[i + 1]);

        int ind = 0;
        for(auto it : g[u]) {
            int v = it.ff, wt = it.ss;
            if(v ^ p) {
                int left = (ind - 1 >= 0 ? pref[ind - 1] : 0);
                int right = (ind + 1 < k ? suff[ind + 1] : 0);
                up[v] = max(up[v], wt + max(left, right));
                ind++;
            }
        }

        for(auto it : g[u]) {
            int v = it.ff, wt = it.ss;
            if(v ^ p) {
                up[v] = max(up[v], wt + up[u]);
                dfs_up(v, u);
            }
        }
    };

    dfs_down(1, 0);
    dfs_up(1, 0);

    // for(int i = 1; i <= n; i++) cerr<<down[i]<<" "; cerr<<endl;
    // for(int i = 1; i <= n; i++) cerr<<up[i]<<" "; cerr<<endl;

    int mx = 0;
    for(int i = 1; i <= n; i++) {
        mx = max(mx, down[i] + up[i]);
    }

    cout<<2 * sum - mx<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/