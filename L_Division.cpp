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
    int p, q; cin>>p>>q;
    map<int, int> Qmp;

    int i = 2, tmp = q;
    while(i * i <= tmp) {
        while(tmp % i == 0) {
            Qmp[i]++;
            tmp /= i;
        }
        i++;
    }
    if(tmp > 1) Qmp[tmp]++;

    int mx = 1;

    for(auto [x, y] : Qmp) {
        int tmp = p, cnt = 0;
        while(tmp % x == 0) tmp /= x, cnt++;
        tmp = p;
        if(cnt >= y) {
            int d = cnt - y + 1;
            while(d--) tmp /= x;
        }
        mx = max(mx, tmp);
    }

    cout<<mx<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto f = [&] (int p, int q) {
        int mx = -1;
        for(int i = 1; i * i <= p; i++) {
            if(p % i == 0) {
                int d = p / i;
                if(i % q) mx = max(mx, i);
                if(d % q) mx = max(mx, d);
            }
        }
        return mx;
    };

    // for(int i = 1; i <= 100; i++) {
    //     for(int j = 2; j <= 100; j++) {
    //         cerr<<"i: "<<i<<", j: "<<j<<", ans: "<<f(i, j)<<endl;
    //     }
    // }

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}