#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, l, r; cin>>n>>l>>r;
    map<int, int> l_mp, r_mp;
    for(int i = 0; i < l; i++) {
        int x; cin>>x;
        l_mp[x]++;
    }
    for(int i = 0; i < r; i++) {
        int x; cin>>x;
        if(l_mp.find(x) != l_mp.end()) {
            l_mp[x]--;
            if(l_mp[x] == 0) l_mp.erase(x);
        } else {
            r_mp[x]++;
        }
    }
    if(l < r) {
        swap(l, r);
        swap(l_mp, r_mp);
    }
    l = 0, r = 0;
    for(auto it : l_mp) l += it.second;
    for(auto it : r_mp) r += it.second;
    assert(l >= r);
    int ans = 0, dif = (l - r) / 2;
    for(auto it : l_mp) {
        int val = it.first;
        int ache = l_mp[val] / 2;
        l_mp[val] -= 2 * min(ache, dif);
        
        ans += min(ache, dif);
        dif -= min(ache, dif);
        if(dif == 0) break;
    }
    ans += min(l, r) + 2 * dif;
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