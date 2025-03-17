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

int dp[85][85][10005]; // {ind, cnt, sum}

void solve() {
    int n, x, y; cin>>n>>x>>y;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin>>a[i]>>b[i];

    function<int(int, int, int)> magic = [&] (int ind, int cnt, int swt) {
        if(ind == n) return (cnt == 0 ? 0LL : INF);

        int &ans = dp[ind][cnt][swt];
        if(~ans) return ans;

        ans = INF;

        ans = min(ans, magic(ind + 1, cnt, swt));
        
        if(swt - a[ind] >= 0) 
            ans = min(ans, b[ind] + magic(ind + 1, cnt - 1, swt - a[ind]));

        return ans;
    };

    int ans = 0;
    memset(dp, -1, sizeof dp);

    for(int i = n; i >= 0; i--) {
        if(magic(0, i, x) <= y) {
            ans = i;
            break;
        }
    }

    if(ans < n) ans++;

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