#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) int(x.size())
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int siv[N];
vector<int> di[N];

void solve() {
    int n, k; cin>>n>>k;
    set<int> cur;
    for(int i = n; i > 1; i--) if(siv[i] == i) {
        int ct = 0;
        set<int> tmp;
        for(int j = i; j <= n; j += i) {
            if(cur.count(j)) continue;
            ct++;
            tmp.insert(j);
            for(int k : di[j]) {
                if(cur.count(k) || tmp.count(k)) continue;
                ct++;
                tmp.insert(k);
            }
        }
        if(sz(cur) + ct > k) {cout<<"No"<<endl; return; }
        for(int x : tmp) cur.insert(x);
        if(sz(cur) == k) break;
        if(sz(cur) == k - 1) {cur.insert(1); break; }
    }
    if(sz(cur) ^ k) {cout<<"No"<<endl; return; }
    cout<<"Yes"<<endl;
    for(int x : cur) cout<<x<<" "; cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    iota(siv, siv + N, 0LL);
    for(int i = 2; i < N; i++) {
        if(siv[i] ^ i) continue;
        di[i].push_back(i);
        for(int j = i + i; j < N; j += i) {
            if(siv[j] == j) siv[j] = i;
            di[j].push_back(i);
        }
    }

    // for(int i = 1; i <= 100; i++) {
    //     cerr<<i<<" -> ";
    //     for(int j : di[i]) cerr<<j<<" "; cerr<<endl;
    // }

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}