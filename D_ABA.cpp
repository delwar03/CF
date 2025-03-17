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
    string s; cin>>s;
    int n = (int) s.size();
    vector<int> pos[26];
    for(int i = 0; i < n; i++) {
        pos[s[i] - 'A'].push_back(i);
    }
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        if(pos[i].size() <= 1) continue;
        auto vec = pos[i];
        int sz = (int) vec.size();
        int sm = 0;
        for(int j = sz - 1; j >= 0; j--) {
            ans += sm - (vec[j] + 1) * (sz - j - 1);
            sm += vec[j];
        }
    }
    cout<<ans<<endl;
}

/*
ABCACC
A -> 0 3
C -> 2 4 5
ans = 2 + 1 + 2
*/

/*
    2 5 7 9 10

    ans =  (5 - 2 - 1) + (7 - 2 - 1) + (9 - 2 - 1) + (10 - 2 - 1)
    v[i] -> sum(v[i + 1]...v[n - 1]) - (v[i] + 1) * (n - i - 1)
*/

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