#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e12 + 10;

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    map<int, vector<int>> ind;
    for(auto &x : a) cin>>x;
    for(int i = 0; i < n; i++) {
        cin>>b[i];
    }
    map<int, int> mp;
    int m; cin>>m;
    vector<int> d(m);
    for(auto &x : d) {cin>>x; mp[x]++;}

    vector<int> vis(n);

    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) vis[i] = 1;
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            ind[b[i]].push_back(i);
        } else {
            if(!ind.count(b[i]))
                ind[b[i]] = {};
        }
    }

    int f = 1;
    for(int i = 0; i < m; i++) {
        if(ind.count(d[i])) {
            if(ind[d[i]].size()) {

                vis[ind[d[i]].back()] = 1;
                ind[d[i]].pop_back();
            }
            f = 1;
        } else {
            f = 0;
        }
    }
    int sm = accumulate(vis.begin(), vis.end(), 0LL);
    
    if(sm == n && f) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; cin>>t;
    while(t--) {
        solve();
    }
}

/*
i/p: 
o/p: 
*/