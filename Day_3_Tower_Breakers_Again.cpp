#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int g[N];

int magic(int n) {
    int &ans = g[n];
    if(~ans) return ans;

    ans = 0;
    set<int> st;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            int z = n / i;
            if(z & 1) st.insert(magic(i));
            else st.insert(0);
            if(i * i != n && i != 1) {
                z = i;
                if(z & 1) st.insert(magic(n / i));
                else st.insert(0);
            }
        }
    }
    while(st.count(ans)) ans++;
    return ans;
}

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int xr = 0;
    for(auto &x : v) {
        cin>>x;
        xr ^= g[x];
    }
    cout<<(xr ? "1" : "2")<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(g, -1, sizeof g);

    g[0] = g[1] = 0;

    for(int i = 2; i < N; i++) g[i] = magic(i);

    // for(int i = 0; i <= 100; i++) cerr<<i<<" -> "<<g[i]<<endl;

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