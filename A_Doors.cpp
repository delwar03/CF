#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
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

void solve() {
    int n, k; cin>>n>>k;
    vector<int> C(n), A(n);
    for(auto &x : C) cin>>x;
    for(auto &x : A) cin>>x;

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0LL);
    sort(ord.begin(), ord.end(), [&] (int i, int j) {
        return A[i] - C[i] < A[j] - C[j];
    });

    auto f = [&] (int m) {
        auto CC = C;
        for(int i = 0; i < m; i++) CC[ord[i]] = 0;
        int kk = k;
        for(int i = 0; i < n; i++) {
            if(CC[i] > kk) return false;
            kk += A[i] - CC[i];
        }
        return true;
    };

    int lo = 0, hi = n, best = -1;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(f(mid)) {
            best = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout<<best<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}