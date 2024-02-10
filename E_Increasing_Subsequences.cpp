#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;


void solve() {
    int n; cin>>n;
    int m = n;
    bool hobe = true;
    vector<int> ans;
    for(int i = 63; i >= 0; i--) {
        if(m & (1LL << i)) {
            if(hobe) {
                hobe = false;
                for(int j = 1; j <= i; j++) ans.push_back(j);
            } else {
                ans.push_back(i + 1);
            }
        }
    }
    // cout<<"Bin: ";
    // for(int i = 64; i >= 0; i--) {
    //     if(n & (1LL << i)) cout<<1;
    //     else cout<<0;
    // } cout<<endl;

    if(ans.size() > 200) cout<<"-1\n";
    else {
        cout<<ans.size()<<endl;
        for(auto it : ans) cout<<it<<" "; cout<<endl;
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