#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

int Inv[N], Fact[N], revFact[N];

int mult(int a, int b) {
    return (a % mod * b % mod) % mod;
}

int add(int a, int b) {
    a += b;
    return a >= mod ? a - mod : a;
}

int sub(int a, int b) {
    a -= b;
    return a < 0 ? a + mod : a;
}

void solve() {
    int n; cin>>n;
    int ans = mult(n, Fact[n]);
    for(int k = 1; k <= n - 1; k++) {
        ans = sub(ans, mult(Fact[n], revFact[k]));
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sz = 5;
    vector<int> tmp(sz);
    iota(tmp.begin(), tmp.end(), 1LL);
    vector<vector<int>> comb;

    do {
        comb.push_back(tmp);
    } while(next_permutation(tmp.begin(), tmp.end()));

    sort(comb.begin(), comb.end());

    // for(auto vec : comb) {
    //     for(auto x : vec) cerr<<x<<" "; cerr<<endl;
    // }

    Inv[1] = 1;
    for(int i = 2; i < N; i++) Inv[i] = mod - (mod / i) * Inv[mod % i] % mod;

    Fact[0] = Fact[1] = revFact[0] = revFact[1] = 1;
    for(int i = 2; i < N; i++) {
        Fact[i] = mult(Fact[i - 1], i);
        revFact[i] = mult(revFact[i - 1], Inv[i]);
    }

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
