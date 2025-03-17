#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
#define Mat array<bitset<N>, N>
#define Vec bitset<N>
using namespace std;
const int mod = 1e9 + 7;
const int N = 505;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

Mat adj;
Mat dp[31];

void solve() {
    int n; cin>>n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int x; cin>>x;
            if(x) adj[i][j] = 1;
        }
    }

    dp[0] = adj;
    for(int k = 1; k < 31; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dp[k - 1][i][j]) {
                    dp[k][i] |= dp[k - 1][j];
                }
            }
        }
    }

    int q; cin>>q;
    while(q--) {
        int k, u; cin>>k>>u;
        Vec cur;
        cur[u] = 1;
        for(int j = 30; j >= 0; j--) {
            if((k >> j) & 1) {
                Vec tmp;
                for(int i = 1; i <= n; i++) {
                    if(cur[i])
                        tmp |= dp[j][i];
                }
                cur = tmp;
            }
        }
        vector<int> ans;
        for(int i = 1; i <= n; i++) {
            if(cur[i]) ans.push_back(i);
        }
        if(ans.size()) {
            cout<<(int) ans.size()<<endl;
            for(auto it : ans) cout<<it<<" "; cout<<endl;
        } else {
            cout<<0<<endl;
            cout<<-1<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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