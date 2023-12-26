#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;
int n, k;
vector<int> v;

int hobe(int x) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] <= x) cnt++;
    }
    return cnt;
}

void solve() {
    cin>>n>>k;
    v.resize(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    sort(v.begin(), v.end());
    if(k == 0) {
        if(v[0] == 1) cout<<"-1\n";
        else cout<<"1\n";
    } else {
        if(v[k] == v[k - 1]) cout<<"-1\n";
        else cout<<v[k - 1]<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 