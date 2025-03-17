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

struct Event {
    int a, p, b, q;
};

// S(better) -> p * b < q * a
// T(better)

void solve() {
    int n, x; cin>>n>>x;
    vector<Event> events(n);
    for(auto &e : events) cin>>e.a>>e.p>>e.b>>e.q;

    // for(auto &[a, p, b, q] : events) cerr<<a<<" "<<p<<" "<<b<<" "<<q<<endl;

    for(auto &[a, p, b, q] : events) {
        if(p * b > q * a) {
            swap(a, b);
            swap(p, q);
        }
    }
    // cerr<<"----------"<<endl;
    // for(auto &[a, p, b, q] : events) cerr<<a<<" "<<p<<" "<<b<<" "<<q<<endl;

    auto f = [&] (int m) {
        int cost = 0;
        // (rem + b - 1) / b = y
        for(auto &[a, p, b, q] : events) {
            int mn = INF;
            for(int y = 0; y <= 100; y++) {
                int c = y * q, rem = m - y * b;
                if(rem > 0) {
                    int x = (rem + a - 1) / a;
                    c += x * p;
                }
                mn = min(mn, c);
            }
            cost += mn;
        }
        return cost <= x;
    };

    int l = 0, r = 1e9 + 10, best = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(f(mid)) {
            best = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
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