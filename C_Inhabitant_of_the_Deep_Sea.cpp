#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    int i = 0, j = n - 1;
    int ans = 0;
    while(i < j) {
        if(v[i] < v[j]) {
            if(k == 2 * v[i] - 1) {v[i] = 0; break; }
            if(k < 2 * v[i]) break;
            k -= 2 * v[i];
            v[j] -= v[i];
            v[i] = 0;
            i++;
        } else if(v[i] > v[j]) {
            if(k < 2 * v[j]) break;
            k -= 2 * v[j];
            v[i] -= v[j];
            v[j] = 0;
            j--;
        } else {
            if(k == 2 * v[i] - 1) {v[i] = 0; break; }
            if(k < 2 * v[i]) break;
            k -= 2 * v[i];
            v[i] = 0;
            v[j] = 0;
            i++;
            j--;
        }
    }

    if(i == j) {
        if(v[i] <= k) v[i] = 0;
    }
    
    for(int i = 0; i < n; i++) {
        if(v[i] == 0) ans++;
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": \n";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 