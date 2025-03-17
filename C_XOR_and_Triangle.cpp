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
    int x; cin>>x;
    int id = 0;
    for(int i = 0; i < 32; i++) if(x >> i & 1) {id = i; break;}
    int y = (1LL << id);
    // cerr<<y<<endl;
    if(__builtin_popcountll(x) > 1) {
        for(int i = id; i >= 0; i--) if(!(x >> i & 1)) y |= (1LL << i);
    }
    id++;
    int tm = x >> id;
    // cerr<<y<<endl;
    while(tm) {
        if(!(tm & 1) && (tm / 2)) y |= (1LL << id);
        tm >>= 1;
        id++;
    }
    int z = x ^ y;
    vector<int> cur = {x, y, z};
    // cerr<<x<<" "<<y<<endl;
    sort(cur.begin(), cur.end());
    cout<<(cur[0] + cur[1] > cur[2] ? y : -1)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int tmp = 8;
    // for(int i = 1; i <= tmp; i++) cerr<<(tmp & i)<<endl;

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}