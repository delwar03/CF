#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k; cin>>n>>k;
    deque<int> dq;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        dq.push_back(x);
    }
    for(int i = 0; i < k; i++) {
        int x = dq.front(); dq.pop_front();
        int y = dq.back(); dq.pop_back();
        dq.push_back(x + y);
    }

    while(dq.size()) {
        cout<<dq.front()<<" ";
        dq.pop_front();
    } cout<<endl;
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