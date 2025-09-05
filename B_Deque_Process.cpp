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
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    deque<int> dq(v.begin(), v.end());
    vector<int> cur = {dq[0]};
    dq.pop_front();
    string ans = "L";
    int cnt = 0, f = 1, p = 0;
    while(sz(dq)) {
        if(sz(dq) > 1) {
            if((dq.front() > cur.back()) != (dq.back() > cur.back())) {
                cur.push_back(dq.front());
                dq.pop_front();
                cur.push_back(dq.back());
                dq.pop_back();
                ans += "LR";
            } else {
                if((dq.front() > cur.back()) && (dq.back() > cur.back())) {
                    if(dq.front() > dq.back()) {
                        cur.push_back(dq.front());
                        dq.pop_front();
                        cur.push_back(dq.back());
                        dq.pop_back();
                        ans += "LR";
                    } else {
                        cur.push_back(dq.back());
                        dq.pop_back();
                        cur.push_back(dq.front());
                        dq.pop_front();
                        ans += "RL";
                    }
                } else {
                    if(dq.front() < dq.back()) {
                        cur.push_back(dq.front());
                        dq.pop_front();
                        cur.push_back(dq.back());
                        dq.pop_back();
                        ans += "LR";
                    } else {
                        cur.push_back(dq.back());
                        dq.pop_back();
                        cur.push_back(dq.front());
                        dq.pop_front();
                        ans += "RL";
                    }
                }
            }
        } else {
            cur.push_back(dq.front());
            dq.pop_front();
            ans += "L";
        }
    }

    cout << ans << endl;
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