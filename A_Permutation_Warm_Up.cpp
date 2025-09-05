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
    int n;
    cin >> n;
    int ans = 0;
    for (int i = n; i >= 1; i--)
        ans += abs(i - (n - i + 1));
    cout << ans / 2 + 1 << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sz = 7;
    vector<int> tmp(sz);
    iota(tmp.begin(), tmp.end(), 1LL);

    set<int> st;
    int mx = 0;

    // do
    // {
    //     int cur = 0;
    //     for (int i = 0; i < sz; i++)
    //         cur += abs(tmp[i] - i - 1);
    //     st.insert(cur);
    //     mx = max(mx, cur);
    // } while (next_permutation(tmp.begin(), tmp.end()));

    // cerr << sz(st) << " " << mx << endl;

    int t = 1, c = 1;
    cin >> t;
    while (t--)
    {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}