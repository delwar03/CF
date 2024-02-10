#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

vector<int> getFactors(int n) {
    vector<int> v;
    v.push_back(1);
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            v.push_back(i);
            if(i != n / i) v.push_back(n / i);
        }
    }
    if(n != 1) v.push_back(n);
    return v;
}

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    int ans = INF;
    for(int i = 0; i < n; i++) {
        vector<int> f(3, 0);
        f[s[i] - 'a']++;
        for(int j = i + 1; j < min(n, i + 7); j++) {
            f[s[j] - 'a']++;
            if(f[0] > f[1] && f[0] > f[2]) ans = min(ans, j - i + 1);
        }
    }
    if(ans == INF) ans = -1;
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