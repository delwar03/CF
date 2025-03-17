#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

int cnt[30][2];

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int ans = 0, sum = 0;
    for(auto &x : v) cin>>x, sum += x;

    vector<int> pf(n + 1);
    for(int i = 0; i < n; i++) {
        pf[i + 1] = pf[i] ^ v[i];
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < 30; j++) {
            if((pf[i] >> j) & 1) {
                cnt[j][1]++;
            } else {
                cnt[j][0]++;
            }
        }
    }

    for(int j = 0; j < 30; j++) {
        ans += cnt[j][0] * cnt[j][1] * (1LL << j);
    }

    cout<<ans - sum<<endl;
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