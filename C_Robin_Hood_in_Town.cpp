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
    vector<int> v(n);
    int sm = 0, mxInd = -1, mx = -1;
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        sm += v[i];
        if(v[i] > mx) {
            mx = v[i];
            mxInd = i;
        }
    }

    // cerr<<mx<<" "<<mxInd<<endl;

    auto f = [&] (int x) {
        int avg = (sm + x);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(2 * n * v[i] < avg) cnt++;
        }
        return 2 * cnt > n;
    };

    int l = 0, r = 1e15, best = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        v[mxInd] += mid;
        if(f(mid)) {
            best = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
        v[mxInd] -= mid;
    }
    cout<<best<<endl;
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