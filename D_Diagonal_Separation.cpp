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
    map<int, vector<pair<int, int>>> opX, opY;
    for(int i = 0; i < m; i++) {
        int x, y; char typ; cin>>x>>y>>typ;
        int f = (typ == 'W');
        opX[x].push_back({y, f});
        opY[y].push_back({x, f});
    }
    
    for(auto &[a, b] : opX) {
        sort(b.begin(), b.end());
    }
    for(auto &[a, b] : opY) {
        sort(b.begin(), b.end());
    }

    set<int> st;

    for(auto [x, vec] : opX) {
        for(auto [y, f] : vec) {
            if(f) {
                st.insert(y);
            } else {
                if(sz(st)) {
                    auto it = st.lower_bound(y);
                    if(it == st.begin() && *it > y) continue;
                    cout<<"No"<<endl; return;
                }
            }
        }
    }

    st.clear();

    for(auto [y, vec] : opY) {
        for(auto [x, f] : vec) {
            if(f) {
                st.insert(x);
            } else {
                if(sz(st)) {
                    auto it = st.lower_bound(x);
                    if(it == st.begin() && *it > x) continue;
                    cout<<"No"<<endl; return;
                }
            }
        }
    }

    cout<<"Yes"<<endl;


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