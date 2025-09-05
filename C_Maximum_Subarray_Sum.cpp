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
const int INF = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k; cin>>n>>k;
    string s; cin>>s;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    int mx = 0;
    for(int i = 0; i < n; i++) {
        int j = i;
        while(j < n && s[j] == '1') j++;
        int sm = 0, cur = 0;
        for(int l = i; l < j; l++) {
            sm += v[l];
            cur = max(cur, sm);
            sm = max(0LL, sm);
        }
        mx = max(mx, cur);
        i = j;
    }

    if(mx > k) {cout<<"No"<<endl; return; }

    vector<int> id;
    for(int i = 0; i < n; i++) if(s[i] == '0') id.push_back(i);
    if(!sz(id)) {
        int sm = 0, mx = 0;
        for(int i = 0; i < n; i++) {
            sm += v[i];
            mx = max(mx, sm);
            sm = max(0LL, sm);
        }
        if(mx ^ k) {
            cout<<"No"<<endl;
        } else {
            cout<<"Yes"<<endl;
            for(int i = 0; i < n; i++) cout<<v[i]<<" \n"[i == n - 1];
        }
        return;
    }
    // assert(id != -1);
    int cur = -1;
    for(int i = 0; i + 1 < sz(id); i++) {
        if(id[i] + 1 == id[i + 1]) {cur == id[i]; break; }
    }

    if(cur == -1) {
        cur = id[0];
        int sm = 0, mx = 0;
        for(int i = cur; i >= 0; i--) sm += v[i], mx = max(mx, sm);
        int pp = mx;
        sm = 0; mx = 0;
        for(int i = cur; i <= (sz(id) > 1 ? id[1] : n - 1); i++) sm += v[i], mx = max(mx, sm);
        pp += mx;
        v[cur] = k - pp;
        for(int i = cur + 1; i < n; i++) if(s[i] == '0') v[i] = -INF;
    } else {
        int sm = 0, mx = 0;
        for(int i = cur; i >= 0 && s[i] != '0'; i--) sm += v[i], mx = max(mx, sm);
        v[cur] = k - mx;
        for(int i = cur + 1; i < n; i++) if(s[i] == '0') v[i] = -INF;
    }
    cout<<"Yes"<<endl;

    for(int i = 0; i < n; i++) cout<<v[i]<<" \n"[i == n - 1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}