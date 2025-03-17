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
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m, k; cin>>n>>m>>k;
    vector<vector<int>> keys(m);
    vector<int> res(m);
    for(int i = 0; i < m; i++) {
        int len; cin>>len;
        for(int j = 0; j < len; j++) {
            int x; cin>>x;
            --x;
            keys[i].push_back(x);
        }
        char ch; cin>>ch;
        res[i] = (ch == 'o');
    }

    int ans = 0;
    for(int i = 0; i < (1LL << n); i++) {
        int f = 1;
        for(int j = 0; j < m; j++) {
            int cnt = 0;
            for(int x : keys[j]) {
                if(i >> x & 1) cnt++;
            }
            if(cnt >= k) {
                if(!res[j]) {f = 0; break; }
            } else {
                if(res[j]) {f = 0; break; }
            }
            if(!f) break;
        }
        ans += f;
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