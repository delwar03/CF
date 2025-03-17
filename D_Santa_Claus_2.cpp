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
    int n, m, x, y; cin>>n>>m>>x>>y;
    vector<pii> h(n);
    for(auto &[a, b] : h) cin>>a>>b;
    map<int, vector<int>> mpX, mpY;
    for(auto [a, b] : h) {
        mpX[a].push_back(b);
        mpY[b].push_back(a);
    }

    for(auto &[a, b] : mpX) sort(b.begin(), b.end());
    for(auto &[a, b] : mpY) sort(b.begin(), b.end());

    map<int, pii> cntX, cntY;

    for(int i = 0; i < m; i++) {
        char ch; int c; cin>>ch>>c;
        if(ch == 'R') {
            if(mpY.count(y)) {
                int l = lower_bound(mpY[y].begin(), mpY[y].end(), x) - mpY[y].begin();
                int r = upper_bound(mpY[y].begin(), mpY[y].end(), x + c) - mpY[y].begin();
                if(cntY.count(y)) {
                    cntY[y].F = min(cntY[y].F, l);
                    cntY[y].S = max(cntY[y].S, r);
                } else {
                    cntY[y] = {l, r};
                }
            }
            x += c;
        } else if(ch == 'L') {
            if(mpY.count(y)) {
                int l = lower_bound(mpY[y].begin(), mpY[y].end(), x - c) - mpY[y].begin();
                int r = upper_bound(mpY[y].begin(), mpY[y].end(), x) - mpY[y].begin();
                if(cntY.count(y)) {
                    cntY[y].F = min(cntY[y].F, l);
                    cntY[y].S = max(cntY[y].S, r);
                } else {
                    cntY[y] = {l, r};
                }
            }
            x -= c;
        } else if(ch == 'U') {
            if(mpX.count(x)) {
                int l = lower_bound(mpX[x].begin(), mpX[x].end(), y) - mpX[x].begin();
                int r = upper_bound(mpX[x].begin(), mpX[x].end(), y + c) - mpX[x].begin();
                if(cntX.count(x)) {
                    cntX[x].F = min(cntX[x].F, l);
                    cntX[x].S = max(cntX[x].S, r);
                } else {
                    cntX[x] = {l, r};
                }
            }
            y += c;
        } else {
            if(mpX.count(x)) {
                int l = lower_bound(mpX[x].begin(), mpX[x].end(), y - c) - mpX[x].begin();
                int r = upper_bound(mpX[x].begin(), mpX[x].end(), y) - mpX[x].begin();
                if(cntX.count(x)) {
                    cntX[x].F = min(cntX[x].F, l);
                    cntX[x].S = max(cntX[x].S, r);
                } else {
                    cntX[x] = {l, r};
                }
            }
            y -= c;
        }
        // cerr<<"x: "<<x<<", y: "<<y<<endl;
    }

    int cnt = 0;

    for(auto [a, b] : cntX) {
        cnt += b.S - b.F;
    }
    for(auto [a, b] : cntY) {
        cnt += b.S - b.F;
    }

    assert(cnt % 2 == 0);

    cout<<x<<" "<<y<<" "<<cnt / 2<<endl;
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