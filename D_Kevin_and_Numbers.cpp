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
    int n, m; cin>>n>>m;
    vector<int> a(n), b(m);
    int sm1 = 0, sm2 = 0;
    for(auto &x : a) cin>>x, sm1 += x;
    for(auto &x : b) cin>>x, sm2 += x;

    if(sm1 ^ sm2) {cout<<"No"<<endl; return; }

    map<int, int> mp;
    for(int x : a) mp[x] += 1;

    vector<int> tmp, del;
    for(int x : b) {
        if(mp[x] > 0) {
            tmp.push_back(x);
            mp[x] -= 1;
        } else {
            del.push_back(x);
        }
    }
    int f = 0;

    for(auto x : del) {
        if(f) return;

        function<void(int)> chk = [&] (int x) {
            if(f) return;
            if(x == 1) {
                if(mp[x] > 0) {mp[x] -= 1, tmp.push_back(x);}
                else {cout<<"No"<<endl; f = 1;}
                return;
            }
            if(mp[x] > 0) {mp[x] -= 1, tmp.push_back(x); return;}
            chk(x / 2);
            chk((x + 1) / 2);
        };

        chk(x);
        if(sz(tmp) > n) {cout<<"No"<<endl; return; }
    }

    if(sz(tmp) != n) {cout<<"No"<<endl; return; }

    sort(a.begin(), a.end());
    sort(tmp.begin(), tmp.end());

    for(int i = 0; i < n; i++) if(a[i] ^ tmp[i]) {
        cout<<"No"<<endl; return;
    }

    cout<<"Yes"<<endl;
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