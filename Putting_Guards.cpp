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

int Arr[30][30];

void solve() {
    int n, m; cin >> n >> m;
    memset(Arr, 0, sizeof Arr);
    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        for(int j = 1; j <= m; j++) {
            Arr[i][j] = s[j - 1] - '0';
        }
    }

    int cnt = 0;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            int cur = Arr[i][j] + Arr[i + 1][j] + Arr[i][j + 1] + Arr[i + 1][j + 1];

            if(cur == 1 || cur == 3 || (cur == 2 && Arr[i][j] && Arr[i + 1][j + 1]) || (cur == 2 && Arr[i][j + 1] && Arr[i + 1][j])) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ": ";
        solve();
    }
}