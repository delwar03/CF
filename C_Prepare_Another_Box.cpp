#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
    vector<int> a(n), b(n - 1);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    
    sort(a.begin(), a.end());

    auto f = [&] (int x) {
        auto tmp = b;
        tmp.push_back(x);
        sort(tmp.begin(), tmp.end());
        for(int i = n - 1; i >= 0; i--) {
            if(tmp[i] < a[i]) return false;
        }
        return true;
    };

    int l = 1, r = INF, best = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(f(mid)) {
            best = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout<<best<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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