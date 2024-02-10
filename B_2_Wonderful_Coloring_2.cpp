#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    map<int, int> mp;
    vector<int> v[n + 1];
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        v[x].push_back(i);
        mp[x]++;
    }
    vector<int> ans(n), baki;
    for(auto it : mp) {
        if(it.second >= k) {
            int x = it.first;
            int col = 1;
            for(int j = 0; j < k; j++) {
                ans[v[x][j]] = col++;
            }
        } else {
            int x = it.first;
            for(auto it1 : v[x]) baki.push_back(it1);
        }
    }
    int col = 1, elem = baki.size() / k;
    for(int i = 0; i < elem * k; i++) {
        ans[baki[i]] = col++;
        if(col > k) col = 1;
    }
    // cout<<"baki: ";
    // for(auto it : baki) cout<<it<<" "; cout<<endl;
    for(auto it : ans) cout<<it<<" "; cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        // cout<<"Scenario #"<<c++<<":\n";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/