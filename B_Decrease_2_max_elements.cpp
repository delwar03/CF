#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        pq.push(x);
    }

    int cnt = 0;

    while(pq.size() > 1) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        x--;
        y--;

        if(x) pq.push(x);
        if(y) pq.push(y);

        cnt++;
    }

    cout<<cnt<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/