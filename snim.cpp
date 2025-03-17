#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e4 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> g(N, -1);
set<int> st;

int f(int n) {
    if(~g[n]) return g[n];
    set<int> cur;
    for(auto it : st) {
        if(n - it >= 0) cur.insert(f(n - it));
    }
    int j = 0;
    while(cur.count(j)) j++;
    return g[n] = j;
};

void solve() {
    int k; cin>>k;
    for(int i = 0; i < k; i++) {
        int x; cin>>x;
        st.insert(x);
    }

    g[0] = 0;
    for(int i = 1; i < N; i++) g[i] = f(i);

    string ans = "";

    int m; cin>>m;
    while(m--) {
        int l; cin>>l;
        int xr = 0;
        for(int i = 0; i < l; i++) {
            int x; cin>>x;
            xr ^= g[x];
        }
        ans += (xr ? "W" : "L");
    }
    cout<<ans<<endl;
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