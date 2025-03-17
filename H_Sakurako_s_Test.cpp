#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    int m = n / 2;
    m++;

    vector<int> dp(n + 1, -1), freq(n + 1, 0);
    for(auto it : v) freq[it]++;
    for(int i = 1; i <= n; i++) freq[i] += freq[i - 1];

    auto f = [&] (int mid, int x) {
        int cnt = 0;
        for(int i = 0; i <= n; i += x) {
            cnt += freq[min(n, i + mid)];
            cnt -= freq[max(0LL, i - 1)];
        }
        return cnt;
    };

    while(q--) {
        int x; cin>>x;
        if(~dp[x]) {
            cout<<dp[x]<<endl;
        } else {
            int l = 0, r = x - 1, best = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(f(mid, x) >= m) {
                    best = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            dp[x] = best;
            cout<<best<<" ";
        }
    } cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/