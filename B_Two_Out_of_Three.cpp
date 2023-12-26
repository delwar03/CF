#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

bool isPossible(int n, vector<int> &v, int sum) {
    bool dp[n + 1][sum + 1];
    for(int i = 0; i <= n; i++) dp[i][0] = true;
    for(int i = 0; i <= sum; i++) dp[0][i] = false;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j - v[i - 1] >= 0) dp[i][j] |= dp[i - 1][j - v[i - 1]];
        }
    }
    return dp[n][sum];
}

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    map<int, int> mp;
    for(auto &x : v) {
        cin>>x;
        mp[x]++;
    }
    map<int, int> mp2; 
    for(auto it : mp) {
        if(it.second != 1) mp2[it.first] = it.second;
    }
    if(mp2.size() <= 1) {cout<<"-1\n"; return; }
    vector<vector<int>> vv(105);
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        if(mp2.find(v[i]) == mp2.end()) ans[i] = 1;
        else {
            vv[v[i]].push_back(i);
        }
    }
    for(int i = 0; i <= 100; i++) {
        if(vv[i].size()) {
             for(int j = 0; j < vv[i].size(); j++) {
                if(j == 0) ans[vv[i][j]] = 1;
                else ans[vv[i][j]] = 2;
             }
        }
    }

    int f = 0;
    for(int i = 0; i <= 100; i++) {
        if(vv[i].size()) {
             for(int j = 0; j < vv[i].size(); j++) {
                if(j == 0) ans[vv[i][j]] = 1;
                else ans[vv[i][j]] = 3;
                f = 1;
            }
        }
        if(f) break;
    }
    for(auto it : ans) cout<<it<<" "; cout<<endl;
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