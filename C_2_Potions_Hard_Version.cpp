#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        pq.push(x);
        sum += x;
        if(sum < 0) {
            sum -= pq.top();
            pq.pop();
        }
    }
    cout<<(int) pq.size()<<endl;
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