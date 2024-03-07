#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n + 1), one_cnt(n + 1);
    int ind = 0;
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
        if(v[i] == 1) ind++;
        one_cnt[i] = ind;
    }
    for(int i = 1; i <= n; i++) v[i] += v[i - 1];
    
    while(q--) {
        int l, r; cin>>l>>r;
        int sum = v[r] - v[l - 1];
        int one = one_cnt[r] - one_cnt[l - 1];
        int non_one = sum - one;
        non_one -= (r - l + 1 - one);
        if((r - l + 1) == 1) cout<<"NO"<<endl;
        else {
            if(non_one >= one) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 