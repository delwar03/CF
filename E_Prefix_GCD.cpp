#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    multiset<int> mst;
    int g = INF;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        mst.insert(x);
        g = min(g, x);
    }

    int ans = g;
    mst.erase(mst.find(g));
    while(mst.size()) {
        int tmp = g;
        for(auto x : mst) {
            tmp = min(tmp, __gcd(g, x));
        }

        if(tmp == g) {
            ans += (int) mst.size() * g;
            break;
        } else {
            int del = -1;
            for(auto x : mst) {
                if(__gcd(g, x) == tmp) {
                    del = x;
                    break;
                }
            }
            if(~del) {
                ans += tmp;
                mst.erase(mst.find(del));
            }
            g = tmp;
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/