#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dp(n + 1), val;

    function<int(int, int)> dfs = [&] (int u, int p) {
        int mxChild = -1, mxVal = 0;
        for(auto v : g[u]) {
            if(v ^ p) {
                int cur = dfs(v, u);
                if(1 + cur > mxVal) {
                    mxVal = 1 + cur;
                    mxChild = v;
                }
            }
        }

        for(auto v : g[u]) {
            if(v ^ p) {
                if(v ^ mxChild) {
                    val.push_back(1 + dp[v]);
                }
            }
        }
        return dp[u] = mxVal;
    };

    int cur = dfs(1, 0);
    sort(val.rbegin(), val.rend());
    vector<int> tmp;
    tmp.push_back(cur);
    for(int i = 0; i < (int) val.size(); i++) {
        if(i + 1 < (int) val.size()) {
            tmp.push_back(val[i] + val[i + 1]);
            i++;
        } else {
            tmp.push_back(val[i]);
        }
    }

    tmp.resize(n - 1);
    cur = n - 1;
    for(int i = 0; i < n - 1; i++) {
        cur -= tmp[i];
        cout<<cur<<" \n"[i == n - 2];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/