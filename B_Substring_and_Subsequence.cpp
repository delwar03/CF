#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int prm = 31;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    string a, b; cin>>a>>b;
    int n = a.size(), m = b.size();
    int cnt = 0;

    for(int i = 0; i < m; i++) {
        int ind = i;
        for(int j = 0; j < n; j++) {
            if(ind < m && b[ind] == a[j]) ind++;
        }
        cnt = max(cnt, ind - i);
    }
    cout<<n + m - cnt<<endl;
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