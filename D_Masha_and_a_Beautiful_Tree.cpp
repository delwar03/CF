#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
int n, ans = 0;
vector<int> v(N);

void calc(int l, int r) {
    if(l == r) return;

    int mid = (l + r) / 2;
    int mxL = 0, mnR = INF;
    for(int i = l; i <= mid; i++) {
        mxL = max(mxL, v[i]);
        mnR = min(mnR, v[mid + 1 + i - l]);
    }

    if(mxL > mnR) {
        for(int i = l; i <= mid; i++) {
            swap(v[i], v[mid + 1 + i - l]);
        }
        ans++;
    }
    calc(l, mid);
    calc(mid + 1, r);
}

void solve() {
    cin>>n;
    v.resize(n);
    ans = 0;
    for(auto &x : v) cin>>x;
    calc(0, n - 1);
    for(int i = 0; i < n; i++) {
        if(v[i] != i + 1) {
            cout<<"-1\n";
            return;
        }
        // cerr<<v[i]<<" ";
    }
    cout<<ans<<endl;
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