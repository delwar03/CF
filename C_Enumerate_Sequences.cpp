#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

int n, k;
int dp[10][105];
vector<int> v;
vector<vector<int>> ans;

void magic(int ind, int sum, vector<int> &cur) {
    if(ind == n) {
        if(sum % k == 0) {
            ans.push_back(cur);
        }
        return;
    }

    for(int i = 1; i <= v[ind]; i++) {
        cur.push_back(i);
        magic(ind + 1, sum + i, cur);
        cur.pop_back();
    }
}

void solve() {
    cin>>n>>k;
    v.resize(n);
    for(auto &x : v) cin>>x;

    vector<int> tmp;
    magic(0, 0, tmp);

    sort(ans.begin(), ans.end());
    for(auto vec : ans) {
        for(auto it : vec) {
            cout<<it<<" ";
        } cout<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/