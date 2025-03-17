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
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> v(n), pos, neg;
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        if(v[i] >= 0) {
            pos.push_back(v[i]);
        } else {
            neg.push_back(v[i]);
        }
    }

    auto f = [&] (int x) {
        int cur = 0, i = 0, j = 0;
        while(i < sz(pos) && j < sz(neg)) {
            if(cur + pos[i] <= x) {
                cur += pos[i++];
            } else {
                cur += neg[j++];
            }
            if(cur < 0) cur = 0;
        }
        while(i < sz(pos)) cur += pos[i++];
        return cur <= x;
    };

    int lo = 0, hi = INF, best = -1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
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