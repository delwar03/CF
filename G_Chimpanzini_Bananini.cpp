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
    int q; cin>>q;
    int f = 0, tot = 0, sz = 0, cur = 0;
    deque<int> dq;

    while(q--) {
        int t; cin>>t;
        if(t == 1) {
            if(sz(dq)) {
                int x = (f ? dq.front() : dq.back()); (f ? dq.pop_front() : dq.pop_back());
                (f ? dq.push_back(x) : dq.push_front(x));
                cur -= x * (sz - 1);
                cur += tot - x;
            }
        } else if(t == 2) {
            cur = (sz + 1) * tot - cur;
            f ^= 1;
        } else {
            int k; cin>>k;
            (f ? dq.push_front(k) : dq.push_back(k));
            sz += 1;
            cur += k * sz; tot += k;
        }
        cout<<cur<<endl;
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