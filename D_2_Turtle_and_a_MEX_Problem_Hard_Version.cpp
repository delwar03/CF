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
    int n, m; cin>>n>>m;
    vector<set<int>> v(n);
    for(int i = 0; i < n; i++) {
        int k; cin>>k;
        for(int j = 0; j < k; j++) {
            int x; cin>>x;
            v[i].insert(x);
        }
    }

    auto getMEX = [&] (set<int> st, int cur) {
        int j = cur;
        while(st.count(j)) j++;
        return j;
    };

    map<int, priority_queue<int>> mp;
    vector<pair<int, int>> mex(n);
    int mx = 0;

    for(int i = 0; i < n; i++) {
        int cur1 = getMEX(v[i], 0);
        int cur2 = getMEX(v[i], cur1 + 1);
        mex[i] = {cur1, cur2};
        
        mx = max(mx, cur2);
        mp[cur1].push(cur2);
    }
    
    int ans = 0, sm = 0;

    vector<int> g[mx + 10];

    for(int i = 0; i < n; i++) {
        int u = mex[i].ff, v = mex[i].ss;
        if(u ^ v)
            g[u].push_back(v);
    }

    for(int i = 0; i <= mx; i++) {
        if(mp.count(i) && mp[i].size() >= 2) {
            for(int j = 0; j < i; j++) {
                // cerr<<i<<endl;
                g[j].push_back(i);
            }
        }
    }

    vector<int> maxCanGo(mx + 10, -1);

    function<int(int)> dfs = [&] (int u) {
        if(~maxCanGo[u]) return maxCanGo[u];
        int mx = u;
        for(auto v : g[u]) {
            mx = max(mx, dfs(v));
        }
        return maxCanGo[u] = mx;
    };

    for(int i = 0; i <= mx; i++) {
        maxCanGo[i] = dfs(i);
    }


    int curMax = 0;
    for(auto it : mex) {
        int u = it.ff, v = it.ss;
        curMax = max(curMax, u);
        if(mp[u].size() >= 2) {
            curMax = max(curMax, maxCanGo[u]);
        }
    }

    for(auto &x : maxCanGo) {
        x = max(x, curMax);
    }

    // for(int i = 0; i <= mx; i++) cerr<<maxCanGo[i]<<" "; cerr<<endl;

    for(int i = 0; i <= min(m, mx); i++) {
        ans += maxCanGo[i];
        sm += i;
    }

    if(mx < m) {
        ans += m * (m + 1) / 2 - sm;
    }

    cout<<ans<<endl;
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