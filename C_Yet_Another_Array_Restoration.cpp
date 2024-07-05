#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;

vector<int> getFactors(int n) {
    vector<int> res;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(n / i != i) {
                res.push_back(n / i);
            }
        }
    }
    sort(res.begin(), res.end());

    return res;
}

void solve() {
    int n, x, y; cin>>n>>x>>y;
    if(x < y) swap(x, y);
    int dif = x - y;
    auto factors = getFactors(dif);

    // cerr<<x<<" "<<y<<endl;
    // for(auto it : factors) cerr<<it<<" "; cerr<<endl;

    for(auto it : factors) {
        vector<int> ans;
        bool hobe = false;
        int p = x;
        while(ans.size() < n && p > 0) {
            ans.push_back(p);
            if(p == y) hobe = true;
            p -= it;
        }

        p = x + it;
        while(ans.size() < n) {
            ans.push_back(p);
            if(p == y) hobe = true;
            p += it;
        }

        if(hobe) {
            for(auto val : ans) cout<<val<<" "; cout<<endl;
            return;
        }
    }
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
