#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int prm[N];

void solve() {
    int a, b; cin>>a>>b;
    map<int, int> mp_a, mp_b;
    int tmp = a;
    while(tmp > 1) {
        int p = prm[tmp];
        while(tmp % p == 0) mp_a[p]++, tmp /= p;
    }
    tmp = b;
    while(tmp > 1) {
        int p = prm[tmp];
        while(tmp % p == 0) mp_b[p]++, tmp /= p;
    }

    for(auto [a, b] : mp_a) if(!mp_b.count(a)) {cout<<"NO"<<endl; return; }
    for(auto [a, b] : mp_b) if(!mp_a.count(a)) {cout<<"NO"<<endl; return; }

    int x = mp_a.begin()->second, y = mp_b.begin()->second, l = lcm(x, y);
    x = l / x, y = l / y;
    // cerr<<x<<" "<<y<<endl;

    for(auto [a, b] : mp_a) {
        if(mp_a[a] * x != mp_b[a] * y) {cout<<"NO"<<endl; return; }
    }
    cout<<"YES"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    iota(prm, prm + N, 0LL);
    for(int i = 2; i < N; i++) {
        if(prm[i] ^ i) continue;
        for(int j = i + i; j < N; j += i) {
            if(prm[j] == j) prm[j] = i;
        }
    }

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}