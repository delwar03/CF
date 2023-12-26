#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> range(30), val(30), v;
    int cur = 0;
    for(int i = 1; i < n; i++) {
        int x; cin>>x;
        cur ^= x;
        v.push_back(x);

        for(int j = 30; j >= 0; j--) {
            if(cur & (1LL << j)) val[j]++;
            if(i & (1LL << j)) range[j]++;
        }
    }
    
    int ans = 0LL;
    for(int i = 0; i < 30; i++) {
        // if(range[i] == 0 && val[i] == 0) continue;
        if(range[i] != val[i]) ans |= (1LL << i);
    }
    cout<<ans<<" ";
    for(auto it : v) {ans ^= it; cout<<ans<<" ";}
    cout<<endl;
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