#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int arr[N], pf[N];

void solve() {
    int l, r; cin>>l>>r;
    int ans = pf[r] - pf[l - 1] + arr[l];

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i < N; i++) arr[i] = 1 + arr[i / 3];
    for(int i = 1; i < N; i++) pf[i] = pf[i - 1] + arr[i];

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