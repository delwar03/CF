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
    int n; cin>>n;
    int last = n % 10;
    int ans = 7;
    if(last >= 7) ans = min(ans, last - 7);
    else ans = min(ans, last + 3);
    // // cerr<<ans<<endl;
    // int tmp = n / 10;
    // while(tmp) {
    //     int cur = tmp % 10;
    //     if(cur <= 7) ans = min(ans, 7 - cur + (7 - cur >= last && last != 0));
    //     else ans = min(ans, 9 - cur + 1 + 7 + (9 - cur + 1 + 7 >= last && last != 0));
    //     tmp /= 10;
    // }

    auto f = [&] (int x) {
        while(x) {
            if(x % 10 == 7) return true;
            x /= 10;
        }
        return false;
    };

    int x = 9;

    for(int i = 0; i <= 12; i++) {
        int cnt = 0, tmp = n;
        for(int j = 0; j <= 12; j++) {
            if(f(tmp)) {
                ans = min(ans, cnt);
                // cerr<<tmp<<" "<<cnt<<endl;
                break;
            }
            tmp += x;
            cnt += 1;
        }
        x *= 10;
        x += 9;
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cerr<<12345678 + 9<<endl;
    // cerr<<12345678 + 99<<endl;
    // cerr<<12345678 + 999<<endl;
    // cerr<<12345678 + 9999<<endl;
    // cerr<<12345678 + 99999<<endl;
    // cerr<<12345678 + 999999<<endl;

    int x = 80;
    // cerr<<(x += 99)<<endl;
    // cerr<<(x += 99)<<endl;
    // cerr<<(x += 99)<<endl;
    // cerr<<(x += 99)<<endl;
    // cerr<<(x += 99)<<endl;
    // cerr<<(x += 99)<<endl;
    // cerr<<(x += 99)<<endl;

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}