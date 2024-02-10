#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;


void solve() {
    int n, m; cin>>n>>m;
    vector<int> a(n), b(m);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(a[i] < b[j]) i++;
        else j++;
    }
    if(i == n && j == m) cout<<"uncertain"<<endl;
    else if(i == n) cout<<"MechaGodzilla"<<endl;
    else cout<<"Godzilla"<<endl;
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