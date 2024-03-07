#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<vector<int>> v;
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    vector<int> pref(n + 1);
    
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + v[i - 1][0];
    }
    // for(auto it : pref) cerr<<it<<" "; cerr<<endl;
    set<int> winners;
    for(int i = n - 1; i >= 0; i--) {
        winners.insert(v[i][1]);
        if(v[i][0] > pref[i]) break;
    }
    cout<<winners.size()<<endl;
    for(auto it : winners) cout<<it<<" "; cout<<endl;
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