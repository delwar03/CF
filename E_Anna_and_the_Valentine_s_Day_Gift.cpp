#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;

void solve() {
    int n, m; cin>>n>>m;
    priority_queue<int> pq;
    int tot = 0;
    for(int i = 0; i < n; i++) {
        string s; cin>>s;
        tot += (int) s.size();
        int cnt = 0;
        while(s.back() == '0') cnt++, s.pop_back();
        pq.push(cnt);
    }
    int i = 1;
    while(pq.size()) {
        if(i++ & 1) tot -= pq.top();
        pq.pop();
    }
    if(tot > m) cout<<"Sasha"<<endl;
    else cout<<"Anna"<<endl;
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