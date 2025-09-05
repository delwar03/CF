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
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> di[N];

int a[N], f[N];
array<int, 2> suf[N];
bool p[N];

void solve() {

    auto get = [&] (int l, int r) {
        return l + rng() % (r - l + 1);
    };


    while(0) {

        int n = get(2, 10000);
        vector<int> v(n);
        for(auto &x : v) x = get(1, 10000);
 
        auto him = [&] () {
            for (int i = 1; i <= n; i++) {
                int x = v[i - 1];
                a[x]++;
            }
            memset(p, true, sizeof p);
            vector<int> ex;
            for (int i = 2; i < N; i++) {
                f[i] = a[i];
                for (int j = i + i; j < N; j += i) {
                    f[i] += a[j];
                    p[j] = false;
                }
                if (p[i]) {
                    ex.push_back(i);
                }
            }
            int sz = ex.size();
            suf[sz] = {0, N};
            for (int i = sz - 1; i >= 0; i--) {
                suf[i] = max(suf[i + 1], {f[v[i]], v[i]});
            }
            array<int, 3> ans = {0, N, N + 1};
            for (int i = 0; i < sz; i++) {
                for (int j = i + 1; j < sz; j++) {
                    if (1LL * ex[i] * ex[j] >= N) {
                        ans = max(ans, {f[ex[i]] + suf[j][0], ex[i], suf[j][1]});
                        break;
                    }
                    int cur = f[ex[i]] + f[ex[j]] - f[ex[i] * ex[j]];
                    ans = max(ans, {cur, ex[i], ex[j]});
                }
            }
            return n - ans[0];
            // cout << n - ans[0] << '\n' << ans[1] << ' ' << ans[2] << '\n';
        };

        auto my = [&] () {

            // int n; cin >> n;
            // vector<int> v(n);
            int mx = 0;
            for(auto &x : v) mx = max(mx, x);

            vector<int> cnt(mx + 1);
            for(int x : v) {
                for(int j : di[x]) cnt[j] += 1;
            }

            vector<int> ans;

            int mxCt = 0, mxId = 2, cur = 0;
            for(int i = 2; i <= mx; i++) if(cnt[i] > mxCt) mxCt = cnt[i], mxId = i;
            cur = mxCt;
            ans.push_back(mxId);
            for(int x : v) if(x % mxId == 0) {
                for(int j : di[x]) cnt[j] -= 1;
            }

            mxCt = 0, mxId = 3;
            for(int i = 2; i <= mx; i++) if(cnt[i] > mxCt) mxCt = cnt[i], mxId = i;
            cur += mxCt;
            ans.push_back(mxId);

            return n - cur;

            // cout << n - cur << endl;
            // cout << ans[0] << " " << ans[1] << endl;
        };

        int x1 = my(), x2 = him();

        if(x1 ^ x2) {
            cerr << "my: " << x1 << ", him: " << x2 << endl; 
            cerr << n << endl;
            for(int x : v) cerr << x << " "; cerr << endl;
            return;
        }
    }


    int n; cin >> n;
    vector<int> v(n);
    int mx = 0;
    for(auto &x : v) cin >> x, mx = max(mx, x);

    vector<int> cnt(mx + 1);
    for(int x : v) {
        for(int j : di[x]) cnt[j] += 1;
    }

    vector<int> ans;

    int mxCt = 0, mxId = 2, cur = 0;
    for(int i = 2; i <= mx; i++) if(cnt[i] > mxCt) mxCt = cnt[i], mxId = i;
    cur = mxCt;
    ans.push_back(mxId);
    for(int x : v) if(x % mxId == 0) {
        for(int j : di[x]) cnt[j] -= 1;
    }

    mxCt = 0, mxId = 2;
    for(int i = 2; i <= mx; i++) if(cnt[i] > mxCt) mxCt = cnt[i], mxId = i;
    cur += mxCt;
    ans.push_back(mxId);

    cout << n - cur << endl;
    cout << ans[0] << " " << ans[1] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 2; i < N; i++) {
        if(sz(di[i])) continue;
        for(int j = i; j < N; j += i) {
            di[j].push_back(i);
        }
    }

    // for(int i = 0; i <= 100; i++) {
    //     cerr << i << " -> ";
    //     for(int j : di[i]) cerr << j << " "; cerr << endl;
    // }

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}