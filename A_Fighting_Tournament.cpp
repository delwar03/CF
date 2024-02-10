#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    vector<vector<int>> wins(n);
    int round = 0;
    deque<int> idx;
    for(int i = 0; i < n; i++) idx.push_back(i);
    
    while(v[idx.front()] != n) {
        int x = idx.front();
        idx.pop_front();
        int y = idx.front();
        idx.pop_front();
        if(v[x] < v[y]) swap(x, y);
        wins[x].push_back(round++);
        idx.push_front(x);
        idx.push_back(y);
    }

    while(q--) {
        int id, k; cin>>id>>k;
        id--;
        int ans = lower_bound(wins[id].begin(), wins[id].end(), k) - wins[id].begin();
        if(v[id] == n && k > round) ans += k - round;
        cout<<ans<<endl;
    }
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