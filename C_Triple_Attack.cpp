#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    int ans = 0;

    auto f = [&] (int m, int x) {
        int cost = m;
        int cnt = 0, tmp = ans + 1;
        while(tmp % 3 != 0 && tmp < ans + m) tmp++;
        cnt = (tmp % 3 == 0);
        cnt += (ans + m - tmp) / 3;
        cost += 2 * cnt;
        return cost >= x;
    };

    for(int i = 0; i < n; i++) {
        int l = 1, r = INF, best = 1;

        while(l <= r) {
            int mid = (l + r) >> 1;
            if(f(mid, v[i])) {
                best = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        // cerr<<"best: "<<best<<endl;

        ans += best;
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/