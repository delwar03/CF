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
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    string s; cin>>s;

    auto get = [&] (string tmp) {
        sort(tmp.begin(), tmp.end());
        int cnt = 0;
        do {
            cnt += 1;
        } while(next_permutation(tmp.begin(), tmp.end()));
        return cnt;
    };

    // string best = s;
    // int mn = INF;

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         if(s[i] != s[j]) {
    //             char cur = s[i];
    //             s[i] = s[j];
    //             int x = get(s);
    //             if(x < mn) {
    //                 mn = x;
    //                 best = s;
    //             }
    //             s[i] = cur;
    //         }
    //     }
    // }
    // cout<<best<<endl;

    vector<int> freq(26);
    for(auto it : s) freq[it - 'a'] += 1;

    int mx = 0, mn = INF, indMx = -1, indMn = -1;

    for(int i = 0; i < 26; i++) {
        if(freq[i] > mx) {
            mx = freq[i];
            indMx = i;
        }
        if(freq[i] && freq[i] <= mn) {
            mn = freq[i];
            indMn = i;
        }
    }

    // cerr<<indMx<<" "<<indMn<<endl;

    for(auto &it : s) {
        if(it - 'a' == indMn) {
            it = 'a' + indMx;
            break;
        }
    }

    cout<<s<<endl;
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