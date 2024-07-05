#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int INF = 1e15 + 10;
const int N = 3e5 + 10;

set<int> st;

int getMaxFactor(int n) {
    int mx = 1;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            mx = max(mx, i);
            mx = max(mx, n / i);
        }
    }
    return mx;
}

void solve() {
    int n; cin>>n;
    if(st.count(n)) {
        cout<<getMaxFactor(n)<<endl;
    } else {
        int ans = 1;
        while(ans <= n) {
            ans *= 2;
        }
        cout<<ans - 1<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 2; i <= 25; i++) {
        st.insert((1LL << i) - 1);
    }

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