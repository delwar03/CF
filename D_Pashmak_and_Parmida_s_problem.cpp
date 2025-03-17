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

vector<int> vals, freq(N), pref(N), suff(N);
int BIT[N];

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
        int ind = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
        return ind;
    };

    for(auto &x : v) x = getId(x);

    for(int i = 0; i < n; i++) {
        freq[v[i]]++;
        pref[i] = freq[v[i]];
    }

    // for(int i = 0; i < n; i++) cerr<<pref[i]<<" "; cerr<<endl;

    auto add = [&] (int x, int val) {
        for(int i = x; i <= n; i += i & -i) BIT[i] += val;
    };

    auto sum = [&] (int x) {
        int ret = 0;
        for(int i = x; i > 0; i -= i & -i) ret += BIT[i];
        return ret;
    };

    auto qur = [&] (int l, int r) {
        if(l > r) return 0LL;
        return sum(r) - sum(l - 1);
    };

    for(int i = 0; i < n; i++) add(pref[i], +1);

    freq.assign(N, 0);

    int ans = 0;

    for(int i = n - 1; i >= 0; i--) {
        add(pref[i], -1);
        freq[v[i]]++;
        suff[i] = freq[v[i]];
        ans += qur(suff[i] + 1, n);
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