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
    int n; cin>>n;
    vector<int> freq(n + 1);
    int mx = 0, ele = 0;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        freq[x]++;
        if(x && freq[x] > mx) {
            mx = freq[x];
            ele = x;
        }
    }
    int ans = 0;
    if(ele == 0) {
        ans += freq[0] * (freq[0] - 1) / 2;
    } else {
        freq[ele] += freq[0];
        for(int i = 1; i <= n; i++) {
            ans += freq[i] * (freq[i] - 1) / 2;
        }
    }
    cout<<ans<<endl;
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