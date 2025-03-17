#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[N][205];

void solve() {
    int n, m, k; cin>>n>>m>>k;
    vector<vector<int>> g[n + 5];
    for(int i = 0; i < k; i++) {
        int l, r, d, w; cin>>l>>r>>d>>w;
        g[l].push_back({0, w, d});
        g[r + 1].push_back({1, w, d});
    }
    vector<int> nxt(n + 1), val(n + 1);
    multiset<pair<int, int>> st;

    for(int i = 1; i <= n; i++) {
        for(auto it : g[i]) {
            if(it[0] == 0) {
                st.insert({it[1], it[2]});
            } else {
                st.erase(st.find({it[1], it[2]}));
            }
        }
        if(st.size()) {
            auto it = *(--st.end());
            val[i] = it.F;
            nxt[i] = it.S + 1;
        } else {
            val[i] = 0;
            nxt[i] = i + 1;
        }
    }

    function<int(int, int)> magic = [&] (int ind, int tot) {
        if(ind > n) return 0LL;
        int &ans = dp[ind][tot];
        if(~ans) return ans;

        ans = INF;

        if(tot - 1 >= 0)
            ans = min(ans, magic(ind + 1, tot - 1));
        ans = min(ans, val[ind] + magic(nxt[ind], tot));

        return ans;
    };

    memset(dp, -1, sizeof dp);
    cout<<magic(1, m)<<endl;
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