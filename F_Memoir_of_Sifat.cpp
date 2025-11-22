#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
// #define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string ask(const string &s) {
    cout << s << endl;
    string res; cin >> res;
    return res;
}

void solve() {
    int n; cin >> n;
    string s;
    int lo = 1, hi = n, best = -1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        s = string(mid, '1');
        if(ask(s) == "No") {
            hi = mid - 1;
        } else {
            best = mid;
            lo = mid + 1;
        }
    }

    if(best == -1) {cout << string(n, '0') << endl; return;}

    s = string(best, '1');

    if(sz(s) == n) {
        cout << s << endl;
        return;
    }

    int m = best, f = 0;

    for(int i = 1; i <= m; i++) {
        if(f) break;
        int j = 0, cnt = 0;
        while(j < n && cnt + (s[j] == '1') < i) j++, cnt += (s[j] == '1');
        if(j) j++;
        while(1) {
            s.insert(s.begin() + j, '0');
            string x = ask(s);
            if(x != "Yes") {
                if(x == "Correct") {
                    f = 1;
                    break;
                }
                s.erase(s.begin() + j);
                break;
            }
        }
    }

    while(sz(s) < n) s.push_back('0');

    cout << s << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}