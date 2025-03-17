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
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int prime[N];
vector<int> divi[N];

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int mx = 0, g = 0;
    for(auto &x : v) {
        cin>>x;
        mx = max(mx, x);
        g = __gcd(g, x);
    }

    if(g != 1) {cout<<"not coprime"<<endl; return; }

    vector<int> vis(mx + 1);

    for(int i : v) {
        for(int j : divi[i]) {
            if(vis[j]) {cout<<"setwise coprime"<<endl; return; }
            vis[j] = 1;
        }
    }
    cout<<"pairwise coprime"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < N; i++) prime[i] = i;

    for(int i = 2; i < N; i++) {
        if(prime[i] == i) {
            for(int j = i; j < N; j += i) {
                divi[j].push_back(i);
                if(prime[j] == j) {
                    prime[j] = i;
                }
            }
        }
    }

    // for(int i = 1; i <= 100; i++) {
    //     cerr<<i<<" -> ";
    //     for(auto j : divi[i]) cerr<<j<<" "; cerr<<endl;
    // }

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}