#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k, pb, ps; cin>>n>>k>>pb>>ps;
    vector<int> p(n), a(n);
    for(auto &x : p) cin>>x;
    for(auto &x : a) cin>>x;

    int score_b = 0, score_s = 0;
    vector<int> vis(n + 1, 0);
    int ind = k;
    int pos = pb;
    int score = 0;

    while(ind--) {
        score += a[pos - 1];
        score_b = max(score_b, score + a[pos - 1] * ind);
        if(vis[pos]) break;
        vis[pos] = 1;
        pos = p[pos - 1];
    }

    vis.assign(n + 1, 0);
    ind = k;
    pos = ps;
    score = 0;
    
    while(ind--) {
        score += a[pos - 1];
        score_s = max(score_s, score + a[pos - 1] * ind);
        if(vis[pos]) break;
        vis[pos] = 1;
        pos = p[pos - 1];
    }

    // cerr<<score_b<<" "<<score_s<<endl;

    if(score_b > score_s) {
        cout<<"Bodya"<<endl;
    } else if(score_s > score_b) {
        cout<<"Sasha"<<endl;
    } else {
        cout<<"Draw"<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 
