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
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    auto ans = v;
    ans.push_back(0);

    int id = -1;
    for(int i = 0; i < n; i++) {
        if(v[i] != -1 && v[i] != 1) {
            id = i;
            break;
        }
    }

    int sm = 0, mx = 0, mn = 0;
    if(id != -1) {
        for(int i = id + 1; i < n; i++) {
            sm += v[i];
            mx = max(mx, sm);
            mn = min(mn, sm);
        }
        int f1 = mx, f2 = mn;
        
        sm = 0, mx = 0, mn = 0;
        
        for(int i = id - 1; i >= 0; i--) {
            sm += v[i];
            mx = max(mx, sm);
            mn = min(mn, sm);
        }
        
        f1 += mx;
        f2 += mn;

        // cerr<<f1<<" "<<f2<<endl;

        for(int j = v[id] + f2; j <= v[id] + f1; j++) ans.push_back(j);
    }

    sm = 0, mx = 0, mn = 0;

    if(id == -1) {
        for(int i = 0; i < n; i++) {
            sm += v[i];
            mx = max(mx, sm);
            if(sm < 0) sm = 0;
        }
        sm = 0;
        for(int i = 0; i < n; i++) {
            sm += v[i];
            mn = min(mn, sm);
            if(sm > 0) sm = 0;
        }
    } else {
        for(int i = 0; i < id; i++) {
            sm += v[i];
            mx = max(mx, sm);
            if(sm < 0) sm = 0;
        }
        sm = 0;
        for(int i = 0; i < id; i++) {
            sm += v[i];
            mn = min(mn, sm);
            if(sm > 0) sm = 0;
        }

        sm = 0;
        for(int i = id + 1; i < n; i++) {
            sm += v[i];
            mx = max(mx, sm);
            if(sm < 0) sm = 0;
        }
        sm = 0;
        for(int i = id + 1; i < n; i++) {
            sm += v[i];
            mn = min(mn, sm);
            if(sm > 0) sm = 0;
        }
    }

    for(int i = 1; i <= mx; i++) ans.push_back(i);
    for(int i = -1; i >= mn; i--) ans.push_back(i);

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout<<sz(ans)<<endl;
    for(auto it : ans) cout<<it<<" "; cout<<endl;
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