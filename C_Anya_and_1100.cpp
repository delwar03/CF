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
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    string s; cin>>s;
    int n = (int) s.size();

    int cnt = 0;

    for(int i = 0; i + 3 < n; i++) {
        int f = s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0';
        if(f) cnt++;
    }

    int q; cin>>q;
    while(q--) {
        int i, x; cin>>i>>x;
        --i;
        if(x == 0) {
            if(s[i] == '1') {
                if(i + 3 < n && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') {
                    cnt--;
                }
                if(i - 1 >= 0 && s[i - 1] == '1' && i + 2 < n && s[i + 1] == '0' && s[i + 2] == '0') {
                    cnt--;
                }
                if(i + 1 < n && s[i + 1] == '0' && i - 2 >= 0 && s[i - 1] == '1' && s[i - 2] == '1') {
                    cnt++;
                }
                if(i - 3 >= 0 && s[i - 1] == '0' && s[i - 2] == '1' && s[i - 3] == '1') {
                    cnt++;
                }
            }
            s[i] = '0';
        } else {
            if(s[i] == '0') {
                if(i + 1 < n && s[i + 1] == '0' && i - 2 >= 0 && s[i - 1] == '1' && s[i - 2] == '1') {
                    cnt--;
                }
                if(i - 3 >= 0 && s[i - 1] == '0' && s[i - 2] == '1' && s[i - 3] == '1') {
                    cnt--;
                }
                if(i + 3 < n && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') {
                    cnt++;
                }
                if(i - 1 >= 0 && s[i - 1] == '1' && i + 2 < n && s[i + 1] == '0' && s[i + 2] == '0') {
                    cnt++;
                }
            }
            s[i] = '1';
        }
        cout<<(cnt ? "YES" : "NO")<<endl;
    }
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

/*
i/p: 
o/p: 
*/