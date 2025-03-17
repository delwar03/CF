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
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    
    priority_queue<vector<int>> pq;

    for(int i = 0; i < n; i++) {
        pq.push({a[i] + b[i], a[i], b[i]});
    }

    int p1 = 0, p2 = 0, f = 1;

    while(pq.size()) {
        auto vec = pq.top();
        pq.pop();
        if(f) {
            p1 += vec[1];
        } else {
            p2 += vec[2];
        }
        f ^= 1;
    }

    if(p1 == p2) {
        cout<<"Tie"<<endl;
    } else {
        cout<<(p1 > p2 ? "First" : "Second")<<endl;
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