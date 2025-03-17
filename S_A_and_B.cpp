#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int INF = 1e9 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int a, b; cin>>a>>b;
    int d = abs(a - b);

    if(!d) {
        cout<<0<<endl;
        return;
    }

    auto sum = [&] (int n) {
        return n * (n + 1) / 2;
    };

    if(d & 1) {

        auto get = [&] (int n) {
            int m = n;
            if(n % 2 == 0) m -= 1;
            int num = (m / 2) * 4 + 1;
            if(n % 2 == 0) num += 1;
            return num;
        };

        // for(int i = 1; i <= 10; i++) cerr<<i<<" -> "<<get(i)<<endl;

        int lo = 1, hi = INF, best = -1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(sum(get(mid)) >= d) {
                best = get(mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        cout<<best<<endl;
    } else {
        auto get = [&] (int n) {
            int m = n;
            if(n % 2 == 0) m -= 1;
            int num = (m / 2) * 4 + 3;
            if(n % 2 == 0) num += 1;
            return num;
        };

        // for(int i = 1; i <= 10; i++) cerr<<i<<" -> "<<get(i)<<endl;

        int lo = 1, hi = INF, best = -1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(sum(get(mid)) >= d) {
                best = get(mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        cout<<best<<endl;
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