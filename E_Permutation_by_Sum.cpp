#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, l, r, s; cin>>n>>l>>r>>s;
    auto getMax = [&] (int n, int k) {
        if(k > n) return 0LL;
        return k * (2 * n + 1 - k) / 2;
    };
    auto getMin = [&] (int k) {
        if(k < 0) return INF;
        return k * (k + 1) / 2;
    };

    int k = r - l + 1;

    if(s < getMin(k) || s > getMax(n, k)) {cout<<-1<<endl; return; }
    
    vector<int> taken(n + 1, 0);
    for(int i = n; i >= 1; i--) {
        if(s <= getMax(i, k) && s - i >= getMin(k - 1)) {
            taken[i] = 1;
            s -= i;
            k--;
        }
    }
    // for(auto it : taken) cerr<<it<<" "; cerr<<endl;
    if(s) {
        cout<<"-1"<<endl;
    } else {
        vector<int> ans(n + 1);
        int idx = l;
        for(int i = 1; i <= n; i++) {
            if(taken[i]) {
                ans[idx++] = i;
            }
        }
        idx = 1;
        for(int i = 1; i <= n; i++) {
            if(!taken[i]) {
                if(idx == l) idx = r + 1;
                ans[idx++] = i;
            }
        }

        for(int i = 1; i <= n; i++) cout<<ans[i]<<" "; cout<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 
