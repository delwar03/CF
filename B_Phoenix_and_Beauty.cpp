#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    map<int, int> mp;
    for(auto &x : v) {cin>>x; mp[x]++;}
    if(mp.size() > k) {
        cout<<-1<<endl;
        return;
    }
    vector<int> ans;
    int l = ans.size(), ind = 0;
    for(auto it : mp) ans.push_back(it.first);
    while(ans.size() < k) {
        ans.push_back(ans[ind++]);
    }
    // for(auto it : ans) cout<<it<<" "; cout<<endl;
    assert(ans.size() == k);
    cout<<100 * k<<endl;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < k; j++) cout<<ans[j]<<" ";
    }
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 