#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    int sum = 0;
    set<int> st;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        st.insert(x);
        sum += x;
        if(i == 0 && x == 0) {
            cnt++;
        } else {
            if(sum % 2 == 0 && st.count(sum / 2)) {
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
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