#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    map<int, int> mp;
    vector<int> v(n, 0);
    mp[0] = n;

    for(int i = 0; i < k; i++) {
        int ind, val; cin>>ind>>val;
        ind--;
        if(--mp[v[ind]] == 0) mp.erase(v[ind]);
        v[ind] += val;
        mp[v[ind]]++;
        cout<<mp.size()<<endl;
    }
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