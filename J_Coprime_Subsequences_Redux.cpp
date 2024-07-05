#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int INF = 1e15 + 10;
const int N = 100010;

int cnt[N], f[N], g[N];

int binPow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) {
            res = (res * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, m = N; cin>>n>>m;
    vector<int> v(n);
    for(auto &x : v) {
        cin>>x;
        cnt[x]++;
    }

    for(int i = 1; i <= m; i++) {
        int tot = 0;
        for(int j = i; j <= m; j += i) tot += cnt[j];

        g[i] = binPow(2, tot) - 1;
    }

    for(int i = m; i > 0; i--) {
        f[i] = g[i];
        for(int j = 2 * i; j <= m; j += i) {
            f[i] = (f[i] - f[j] + M) % M;
        }
    }
    for(int i = 1; i <= m; i++)
        cout<<f[i]<<" ";
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 