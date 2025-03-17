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
    int n, k; cin>>n>>k;
    vector<int> v(n);
    o_set<array<int, 2>> st;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        mp[v[i]]++;
        st.insert({v[i], i});
    }
    // for(auto [a, b] : mp) cerr<<a<<" -> "<<b<<endl;
    int ans = 0, cur = 0, cnt = 0, prv = -1;
    deque<int> dq;
    for(auto [a, b] : mp) {
        if(a != prv + 1) {
            cur = b;
            cnt = 1;
            dq.clear();
        } else {
            if(cnt < k) {
                cur += b;
                cnt++;
            } else if(cnt == k) {
                cur -= mp[dq.front()];
                dq.pop_front();
                cur += b;
            }
        }
        dq.push_back(a);
        prv = a;
        ans = max(ans, cur);
    }
    cout<<ans<<endl;
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