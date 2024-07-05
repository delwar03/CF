#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    int p = 0;
    priority_queue<int> pq;
    for(int i = 31; i >= 0; i--) {
        if((n >> i) & 1) {p++; pq.push(1LL << i);}
    }
    // cout<<p<<endl;
    if(k > n || k < p) {cout<<"NO"<<endl; return; }
    while(pq.size() != k) {
        int x = pq.top();
        pq.pop();
        pq.push(x / 2);
        pq.push(x / 2);
    }
    cout<<"YES"<<endl;
    while(!pq.empty()) {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 