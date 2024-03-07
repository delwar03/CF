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
    map<int, int> mp, mp1;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        mp[x]++;
        mp1[x] = i;
    }
    vector<int> b(n), p(n);
    for(auto &x : b) cin>>x;
    for(int i = 0; i < n; i++) {
        if(mp.find(b[i]) == mp.end()) p[i] = 1;
        else {
            if(mp[b[i]] == 1) mp.erase(b[i]);
            else mp[b[i]]--;
        }
    }
    // for(auto it : p) cout<<it<<" "; cout<<endl;
    int x = -1, y = -2;
    for(int i = 0; i < n; i++) {
        if(p[i]) {
            if(x == -1) x = i;
            y = i;
        }
    }
    // if(x == -1) {
    //     cout<<0<<endl;
    //     return;
    // }
    vector<int> now, ind;
    for(int i = 0; i < x; i++) now.push_back(b[i]);
    for(int i = y + 1; i < n; i++) now.push_back(b[i]);
    // for(auto it : now) cout<<it<<" "; cout<<endl;
    for(auto it : now) {
        ind.push_back(mp1[it]);
    }
    int mx = -1, prv = -1, cur = 0;
    for(int i = 0; i < ind.size(); i++) {
        if(ind[i] > prv) {
            prv = ind[i];
            cur++;
        } else {
            prv = ind[i];
            cur = 1;
        }
        mx = max(mx, cur);
    }
    if(mx == -1) mx = n;
    cout<<mx<<endl;
    cout<<n - mx<<endl;
    // cout<<y - x + 1<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 