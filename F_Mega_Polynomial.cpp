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
    int A, B, C, D, n; cin>>A>>B>>C>>D>>n;

    auto get = [&] (int n, int i) {
        int cnt = 0;
        while(n) {
            cnt += n / i;
            n /= i;
        }
        return cnt;
    };

    int k = n * (A * D - B * C);

    if(k % (A * D) == 0) {
        k /= (A * D);
        if(k < 0) {cout<<n + 1<<endl; return; }
        int tmp = A /= __gcd(A, C), f = 1;
        for(int i = 2; i * i <= tmp; i++) {
            if(tmp % i == 0) {
                int ct = 0;
                while(tmp % i == 0) tmp /= i, ct++;
                if(get(n, i) - get(n - k, i) < ct) {f = 0; break;}
            }
        }
        if(tmp > 1 && get(n, tmp) - get(n - k, tmp) < 1) f = 0;
        cout<<(f ? k : n + 1)<<endl;
    } else {
        cout<<n + 1<<endl;
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