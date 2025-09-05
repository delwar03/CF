#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int long long
// #define endl '\n'
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
    int n; cin>>n;
    vector<int> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto ask = [&] (int u) {
        cout<<"? 1 1 "<<u<<endl;
        int x; cin>>x;
        return x;
    };

    vector<int> val(n + 1);

    int x = ask(1), f = 0;
    if(x == 1 || x == -1) {
        val[1] = x; f = 1;
    } else {
        if(x == 2) {
            val[1] = 1;
        } else if(x == -2) {
            val[1] = -1;
        } else if(x == 0) {
            cout<<"? 2 1"<<endl;
            x = ask(1);
            val[1] = (x == 2 ? -1 : 1);
            cout<<"? 2 1"<<endl;
        } else {
            assert(false);
        }
    }

    assert(val[1] == -1 || val[1] == 1);

    if(f) {
        for(int i = 2; i <= n; i++) {
            val[i] = ask(i) - val[1];
            assert(val[i] == 1 || val[i] == -1);
        }
    } else {
        vector<int> tmp(n + 1);
        for(int i = 1; i <= n; i++) tmp[i] = ask(i);
        int got = 0;
        for(int i = 2; i <= n; i++) if(tmp[i] == 1 || tmp[i] == -1) { // i -> root
            if(tmp[1] != val[1] + tmp[i]) continue;
            int f = 1;
            for(int j = 2; j <= n; j++) if(i ^ j) { // i -> 1 -> j
                int rem = tmp[j] - tmp[i] - val[1];
                if(rem != 1 && rem != -1) {
                    f = 0; break;
                }
            }
            if(f) {
                val[i] = tmp[i];
                for(int j = 2; j <= n; j++) if(i ^ j) val[j] = tmp[j] - val[i] - val[1];
                got = 1;
                break;
            }
        }
        assert(got);
    }

    cout<<"! ";
    for(int i = 1; i <= n; i++) cout<<val[i]<<" "; cout<<endl;
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