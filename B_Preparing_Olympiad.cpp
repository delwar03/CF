#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, l, r, x; cin>>n>>l>>r>>x;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    int ans = 0, num = 1LL << n;
    for(int i = num - 1; i >= 0; i--) {
        multiset<int> st;
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if((i >> j) & 1) {st.insert(v[j]); sum += v[j];}
        }
        if(st.size() < 2) continue;
        auto it = st.end(); --it;
        int b = *st.begin();
        int e = *it;
        int dif = e - b;
        
        if(sum >= l && sum <= r && dif >= x) ans++;
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        // cout<<"Scenario #"<<c++<<":\n";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/