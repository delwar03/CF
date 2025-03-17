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
    int n, x; cin>>n>>x;
    deque<int> dq;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        dq.push_back(x);
    }

    sort(dq.begin(), dq.end());

    int med = (n - 1) / 2;

    if(dq[med] == x) {cout<<0<<endl; return; }

    int ind = lower_bound(dq.begin(), dq.end(), x) - dq.begin();
    int cnt = 1;
    if(ind <= med) {
        dq.insert(dq.begin() + ind, x);
        while(dq[(sz(dq) - 1) / 2] != x) dq.push_front(dq.front()), cnt++;
    } else {
        dq.insert(dq.begin() + ind, x);
        while(dq[(sz(dq) - 1) / 2] != x) dq.push_back(dq.back()), cnt++;
    }

    cout<<cnt<<endl;
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