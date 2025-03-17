#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> ans;
    ans.push_back(n);

    for(int i = 63; i >= 0; i--) {
        if((n >> i) & 1) {
            if(n ^ (1LL << i)) {
                ans.push_back(n ^ (1LL << i));
            }
        }
    }


    sort(ans.begin(), ans.end());
    cout<<(int) ans.size()<<endl;
    for(auto it : ans) cout<<it<<" "; cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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