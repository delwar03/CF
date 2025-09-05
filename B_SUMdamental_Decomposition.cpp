#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int)x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n, x;
    cin >> n >> x;
    if (n == 1)
    {
        cout << (x == 0 ? -1 : x) << endl;
        return;
    }
    int ans = INF;
    if (n & 1)
    {
        if (x)
            ans = x + n - 1;
        int cur = n - 2, ct = __builtin_popcountll(x), m = min(n, ct);

        if (m == 0)
            cur = n + 3;
        else if (m == 1)
            cur += x + (x != 1 ? 2 : 4);
        else
        {
            cur = INF;
            x ^= 1;
            for (int i = 2; i <= min(n, (int)__builtin_popcountll(x)); i++)
            {
                cur = min(cur, n - i + x);
                x ^= 1;
            }
        }

        ans = min(ans, cur);
    }
    else
    {
        if (x ^ 1)
            ans = (x ^ 1) + n - 1;
        int cur = n - 2, ct = __builtin_popcountll(x), m = min(n, ct);

        if (m == 0)
            cur = n + 3;
        else if (m == 1)
            cur += x + (x != 1 ? 2 : 4);
        else
        {
            cur = INF;
            for (int i = 2; i <= min(n, (int)__builtin_popcountll(x)); i++)
            {
                cur = min(cur, n - i + x);
                x ^= 1;
            }
        }

        ans = min(ans, cur);
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1;
    cin >> t;
    while (t--)
    {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}