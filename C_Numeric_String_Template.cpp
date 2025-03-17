#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    int m; cin>>m;
    while(m--) {
        string s; cin>>s;
        int l = s.size();
        if(l != n) {cout<<"NO"<<endl; continue;}
        map<int, char> mp1;
        map<char, int> mp2;

        int f = 1;

        for(int i = 0; i < n; i++) {
            if((mp1.count(v[i]) && mp1[v[i]] != s[i]) || (mp2.count(s[i]) && mp2[s[i]] != v[i])) {
                f = 0;
                break;
            }
            mp1[v[i]] = s[i];
            mp2[s[i]] = v[i];
        }

        cout<<(f ? "YES" : "NO")<<endl;
    }
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