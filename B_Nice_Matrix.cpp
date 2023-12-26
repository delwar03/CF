#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

int minVal(int a, int b, int c, int d) {
    vector<int> vec = {a, b, c, d};
    int mn = INF;
    for(int i = 0; i < 4; i++) {
        int tmp = 0;
        for(int j = 0; j < 4; j++) {
            tmp += abs(vec[i] - vec[j]);
        }
        mn = min(mn, tmp);
    }
    return mn;
}

void solve() {
    int n, m; cin>>n>>m;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++) {
        vector<int> tmp(m);
        for(int j = 0; j < m; j++) {
            cin>>tmp[j];
        }
        v.push_back(tmp);
    }
    int ans = 0;
    for(int i = 0; 2 * i < n; i++) {
        for(int j = 0; 2 * j < m; j++) {
            vector<int> tmp;
            tmp.push_back(v[i][j]);
            if(i != n - 1 - i) tmp.push_back(v[n - 1 - i][j]);
            if(j != m - 1 - j) tmp.push_back(v[i][m - 1 - j]);
            if(i != n - 1 - i && j != m - 1 - j) tmp.push_back(v[n - 1 - i][m - 1 - j]);
            int mn = INF;
            for(auto x : tmp) {
                int tm = 0;
                for(auto y : tmp) tm += abs(y - x);
                mn = min(mn, tm);
            }
            ans += mn;
        }
    }
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