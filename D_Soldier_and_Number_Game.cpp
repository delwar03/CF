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
const int N = 5e6 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int siv[N], F[N];

void solve() {
    int a, b; cin >> a >> b;
    cout << F[a] - F[b] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    iota(siv, siv + N, 0LL);
    for(int i = 2; i < N; i++) {
        if(siv[i] ^ i) continue;
        for(int j = i; j < N; j += i) {
            if(siv[j] == j) siv[j] = i;
            F[j] = 1 + F[j / i];
        }
    }

    // for(int i = 0; i <= 100; i++) cerr << i << " -> " << F[i] << endl;

    for(int i = 1; i < N; i++) F[i] += F[i - 1];

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}