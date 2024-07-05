#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
vector<int> sz(N, 0);
vector<int> g[N];
int n, k, cnt = 0;

int binPow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

void dfs(int node, int par, int mid) {
    sz[node] = 1;
    for(auto child : g[node]) {
        if(child ^ par) {
            dfs(child, node, mid);
            sz[node] += sz[child];
        }
    }
    if(sz[node] >= mid && cnt < k && par != -1) {
        cnt++;
        sz[node] = 0;
    }
}

void solve() {
    int n, x; cin>>n>>x;
    x++;
    vector<int> v(n), pref(n + 1);
    for(int i = 1; i <= n; i++) {
        cin>>v[i - 1];
        pref[i] = pref[i - 1] ^ v[i - 1];
    }
    int ans = -1;

    auto cutCnt = [&] (int mask) {
        if((pref[n] & mask) != pref[n]) return -1LL;
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if((pref[i] & mask) == pref[i]) {
                cnt++;
            }
        }
        return cnt;
    };

    for(int i = 31; i >= 0; i--) {
        int mask = (1LL << i);
        if(x & mask) {
            int p =  (x ^ mask) | (mask - 1);
            ans = max(ans, cutCnt(p));
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 