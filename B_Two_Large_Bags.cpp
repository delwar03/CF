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
    int n; cin>>n;
    vector<int> freq(n + 2), mark(n + 2);
    for(int i = 0, x; i < n; i++) {
        cin>>x, freq[x] += 1;
        if(freq[x] >= 2) mark[x] = 1;
    }

    for(int i = 1; i <= n; i++) {
        while(freq[i] > 2) {
            freq[i] -= 1;
            freq[i + 1] += 1;
            if(freq[i + 1] >= 2) mark[i + 1] = 1;
        }

        if(freq[i] & 1) {
            if(!mark[i]) {cout<<"No"<<endl; return; }
        }
        int f = 1;
        for(int i = 1; i <= n; i++) {
            // cerr<<freq[i]<<" \n"[i == n];
            if(freq[i] & 1) f = 0;
        }
        if(f) {cout<<"Yes"<<endl; return; }
    }

    cout<<"No"<<endl;
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