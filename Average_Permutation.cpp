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
    int n; cin>>n;
    if(n == 3) {
        cout<<"2 1 3"<<endl;
    } else {
        vector<int> ans(n);
        ans[n - 1] = n;
        ans[0] = n - 1;
        ans[n - 2] = n - 2;
        ans[1] = n - 3;
        int val = 1;
        for(int i = 2; i < n - 2; i++) {
            ans[i] = val++;
        }
        for(auto it : ans) cout<<it<<" "; cout<<endl;
    }
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