#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;
vector<int> freq(N, 0);

void solve() {
    int n, k; cin>>n>>k;
    vector<string> v(n);
    for(auto &x : v) cin>>x;

    vector<int> now(k);
    for(int i = 0; i < k; i++) {
        now[i] = i;
    }

    int ans = INF;

    do {
        // cerr<<"now: ";
        // for(auto it : now) cerr<<it<<" "; cerr<<endl;
        int mn = INF;
        int mx = -INF;

        for(int i = 0; i < n; i++) {
            int num = 0;
            for(int j = 0; j < k; j++) {
                num *= 10;
                num += v[i][now[j]] - '0';
            }
            // cerr<<num<<endl;
            mn = min(mn, num);
            mx = max(mx, num);
        }

        ans = min(ans, mx - mn);
    } while(next_permutation(now.begin(), now.end()));

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 
