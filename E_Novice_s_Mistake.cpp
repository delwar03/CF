#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;

void solve() {
    int n; cin>>n;
    string s = to_string(n);
    int l = s.size();
    vector<vector<int>> ans;

    for(int a = 1; a <= 10000; a++) {
        int curLen = a * l;
        for(int j = 1; j <= min(7LL, curLen - 1); j++) {
            int b = curLen - j;
            string tmp = "";
            for(int k = 0; k < j; k++) tmp += s[k % l];
            if(a * n - b == stol(tmp)) {
                ans.push_back({a, b});
            }
        }
    }

    cout<<(int) ans.size()<<endl;
    for(auto it : ans) cout<<it[0]<<" "<<it[1]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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