#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, k; cin>>n>>k;
    string s; cin>>s;
    vector<int> l(k), r(k);
    for(auto &x : l) {cin>>x; --x;}
    for(auto &x : r) {cin>>x; --x;}

    int q; cin>>q;
    vector<int> query(n);
    for(int i = 0; i < q; i++) {
        int x; cin>>x; --x;
        query[x]++;
    }

    for(int i = 0; i < k; i++) {
        int sum = 0;
        for(int j = l[i]; j <= (l[i] + r[i]) / 2; j++) {
            sum += query[j] + query[l[i] + r[i] - j];
            if(sum & 1) {
                swap(s[j], s[r[i] + l[i] - j]);
            }
        }
    }
    cout<<s<<endl;
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