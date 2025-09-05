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
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int siv[N];
vector<int> prm;

void solve() {
    int n, m; cin >> n >> m;
    if(n > 20) {cout << -1 << endl; return; }
    int mul = 1;
    for(int i = 0; i < n; i++) {
        if((__int128) mul * prm[i] > m) {cout << -1 << endl; return; }
        mul *= prm[i];
    }

    vector<int> ans(n);
    for(int i = 0; i < n; i++) ans[i] = mul / prm[i];

    for(int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    iota(siv, siv + N, 0LL);
    for(int i = 2; i < N; i++) {
        if(i ^ siv[i]) continue;
        for(int j = i + i; j < N; j += i) {
            if(siv[j] == j) siv[j] = i;
        }
    }

    for(int i = 2; i < N; i++) if(siv[i] == i) prm.push_back(i);

    // int tmp = 1, id = -1;
    // for(int i : prm) {
    //     cerr << i << " ";
    //     if((__int128) tmp * i > INF) {id = i; break;}
    //     tmp *= i;
    // } cerr << endl;

    // cerr << tmp << " " << id << endl;

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}