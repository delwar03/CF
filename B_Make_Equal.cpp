#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int sum = 0;
    for(auto &x : v) {cin>>x; sum += x;}
    int p = sum / n;
    int baki = 0;
    // cout<<"P: "<<p<<endl;
    for(int i = 0; i < n; i++) {
        if(v[i] < p) {
            if(baki >= (p - v[i])) {
                baki -= (p - v[i]);
                v[i] += (p - v[i]);
            } else {
                cout<<"NO"<<endl;
                return;
            }
        } else {
            baki += v[i] - p;
        }
    }
    cout<<"YES"<<endl;
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