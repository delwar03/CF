#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

int binPow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, k, q; cin>>n>>k>>q;
    vector<int> v(200005, 0);
    for(int i = 0; i < n; i++) {
        int l, r; cin>>l>>r;
        v[l]++;
        v[r + 1]--;
    }
    for(int i = 1; i <= 200000; i++) v[i] += v[i - 1];
    // for(int i = 90; i <= 100; i++) cout<<v[i]<<" "; cout<<endl;
    vector<int> boro(200005, 0);
    int cnt = 1;
    for(int i = 1; i <= 200000; i++) {
        if(v[i] >= k) {
            boro[i] = boro[i - 1] + 1;
        } else {
            boro[i] = boro[i - 1];
        }
    }
    // for(int i = 90; i <= 100; i++) cout<<boro[i]<<" "; cout<<endl;
    while(q--) {
        int l, r; cin>>l>>r;
        cout<<boro[r] - boro[l - 1]<<endl;
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