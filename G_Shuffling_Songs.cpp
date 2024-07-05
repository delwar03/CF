#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 16;

int n;
int dp[N][1 << N];
int a[16], b[16];

int calc(int i, int mask) {

    int &ans = dp[i][mask];
    if(~ans) return ans;

    ans = 0;

    for(int j = 0; j < n; j++) {
        if(mask & (1 << j))
            if(a[i] == a[j] || b[i] == b[j])
                ans = max(ans, 1 + calc(j, mask ^ (1 << j)));
    }

    return ans;
}

void solve() {
    cin>>n;
    memset(dp, -1, sizeof dp);
    int cnt = 0;
    map<string, int> mp;
    for(int i = 0; i < n; i++) {
        string g, w; cin>>g>>w;
        if(mp[g] == 0) mp[g] = ++cnt;
        if(mp[w] == 0) mp[w] = ++cnt;

        a[i] = mp[g]; b[i] = mp[w];
    }

    int mx = 0;
    int mask = (1 << n) - 1;

    for(int i = 0; i < n; i++) {
        mx = max(mx, 1 + calc(i, mask ^ (1 << i)));
    }

    cout<<n - mx<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 