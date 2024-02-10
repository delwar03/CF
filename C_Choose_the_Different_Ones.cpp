#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, m, k; cin>>n>>m>>k;
    set<int> s1, s2;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        s1.insert(x);
    }
    for(int i = 0; i < m; i++) {
        int x; cin>>x;
        s2.insert(x);
    }
    int e1 = 0, e2 = 0, d = 0;
    for(int i = 1; i <= k; i++) {
        if(s1.count(i) && s2.count(i)) d++;
        else if(s1.count(i)) e1++;
        else if(s2.count(i)) e2++;
        else {
            cout<<"NO"<<endl;
            return;
        }
    }
    assert(e1 + e2 + d == k);
    if(k / 2 - e1 <= d && k / 2 - e2 <= d) cout<<"YES\n";
    else cout<<"NO\n";
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