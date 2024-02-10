#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        mp[x]++;
    }
    priority_queue<pair<int, int>> pq;
    for(auto it : mp) {
        int x = it.first;
        int cnt = it.second;
        pq.push({cnt, x});
    }
    int ans = n;
    while(pq.size() >= 2) {
        auto it1 = pq.top();
        pq.pop();
        auto it2 = pq.top();
        pq.pop();
        int cnt1 = it1.first;
        int x1 = it1.second;
        int cnt2 = it2.first;
        int x2 = it2.second;
        cnt1--;
        cnt2--;
        ans -= 2;
        if(cnt1) pq.push({cnt1, x1});
        if(cnt2) pq.push({cnt2, x1});
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        // cout<<"Scenario #"<<c++<<":\n";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 