#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, m; cin>>n>>m;
    vector<int> a(n), b(n);
    map<int, vector<int>> mp;
    map<int, int> c;
    for(auto &x : a) cin>>x;
    for(int i = 0; i < n; i++) {
        cin>>b[i];
        if(mp.count(a[i] - b[i])) {
            if(b[i] < mp[a[i] - b[i]][0]) {
                mp[a[i] - b[i]] = {b[i], i};
            }
        } else {
            mp[a[i] - b[i]] = {b[i], i};
        }
    }
    for(int i = 0; i < m; i++) {
        int x; cin>>x;
        c[x]++;
    }

    int ans = 0;
    
    for(auto it : mp) {
        int y = it.second[0], i = it.second[1], x = a[i];
        // cerr<<x<<" "<<y<<endl;
        auto ind = c.lower_bound(x);
        while(ind != c.end()) {
            int val = (*ind).first;
            int cnt = (*ind).second;
            int div = (val - y) / (x - y);
            ans += 2 * cnt * div;
            c.erase(ind);
            c[val - (x - y) * div] += cnt;
            ind = c.lower_bound(x);
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/