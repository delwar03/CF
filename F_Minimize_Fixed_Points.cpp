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

bool isPrime(int n) {
    return n >= 2 && siv[n] == n;
}

void solve() {
    int n; cin >> n;
    vector<int> ans(n + 1, -1);
    ans[1] = 1;
    for(int i = n; i > 1; i--) {
        if(isPrime(i) && 2 * i > n) {ans[i] = i; continue; }
        if(!isPrime(i)) continue;
        vector<int> rem;
        for(int j = i + i; j <= n; j += i) if(ans[j] == -1) rem.push_back(j);
        rem.push_back(i);
        for(int j = i, id = 0; j <= n; j += i) if(ans[j] == -1) {
            ans[j] = rem[id++];
        }
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    iota(siv, siv + N, 0LL);
    for(int i = 2; i < N; i++) {
        if(siv[i] ^ i) continue;
        for(int j = i; j < N; j += i) {
            if(siv[j] == j) siv[j] = i;
        }
    }

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}