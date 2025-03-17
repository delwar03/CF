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
    if(n % 2 == 0) {cout<<-1<<endl; return; }
    vector<int> ans(n + 1);
    int l = 1, r = n, val = 1;
    while(l < r) {
        ans[l++] = val++;
        ans[r--] = val++;
    }
    ans[l] = n;
    for(int i = 1; i <= n; i++) cout<<ans[i]<<" \n"[i == n];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // vector<int> tmp(5);
    // iota(tmp.begin(), tmp.end(), 1LL);

    // do {
    //     for(auto it : tmp) cerr<<it<<" "; cerr<<endl;
    // } while(next_permutation(tmp.begin(), tmp.end()));

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