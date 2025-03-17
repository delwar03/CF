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
const int N = 1e6 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> vals;
int BIT[N], sumBIT[N];

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) {
        cin>>x;
        vals.push_back(x);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    auto getId = [&] (int x) {
        int ind = upper_bound(vals.begin(), vals.end(), x) - vals.begin();
        return ind;
    };

    for(auto &x : v) x = getId(x);

    auto add = [&] (int x, int val, int f) {
        if(!f) {
            for(int i = x; i < N; i += i & -i) BIT[i] += val;
        } else {
            for(int i = x; i < N; i += i & -i) sumBIT[i] += val;
        }
    };

    auto sum = [&] (int x, int f) {
        int ret = 0;
        if(!f) {
            for(int i = x; i > 0; i -= i & -i) ret += BIT[i];
        } else {
            for(int i = x; i > 0; i -= i & -i) ret += sumBIT[i];
        }
        return ret;
    };

    for(int i = n - 1; i >= 0; i--) {
        add(v[i], +1, 0);
    }

    for(int i = 0; i < n; i++) {
        add(v[i], -1, 0);
        int cnt = sum(v[i] - 1, 0);
        add(v[i], cnt, 1);
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int tmp = sum(v[i], 1) - sum(v[i] - 1, 1);
        add(v[i], -tmp, 1);
        ans += sum(v[i] - 1, 1);
    }

    cout<<ans<<endl;
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