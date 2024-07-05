#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;
vector<int> freq(N, 0);

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    freq.assign(n + 1, 0);
    int mxElement = -1;
    for(auto &x : v) {
        cin>>x;
        mxElement = max(mxElement, x);
        freq[x]++;
    }
    
    // cerr<<mxElement<<endl;
    // for(auto it : freq) cerr<<it<<" "; cerr<<endl;

    for(int i = 2; i <= mxElement; i++) {
        if(freq[i] > freq[i - 1]) {
            cout<<-1<<endl;
            return;
        }
    }

    vector<int> ans(n);
    int mx = 1;
    for(int i = 0; i < n; i++) {
        mx = max(mx, freq[v[i]]);
        ans[i] = freq[v[i]]--;
    }

    cout<<mx<<endl;
    for(auto it : ans) cout<<it<<" "; cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 
