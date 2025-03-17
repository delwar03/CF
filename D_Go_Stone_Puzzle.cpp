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
    string s, t; cin>>s>>t;
    s += "..";
    t += "..";
    priority_queue<pair<pair<int, int>, string>> pq;
    pq.push({{0, n}, s});

    map<string, int> dp;

    while(pq.size()) {
        auto it = pq.top(); pq.pop();
        string cur = it.ss;
        int cost = it.ff.ff, pos = it.ff.ss;

        if(dp.count(cur)) continue;

        dp[cur] = -cost;

        for(int j = 0; j <= n; j++) {
            if(j == pos || j == pos + 1 || j == pos - 1) continue;
            string now = cur;
            swap(now[j], now[pos]);
            swap(now[j + 1], now[pos + 1]);
            pq.push({{cost - 1, j}, now});
        }
    }

    cout<<(dp.count(t) ? dp[t] : -1)<<endl;
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