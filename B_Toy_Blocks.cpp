#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int sum = 0;
    for(auto &x : v) {cin>>x; sum += x;}
    sort(v.begin(), v.end());
    int  val = (sum + n - 2) / (n - 1);
    int p = val * (n - 1);
    // cout<<val<<" "<<p<<endl;
    if(v[n - 1] > val) p = (n - 1) * v[n - 1];
    cout<<p - sum<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 