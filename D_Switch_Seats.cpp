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

int get(int l, int r) {
    return l + rng() % (r - l + 1);
}

void solve() {
    
    while(0) {
        int n = get(2, 10);
        vector<int> v(2 * n), vis(2 * n);
        for(int i = 1; i <= n; i++) {
            int j = rng() % (2 * n);
            while(vis[j]) j = rng() % (2 * n);
            v[j] = i;
            vis[j] = 1;
            while(vis[j]) j = rng() % (2 * n);
            v[j] = i;
            vis[j] = 1;
        }

        auto brute = [&] () {
            vector<int> pos[n + 1];
            for(int i = 0; i < 2 * n; i++) {
                pos[v[i]].push_back(i);
            }
            int cnt = 0;
            for(int i = 1; i <= n; i++) {
                for(int j = i + 1; j <= n; j++) {
                    if(abs(pos[i][0] - pos[i][1]) <= 1 || abs(pos[j][0] - pos[j][1]) <= 1) continue;
                    if(abs(pos[i][0] - pos[j][0]) <= 1 && abs(pos[i][1] - pos[j][1]) <= 1) cnt++;
                }
            }

            return cnt;
        };

        auto my = [&] () {
            vector<int> pos[n + 1];
            for(int i = 0; i < 2 * n; i++) {
                pos[v[i]].push_back(i);
            }

            int cnt = 0;
            for(int i = 0; i < 2 * n; i++) {
                if(i == pos[v[i]].back()) continue;
                if(v[i] == v[i + 1]) continue;
                if(abs(pos[v[i]][0] - pos[v[i]][1]) == 1 || abs(pos[v[i + 1]][0] - pos[v[i + 1]][1]) == 1) continue;

                // if((pos[v[i]].back() + 1 < 2 * n && v[i + 1] == v[pos[v[i]].back() + 1]) || (i + 1 != pos[v[i]].back() - 1 && v[i + 1] == v[pos[v[i]].back() - 1])) {
                //     cnt += 1;
                // }
                if(abs(pos[v[i]][1] - pos[v[i + 1]][1]) == 1) cnt++;

                // cerr << v[i] << " " << pos[v[i]].back() << " " << cnt << endl;
            }
            return cnt;
        };

        int x1 = my(), x2 = brute();
        if(x1 ^ x2) {
            cerr << x1 << " != " << x2 << endl;
            cerr << n << endl;
            for(auto i : v) cerr << i << " "; cerr << endl;
            return;
        }
    }

    int n; cin >> n;
    vector<int> v(2 * n), pos[n + 1];
    for(int i = 0; i < 2 * n; i++) {
        cin >> v[i];
        pos[v[i]].push_back(i);
    }

    int cnt = 0;
    for(int i = 0; i + 1 < 2 * n; i++) {
        if(i == pos[v[i]].back()) continue;
        if(i + 1 == pos[v[i + 1]].back()) continue;
        if(v[i] == v[i + 1]) continue;
        if(abs(pos[v[i]][0] - pos[v[i]][1]) == 1 || abs(pos[v[i + 1]][0] - pos[v[i + 1]][1]) == 1) continue;

        if(abs(pos[v[i]][1] - pos[v[i + 1]][1]) == 1) cnt++;
        
        // cerr << v[i] << " " << pos[v[i]].back() << " " << cnt << endl;
    }

    cout << cnt << endl;
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