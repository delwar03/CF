#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const int INF = 1e15 + 10;

void solve() {
    int n, m, k; cin>>n>>m>>k;
    map<int, int> mp1, mp2;
    map<int, int> in_b;
    vector<int> a(n), b(m);
    for(auto &x : a) cin>>x;
    for(auto &x : b) {cin>>x; in_b[x]++; mp2[x]++; }

    int cnt = 0;
    for(int i = 0; i < m; i++) {
        if(in_b.count(a[i])) {
            cnt++;
            if(in_b[a[i]] == 1) in_b.erase(a[i]);
            else in_b[a[i]]--;
        }
        mp1[a[i]]++;
    }
    int ans = 0;
    int i = 0, j = m;
    while(j < n) {
        if(cnt >= k) ans++;
        if(mp1[a[i]] > mp2[a[i]]) {
            mp1[a[i]]--;
        } else {
            mp1[a[i]]--;
            cnt--;
        }
        if(mp1[a[j]] < mp2[a[j]]) {
            mp1[a[j]]++;
            cnt++;
        } else {
            mp1[a[j]]++;
        }
        i++;
        j++;
    }
    if(cnt >= k) ans++;
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