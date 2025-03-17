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
    vector<int> v(n);
    map<int, int> mp;
    for(auto &x : v) {
        cin>>x;
        mp[x] += 1;
    }

    int f = 0;
    vector<int> ans;
    for(auto [a, b] : mp) {
        if(b >= 4) {
            ans.clear();
            for(int i = 0; i < 4; i++) ans.push_back(a);
        } else if(b >= 2) {
            f = 1;
            for(int i = 0; i < 2; i++) ans.push_back(a);
        }
        if(sz(ans) == 4) break;
    }

    if(sz(ans) == 4) {
        for(auto it : ans) cout<<it<<" "; cout<<endl;
        return;
    }
    if(!f) {cout<<-1<<endl; return; }

    assert(sz(ans) == 2);
    int x = ans.back(), ct = 2;
    vector<int> tmp;
    for(int i : v) {
        if(i == x && ct) {ct--; continue;}
        tmp.push_back(i);
    }
    sort(tmp.begin(), tmp.end());
    for(int i = 1; i < sz(tmp); i++) {
        if(2 * x > tmp[i] - tmp[i - 1]) {
            ans.push_back(tmp[i - 1]);
            ans.push_back(tmp[i]);
            break;
        }
    }

    if(sz(ans) == 4) {
        for(auto it : ans) cout<<it<<" "; cout<<endl;
    } else {
        cout<<-1<<endl;
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