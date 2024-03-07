#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
vector<vector<int>> dir = {
    {1, 1},
    {1, -1},
    {-1, 1},
    {-1, -1}
}; // DURL

bool isValid(int i, int j) {
    return i >= 0 && i < 7 && j >= 0 && j < 7;
}

void solve() {
    int n; cin>>n;
    set<int> st;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        mp[x]++;
        st.insert(x);
    }
    int p = (1LL << 31) - 1;
    int ans = 0;
    for(auto it : st) {
        // st.erase(it);
        if(st.count(it ^ p)) {
            int val = min(mp[it], mp[it ^ p]);
            ans += val;
            mp[it] -= val;
            mp[it ^ p] -= val;
        }
    }
    for(auto it : mp) ans += it.second;
    cout<<ans<<endl;
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