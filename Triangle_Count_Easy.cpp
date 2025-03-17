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
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    if(n == 1) {cout<<0<<endl; return; }

    sort(v.begin(), v.end());

    auto f = [&] (int x) {
        if(x > v[n - 1]) {
            return (v[n - 1] + v[n - 2] > x);
        } else {
            for(int i = 0; i < n; i++) {
                if(x <= v[i]) {
                    int j = lower_bound(v.begin(), v.end(), v[i] + x) - v.begin() - 1;
                    if(j >= 0 && j > i && v[j] < x + v[i]) return true;
                } else {
                    int j = lower_bound(v.begin(), v.end(), v[i] + x) - v.begin() - 1;
                    if(j >= 0 && j > i && v[j] < x + v[i]) return true;
                    j = upper_bound(v.begin(), v.end(), x - v[i]) - v.begin();
                    if(j != n && j != i) return true;
                }
            }
        }
        return false;
    };

    int l = 1, r = INF, bestL = -1, bestR = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(f(mid)) {
            bestR = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    l = 1, r = bestR;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(f(mid)) {
            bestL = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }


    for(int i = 1; i <= 100; i++) {
        cerr<<i<<" -> "<<f(i)<<endl;
    }

    cerr<<bestL<<" "<<bestR<<endl;

    cout<<bestR - bestL + 1<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/